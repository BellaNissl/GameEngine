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

#ifdef MY_ENGINE_ENABLE_ASSERTS
	#define ENGINE_ASSERT(x, ...) { if(!(x)) { ENGINE_ERROR("Assertion Failed: {0}", (__VA_ARGS__)); __debugbreak(); } }
	#define ENGINE_CORE_ASSERT(x, ...) { if(!(x)) { ENGINE_CORE_ERROR("Assertion Failed: {0}", (__VA_ARGS__)); __debugbreak(); } }
#else 
	#define ENGINE_ASSERT(...)
	#define ENGINE_CORE_ASSERT(...)
#endif

// Bit shifting 1 by x places
#define BIT(x) (1 << x)