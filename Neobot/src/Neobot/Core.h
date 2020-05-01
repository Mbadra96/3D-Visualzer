#pragma once

#ifdef NB_PLATFORM_WINDOWS
	#ifdef NB_BUILD_DLL
		#define NEOBOT_API __declspec(dllexport)
	#else
		#define NEOBOT_API __declspec(dllimport)
	#endif
#else
	#error Neobot only supports Windows!!!
#endif // NB_PLATFORM_WINDOWS
