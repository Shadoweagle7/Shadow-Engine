#include "se-pch.h"
#include "application.h"

namespace shadow_engine {
	application::application() {
		this->application_window = std::unique_ptr<window>(window::create());
	}

	application::~application() {

	}
	void application::run() {
		while (this->running) {
			this->application_window->on_update();
		}
	}
}