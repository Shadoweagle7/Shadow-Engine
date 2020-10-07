#include "se-pch.h"
#include "windows_window.h"

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