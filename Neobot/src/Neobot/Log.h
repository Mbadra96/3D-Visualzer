#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>
namespace Neobot
{
	class NEOBOT_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define NB_CORE_TRACE(...)    ::Neobot::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NB_CORE_INFO(...)     ::Neobot::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NB_CORE_WARN(...)     ::Neobot::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NB_CORE_ERROR(...)    ::Neobot::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NB_CORE_CRITICAL(...) ::Neobot::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define NB_TRACE(...)         ::Neobot::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NB_INFO(...)          ::Neobot::Log::GetClientLogger()->info(__VA_ARGS__)
#define NB_WARN(...)          ::Neobot::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NB_ERROR(...)         ::Neobot::Log::GetClientLogger()->error(__VA_ARGS__)
#define NB_CRITICAL(...)      ::Neobot::Log::GetClientLogger()->critical(__VA_ARGS__)