#include "Floor.h"

Floor::Floor()
    :Shape(1.0, 1.0, 1.0, 1.0)
{
    int Rows = 20;
    unsigned int ind_count = 0;
    //Draw Rows
    for (int i = -Rows/2; i <= Rows/2; i++)
    {
        this->m_Vertices.push_back(glm::vec3(-Rows / 2, 0.0, -i));
        this->m_Vertices.push_back(glm::vec3(Rows / 2, 0.0, -i));
        this->m_Indices.push_back(ind_count++);
        this->m_Indices.push_back(ind_count++);
    }

    for (int i = -Rows / 2; i <= Rows / 2; i++)
    {
        this->m_Vertices.push_back(glm::vec3(-i,0.0, -Rows / 2));
        this->m_Vertices.push_back(glm::vec3(-i, 0.0, Rows / 2));
        this->m_Indices.push_back(ind_count++);
        this->m_Indices.push_back(ind_count++);
    }

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

void Floor::Draw(Shader& shader)
{
    shader.Bind();
    shader.setUniformVec4f("ObjectColor", m_Color);
    shader.setUniformMat4f("u_Model", m_Model);
    glBindVertexArray(m_VAO);
    glDrawElements(GL_LINES, m_Indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

}
