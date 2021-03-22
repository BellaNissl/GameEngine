#pragma once

#ifdef MY_ENGINE_PLATFORM_WINDOWS

extern MyEngine::Application* MyEngine::CreateApplication();

int main(int argc, char** argv) {
	
	MyEngine::Log::Init();
	ENGINE_CORE_WARN("Initialized Log!");
	int a = 5;
	ENGINE_INFO("Hello! Var={0}", a);
	auto app = MyEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif