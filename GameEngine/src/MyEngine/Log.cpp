#include "EnginePch.h"
#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace MyEngine {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	// initializing the loggers and setting the output pattern
	void Log::Init() {
		//%T timestamp %n name %v%$ message
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("ENGINE");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}