#pragma once
#include <GL/glew.h>
#include<string>
#include<unordered_map>
#include "glm/glm.hpp"
struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const std::string& filePath);
	~Shader();
	void Bind()const;
	void UnBind()const;

	//Uniforms
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setUniform1f(const std::string& name, float value);
	void setUniform1i(const std::string& name,int value);
	void setUniformMat4f(const std::string& name, const glm::mat4& matrix);
	void setUniformVec3f(const std::string& name, const glm::vec3& vector);
	

private: 
	unsigned int CompileShader(unsigned int type, const std::string& source);
	int CreateShader(std::string& vertexShader, std::string& fragmentShader);
	ShaderProgramSource ParseShaders(const std::string& filePath);
	int getUniformLocation(const std::string& name);

};