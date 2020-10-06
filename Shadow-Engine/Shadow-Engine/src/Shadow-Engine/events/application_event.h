#include "se-pch.h"

#ifndef SE_APPLICATION_EVENT
#define SE_APPLICATION_EVENT

#include "event.h"

namespace shadow_engine {
	class SE_API window_resize_event : public event {
	private:
		unsigned int width, height;
	public:
		window_resize_event(unsigned int width, unsigned int height)
			: width(width), height(height) {}

		inline unsigned int get_width() const { return this->width; }
		inline unsigned int get_height() const { return this->height; }

		virtual std::string to_string() const override {
			std::stringstream ss;
			ss << "Window Resize Event: (" << this->width << ", " << this->height << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(window_resize)
		EVENT_CLASS_CATEGORY(event_category_application)
	};

	class SE_API window_close_event : public event {
	public:
		EVENT_CLASS_TYPE(window_close)
		EVENT_CLASS_CATEGORY(event_category_application)
	};

	class SE_API app_tick_event : public event {
	public:
		EVENT_CLASS_TYPE(app_tick)
		EVENT_CLASS_CATEGORY(event_category_application)
	};

	class SE_API app_update_event : public event {
	public:
		EVENT_CLASS_TYPE(app_update)
		EVENT_CLASS_CATEGORY(event_category_application)
	};

	class SE_API app_render_event : public event {
	public:
		EVENT_CLASS_TYPE(app_render)
		EVENT_CLASS_CATEGORY(event_category_application)
	};
}

#endif // !SE_EVENT