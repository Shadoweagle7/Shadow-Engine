#ifndef SE_WINDOWS_WINDOW
#define SE_WINDOWS_WINDOW

#include "Shadow-Engine/window.h"

#include <GLFW/glfw3.h>

namespace shadow_engine {
	class windows_window : public window {
	private:
		struct window_data_t {
			std::string title;
			unsigned int width, height;
			bool vsync;

			window::event_callback_t event_callback;
		};

		GLFWwindow *internal_window;
		window_data_t window_data;

		virtual void init(const window::properties &properties);
		virtual void shutdown(const window::properties &properties);
	public:
		windows_window(const window::properties &properties);

		virtual void on_update() override;

		inline unsigned int get_width() const override { return this->window_data.width; }
		inline unsigned int get_height() const override { return this->window_data.height; }
		
		inline virtual void set_event_callback(const window::event_callback_t &callback) {
			this->window_data.event_callback = callback;
		}

		virtual void set_vsync(bool enabled);
		virtual bool is_vsync() const;

		virtual ~windows_window();
	};
}

#endif // !SE_WINDOWS_WINDOW

