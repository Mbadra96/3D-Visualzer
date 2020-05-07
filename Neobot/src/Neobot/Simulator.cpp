#include "Simulator.h"
namespace Neobot
{
	Simulator::Simulator(World* world)
		:m_world(world)
	{

	}
	Simulator::~Simulator()
	{

	}
	void Simulator::Step()
	{
		//TODO
	}

	void Simulator::SetWorld(World* world)
	{
		m_world = world;
	}

}