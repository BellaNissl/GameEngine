#pragma once

#include "Core.h"

namespace MyEngine {
	class MY_ENGINE_API Application {
	public:

		Application(); 
		virtual ~Application();

		void Run();
	};

	// To be defined in a Client
	Application* CreateApplication();
}