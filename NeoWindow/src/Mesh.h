#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Shader.h"


struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
};



class Mesh {
public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    void Draw(Shader& shader);
private:
    std::vector<Vertex>m_Vertices;
    std::vector<unsigned int>m_Indices;
    unsigned int m_VAO;
    unsigned int m_IBO;
    unsigned int m_VBO;
    glm::vec4 m_Color;
    
};