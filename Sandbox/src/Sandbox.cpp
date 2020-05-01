#include <Neobot.h>

class Sandbox : public Neobot::Application
{
public: 
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Neobot::Application* Neobot::CreateApplication()
{
	return new Sandbox();
}