#pragma once
#pragma once
#include "Shape.h"
#include <vector>


class Floor : public Shape
{
public:
	Floor();
	~Floor() {}
	void Draw(Shader& shader) override;
private:
	std::vector<glm::vec3> m_Vertices;
	std::vector<unsigned int>m_Indices;
	unsigned int m_VAO;
	unsigned int m_IBO;
	unsigned int m_VBO;

};

