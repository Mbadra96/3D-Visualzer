#shader vertex

#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
out vec3 Normal;
out vec3 FragPos;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
    gl_Position = u_Projection * u_View * u_Model * vec4(position, 1.0f);
    FragPos = vec3(u_Model * vec4(position, 1.0f));
    Normal = mat3(transpose(inverse(u_Model))) * normal;
}

#shader fragment

#version 330 core

struct Light
{
    vec3 direction;
    vec3 diffuse;
    vec3 ambient;
    vec3 specular;

};

out vec4 color;

in vec3 FragPos;
in vec3 Normal;

uniform vec3 viewPos;
uniform Light light;
uniform vec4 ObjectColor;
void main()
{
    // Ambient
    vec3 ambient = light.ambient;

    // Diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff;

    // Specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16.0);
    vec3 specular = light.specular * spec;

    color = vec4(ambient + diffuse + specular, 1.0) * ObjectColor;
}