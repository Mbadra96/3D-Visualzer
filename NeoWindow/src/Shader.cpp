#include "Shader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



ShaderProgramSource Shader::ParseShaders(const std::string& filePath)
{
    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::ifstream stream(filePath);

    std::string line;

    std::stringstream ss[2];

    ShaderType type = ShaderType::NONE;
    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                type = ShaderType::FRAGMENT;
            }
        }
        else
        {
            ss[(int)type] << line << "\n";
        }
    }
    return { ss[0].str(),ss[1].str() };
}



unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    //ERROR Handling
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(sizeof(char) * length);
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "FAILED TO COMIPLE" << (type == GL_VERTEX_SHADER ? " vertex" : " fragment ") << " SHADER" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }
    return id;
}


int Shader::CreateShader(std::string& vertexShader, std::string& fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
    //Attach
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    //Link and Validate
    glLinkProgram(program);
    glValidateProgram(program);
    // Delete OBJ files
    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}






Shader::Shader(const std::string& filePath)
	:m_FilePath(filePath),m_RendererID(0)
{
    ShaderProgramSource source = ParseShaders(m_FilePath);
    m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);

}

Shader::~Shader()
{
    glDeleteProgram(m_RendererID);
}

void Shader::Bind() const
{
    glUseProgram(m_RendererID);
}

void Shader::UnBind() const
{
    glUseProgram(0);
}

void Shader::setUniform1f(const std::string& name, float value)
{
    glUniform1f(getUniformLocation(name), value);
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
    glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
}
void Shader::setUniform1i(const std::string& name, int value)
{
    glUniform1i(getUniformLocation(name),value);
}

void Shader::setUniformMat4f(const std::string& name, const glm::mat4& matrix)
{
    glUniformMatrix4fv(getUniformLocation(name),1,GL_FALSE,&matrix[0][0]);
}

void Shader::setUniformVec3f(const std::string& name, const glm::vec3& vector)
{
    
    glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
}


int Shader::getUniformLocation(const std::string& name)
{
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
    {
        return m_UniformLocationCache[name];
    }
	int location =  glGetUniformLocation(m_RendererID, name.c_str());
    if (location == -1)
    {
        std::cout <<"Warning Uniform: "<<name<< " doesn't exist !! "<<std::endl;
    }
    else
    {
        m_UniformLocationCache[name] = location;
    }

    return location;
}