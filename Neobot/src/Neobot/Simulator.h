#pragma once
#include "Core.h"
#include "World.h"
#include "Object.h"
namespace Neobot
{
	class NEOBOT_API Simulator
	{
	public:
		Simulator(World* world);
		virtual ~Simulator();
		void Step();
		void SetWorld(World* world);
		// to be defined in client	
	private:
		World* m_world;
	};
}