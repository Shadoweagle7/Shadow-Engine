#include "se-pch.h"
#include "windows_window.h"

#include "Shadow-Engine/events/application_event.h"
#include "Shadow-Engine/events/key_event.h"
#include "Shadow-Engine/events/mouse_event.h"
#include "Shadow-Engine/events/touch_event.h"

namespace shadow_engine {
	static bool glfw_initialized = false;

	// TODO: Smart Pointer?
	window *window::create(const window::properties &properties) {
		return new windows_window(properties);
	}

	void windows_window::init(const window::properties &properties) {
		this->window_data.title = properties.title;
		this->window_data.width = properties.width;
		this->window_data.height = properties.height;

		SE_CORE_INFO(
			"Creating Window: ( title = \"{0}\", width = {1}, height = {2} )",
			this->window_data.title,
			this->window_data.width,
			this->window_data.height
		);

		if (!glfw_initialized) {
			int success = glfwInit();

			SE_CORE_ASSERT(success, "Failed to initialize GLFW.");

			glfw_initialized = true;
		}

		this->internal_window = glfwCreateWindow(
			(int)this->window_data.width,
			(int)this->window_data.height,
			this->window_data.title.c_str(),
			nullptr,
			nullptr
		);

		glfwMakeContextCurrent(this->internal_window);
		glfwSetWindowUserPointer(this->internal_window, &this->window_data);
		
		this->set_vsync(true);

		// set GLFW callbacks

		glfwSetWindowSizeCallback(this->internal_window, [](GLFWwindow *window, int width, int height) {
			windows_window::window_data_t &window_data = *static_cast<windows_window::window_data_t *>(glfwGetWindowUserPointer(window));
			window_data.width = width;
			window_data.height = height;

			window_resize_event wr_event(width, height);

			window_data.event_callback(wr_event);
		});

		glfwSetWindowCloseCallback(this->internal_window, [](GLFWwindow *window) {
			windows_window::window_data_t &window_data = *static_cast<windows_window::window_data_t *>(glfwGetWindowUserPointer(window));

			window_close_event wc_event;

			window_data.event_callback(wc_event);
		});

		glfwSetKeyCallback(this->internal_window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
			windows_window::window_data_t &window_data = *static_cast<windows_window::window_data_t *>(glfwGetWindowUserPointer(window));

			switch (action) {
				default:
					break;
			}
		});
	}

	void windows_window::shutdown() {
		glfwDestroyWindow(this->internal_window);
	}

	windows_window::windows_window(const window::properties &properties) {
		this->init(properties);
	}

	void windows_window::on_update() {
		glfwPollEvents();
		glfwSwapBuffers(this->internal_window);
	}

	void windows_window::set_vsync(bool enabled) {
		glfwSwapInterval((enabled ? 1 : 0));

		this->window_data.vsync = enabled;
	}

	bool windows_window::is_vsync() const {
		return this->window_data.vsync;
	}

	windows_window::~windows_window() {
		this->shutdown();
	}

}