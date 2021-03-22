#pragma once

#ifdef MY_ENGINE_PLATFORM_WINDOWS
	#ifdef MY_ENGINE_BUILD_DLL
		#define MY_ENGINE_API __declspec(dllexport)
	#else
		#define MY_ENGINE_API __declspec(dllimport)
	#endif
#else 
	#error My Engine only supports Windows
#endif