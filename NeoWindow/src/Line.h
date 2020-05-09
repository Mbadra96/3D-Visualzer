#pragma once
#include "Shape.h"
#include <vector>



class Line : public Shape
{
public:
	Line(float x1, float y1, float z1, float x2, float y2, float z2, float r = 1.0, float g = 1.0, float b = 1.0, float a = 1.0);
	~Line(){}
	void Draw(Shader& shader) override;
private:
	std::vector<glm::vec3> m_Vertices;
	std::vector<unsigned int>m_Indices;
	unsigned int m_VAO;
	unsigned int m_IBO;
	unsigned int m_VBO;

};

