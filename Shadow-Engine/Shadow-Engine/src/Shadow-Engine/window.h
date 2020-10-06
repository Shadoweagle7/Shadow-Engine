#ifndef SE_WINDOW
#define SE_WINDOW

#include "se-pch.h"
#include "Shadow-Engine/core.h"
#include "events/event.h"

namespace shadow_engine {
	class SE_API window {
	public:
		struct properties {
			std::string title;
			unsigned int width, height;

			properties(
				std::string_view title = "Shadow Engine",
				unsigned int width = 1280,
				unsigned int height = 720
			) : title(title), width(width), height(height) {
			}
		};

		using event_callback_t = std::function<void(event &)>;

		virtual void on_update() = 0;
		virtual unsigned int get_width() const = 0;
		virtual unsigned int get_height() const = 0;
		virtual void set_event_callback(const event_callback_t &callback) = 0;
		virtual void set_vsync(bool enabled) = 0;
		virtual bool is_vsync() const = 0;

		// Change to smart pointer? Or is covariance going to screw things up?
		static window *create(const properties &properties = properties());

		virtual ~window() {}
	};
}

#endif // !SE_WINDOW
