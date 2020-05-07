#pragma once
#include "Core.h"
#include <string>
namespace Neobot
{
	class NEOBOT_API Object
	{
	public:
		enum class Object_TYPE {
			STATIC = 0,
			DYNMAIC = 1
		};
		Object(const std::string name,Object_TYPE type);
		~Object();
		std::string GetObjectName() const {return m_Name;}
		void SetObjectName(const std::string name) { m_Name = name;}
	private:
		std::string m_Name;
		Object_TYPE m_Type;
	};

}