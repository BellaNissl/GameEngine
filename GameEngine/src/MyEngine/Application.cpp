#include "EnginePch.h"
#include "Application.h"

#include "MyEngine/Events/ApplicationEvent.h"
#include "MyEngine/Log.h"

namespace MyEngine {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}


	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		ENGINE_TRACE(e);
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}