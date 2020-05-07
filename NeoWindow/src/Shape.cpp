#include "Shape.h"



Shape::Shape()
    :m_Model(glm::mat4(1.0f))

{
    float positions[] =
    {
        -0.5, -0.5, 0.5,0.0f,0.0f,1.0f, 0.0f,0.0f,
         0.5, -0.5, 0.5,0.0f,0.0f,1.0f, 1.0f,0.0f,
         0.5, 0.5, 0.5, 0.0f,0.0f,1.0f, 1.0f,1.0f,
        -0.5, 0.5, 0.5, 0.0f,0.0f,1.0f, 0.0f,1.0f,

        -0.5, -0.5, -0.5,0.0f,0.0f,-1.0f,0.0f,0.0f,
         0.5, -0.5, -0.5,0.0f,0.0f,-1.0f,1.0f,0.0f,
         0.5, 0.5, -0.5, 0.0f,0.0f,-1.0f,1.0f,1.0f,
        -0.5, 0.5, -0.5, 0.0f,0.0f,-1.0f,0.0f,1.0f,

         0.5, -0.5, -0.5,1.0f,0.0f,0.0f,0.0f,0.0f,
         0.5, 0.5, -0.5, 1.0f,0.0f,0.0f,1.0f,0.0f,
         0.5, 0.5, 0.5, 1.0f,0.0f,0.0f, 1.0f,1.0f,
         0.5, -0.5, 0.5, 1.0f,0.0f,0.0f,0.0f,1.0f,

        -0.5, 0.5, -0.5, -1.0f,0.0f,0.0f,0.0f,0.0f,
        -0.5, -0.5, -0.5,-1.0f,0.0f,0.0f,1.0f,0.0f,
        -0.5, -0.5, 0.5, -1.0f,0.0f,0.0f,1.0f,1.0f,
        -0.5, 0.5, 0.5, -1.0f,0.0f,0.0f, 0.0f,1.0f,

        -0.5, -0.5, -0.5, 0.0f,-1.0f,0.0f,0.0f,0.0f,
         0.5, -0.5, -0.5,0.0f,-1.0f,0.0f, 1.0f,0.0f,
         0.5, -0.5, 0.5, 0.0f,-1.0f,0.0f, 1.0f,1.0f,
        -0.5, -0.5, 0.5, 0.0f,-1.0f,0.0f, 0.0f,1.0f,

         0.5, 0.5, -0.5,0.0f,1.0f,0.0f,0.0f,0.0f,
        -0.5, 0.5, -0.5,0.0f,1.0f,0.0f,1.0f,0.0f,
        -0.5, 0.5, 0.5, 0.0f,1.0f,0.0f,1.0f,1.0f,
         0.5, 0.5, 0.5, 0.0f,1.0f,0.0f,0.0f,1.0f
    };

    unsigned int indices[] =
    {
         0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        8, 9, 10, 10, 11, 8,
        12, 13, 14, 14, 15, 12,
        16, 17, 18, 18, 19, 16,
        20, 21, 22, 22, 23, 20
    };

    m_VAO = std::make_unique<VertexArray>();
    m_VBO = std::make_unique<VertexBuffer>(positions, sizeof(positions));
    VertexBufferLayout layout;
    layout.Push<float>(3);//location 1 
    layout.Push<float>(3);//location 2
    layout.Push<float>(2);//location 3
    m_VAO->AddBuffer(*m_VBO, layout);

    m_IBO = std::make_unique<IndexBuffer>(indices, sizeof(indices) / sizeof(unsigned int));

    Texture* tex1 = new Texture("res/textures/container2.png");
    Texture* tex2 = new Texture("res/textures/container2_specular.png");

    textures.push_back(tex1);
    textures.push_back(tex2);
}

Shape::~Shape()
{
    for (int i = 0; i < textures.size(); i++)
    {
        delete textures[i];
    }
}

void Shape::Translate(float x, float y, float z)
{
    m_Model = glm::translate(m_Model, glm::vec3(x, y, z));
}

void Shape::Rotate(float angle, float x, float y, float z)
{
    m_Model = glm::rotate(m_Model, glm::radians(angle), glm::vec3(x, y, z));
}

void Shape::OnRender(Shader& shader)
{

    shader.Bind();
    shader.setUniform1f("material.shininess", 32.0f);
    textures[0]->Bind(0);
    textures[1]->Bind(1);
    m_VAO->Bind();
    m_IBO->Bind();
    shader.setUniformMat4f("u_Model", m_Model);
    glDrawElements(GL_TRIANGLES, m_IBO->getCount(), GL_UNSIGNED_INT, nullptr);
    
}



