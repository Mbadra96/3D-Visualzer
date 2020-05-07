#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include "Shader.h"
#include "VertexArray.h"
#include <memory>


class Shape
{
public:
	Shape();
	~Shape();
	void Translate(float x, float y, float z);
	void Rotate(float angle, float x, float y, float z);
	void OnRender(Shader& shader);
private:
	std::unique_ptr<VertexArray> m_VAO;
	std::unique_ptr<IndexBuffer> m_IBO;
	std::unique_ptr<VertexBuffer> m_VBO;
	std::vector<Texture*> textures;
	glm::mat4 m_Model;
};

