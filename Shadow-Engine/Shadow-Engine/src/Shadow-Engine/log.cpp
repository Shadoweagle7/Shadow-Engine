#include "log.h"

#include "spdlog\sinks\stdout_color_sinks.h"

namespace shadow_engine {
	std::shared_ptr<spdlog::logger> log::core_logger;
	std::shared_ptr<spdlog::logger> log::client_logger;

	void log::init() {
		spdlog::set_pattern("%^[%n::%T]: %v%$");

		core_logger = spdlog::stdout_color_mt("SHADOW ENGINE");

		core_logger->set_level(spdlog::level::trace);

		client_logger = spdlog::stdout_color_mt("APPLICATION");

		client_logger->set_level(spdlog::level::trace);
	}
}