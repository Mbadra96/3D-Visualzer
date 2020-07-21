#include "Renderer.h"

Renderer::Renderer()
{
	m_Window.Init();
}

int Renderer::AddFloor()
{
	m_Models.emplace(std::pair<int, Shape* >(m_ModelCounter, new Floor()));
	return m_ModelCounter++;
}

int Renderer::AddLine(float x1, float y1, float z1, float x2, float y2, float z2, float r, float g , float b , float a )
{
	m_Models.emplace(std::pair<int, Shape* >(m_ModelCounter, new Line(x1,y1,z1,x2,y2,z2,r,g,b,a)));
	return m_ModelCounter++;
}

int Renderer::AddModel(const std::string& filepath)
{
	m_Models.emplace(std::pair<int, Shape* >(m_ModelCounter, new Model(filepath)));
	return m_ModelCounter++;
}
void Renderer::Update()
{
	m_Window.Draw(m_Models);
}

void Renderer::Remove(int id)
{
	try 
	{
		m_Models.erase(id);
	}
	catch(int e)
	{
		std::cout << "Model: " << id << " Not found" << std::endl;
	}
}
int Renderer::Closed()
{
	return m_Window.WindowClosed();
}

void Renderer::SetPosition(int model_id,float x, float y, float z)
{
	try
	{
		m_Models[model_id]->SetPosition(x, y, z);
	}
	catch (int e)
	{
		std::cout << "Model: " << model_id << " Not found" << std::endl;
	}
}

void Renderer::SetRotation(int model_id, float angle, float x, float y, float z)
{
	try
	{
		m_Models[model_id]->SetRotation(angle,x, y, z);
	}
	catch (int e)
	{
		std::cout << "Model: " << model_id << " Not found" << std::endl;
	}
}

void Renderer::Rotate(int model_id, float angle, float x, float y, float z)
{

	try
	{
		m_Models[model_id]->Rotate(angle,x, y, z);
	}
	catch (int e)
	{
		std::cout << "Model: " << model_id << " Not found" << std::endl;
	}
}

void Renderer::Translate(int model_id, float x, float y, float z)
{
	try
	{
		m_Models[model_id]->Translate(x, y, z);
	}
	catch (int e)
	{
		std::cout << "Model: " << model_id << " Not found" << std::endl;
	}
}

void Renderer::DrawCoord(float length)
{
	this->AddLine(0, 0.0, 0.0, length, 0.0, 0.0, 0.0, 0.0, 1.0);
	this->AddLine(0.0, 0, 0.0, 0.0, length, 0.0, 0.0, 1.0, 0.0);
	this->AddLine(0.0, 0.0, 0.0, 0.0, 0.0, length, 1.0, 0.0, 0.0);
}
