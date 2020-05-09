#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.h"

class Shape
{
public:
	Shape(float r =1.0f,float g =1.0f, float b = 1.0f ,float a = 1.0f)
		:m_Model(glm::mat4(1.0f)), m_Color(glm::vec4(r, g, b, a))
	{}
	virtual ~Shape() {};
	void Translate(float x, float y, float z)
	{
		m_Model = glm::translate(m_Model, glm::vec3(x, y, z));
	}
	void SetPosition(float x, float y, float z)
	{
		m_Model[3][0] = x;
		m_Model[3][1] = y;
		m_Model[3][2] = z;
	}
	void SetRotation(float angle, float x, float y, float z)
	{
		float xt = m_Model[3][0];float yt = m_Model[3][1];float zt = m_Model[3][2];
		m_Model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(x, y, z));
		this->SetPosition(xt, yt, zt);
	}
	void Rotate(float angle, float x, float y, float z)
	{
		m_Model = glm::rotate(m_Model, glm::radians(angle), glm::vec3(x, y, z));
	}
	virtual void Draw(Shader& shader) {};

protected:
	glm::vec4 m_Color;
	glm::mat4 m_Model;
};

