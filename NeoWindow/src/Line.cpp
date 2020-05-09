#include "Line.h"

 Line::Line(float x1, float y1, float z1, float x2, float y2, float z2, float r, float g, float b, float a)
	 :Shape(r,g,b,a)
{

     this->m_Vertices.push_back(glm::vec3(x1, y1, z1));
     this->m_Vertices.push_back(glm::vec3(x2, y2, z2));

     this->m_Indices.push_back(0);
     this->m_Indices.push_back(1);
     //VAO
     glGenVertexArrays(1, &m_VAO);
     glBindVertexArray(m_VAO);
     //VBO
     glGenBuffers(1, &m_VBO);
     glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
     glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(glm::vec3), &m_Vertices[0], GL_STATIC_DRAW);

     //IBO
     glGenBuffers(1, &m_IBO);
     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
     glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Indices.size() * sizeof(unsigned int), &m_Indices[0], GL_STATIC_DRAW);

     // vertex positions
     glEnableVertexAttribArray(0);
     glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, sizeof(glm::vec3), (void*)0);
     glBindVertexArray(0);
}

void Line::Draw(Shader& shader)
{
    shader.Bind();
    shader.setUniformVec4f("ObjectColor", m_Color);
    shader.setUniformMat4f("u_Model", m_Model);
    glBindVertexArray(m_VAO);
    glDrawElements(GL_LINES, m_Indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

}
