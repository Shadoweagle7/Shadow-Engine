#include "se-pch.h"
#include "application.h"

#include "Shadow-Engine/events/application_event.h"
#include "Shadow-Engine/log.h"

#include <GLFW/glfw3.h>

namespace shadow_engine {
	application::application() {
		this->application_window = std::unique_ptr<window>(window::create());
		this->application_window->set_event_callback(
			std::bind(&application::on_event, this, std::placeholders::_1)
		);
	}

	application::~application() {

	}

	void application::run() {
		while (this->running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			this->application_window->on_update();
		}
	}
	void application::on_event(event &e) {
		SE_CORE_INFO("{0}", e);
	}
}