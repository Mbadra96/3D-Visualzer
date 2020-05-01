#pragma once

#ifdef NB_PLATFORM_WINDOWS
#include "Application.h"
extern Neobot::Application* Neobot::CreateApplication();

int main(int argc,char** argv)
{
	auto app = Neobot::CreateApplication();

	app->Run();

	delete app;
}

#endif // NB_PLATFORM_WINDOWS
