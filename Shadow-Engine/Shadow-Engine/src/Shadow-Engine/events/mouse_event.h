#ifndef SE_MOUSE_EVENT
#define SE_MOUSE_EVENT

#include "event.h"

namespace shadow_engine {
	class SE_API mouse_moved_event : public event {
	private:
		float mouse_x, mouse_y;
	public:
		mouse_moved_event(float mouse_x, float mouse_y) 
			: mouse_x(mouse_x), mouse_y(mouse_y) {}

		inline float get_x() const { return this->mouse_x; }
		inline float get_y() const { return this->mouse_y; }

		virtual std::string to_string() const override {
			std::stringstream ss;
			ss << "Mouse Moved Event: (" << this->mouse_x << ", " << this->mouse_y << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouse_moved)
		EVENT_CLASS_CATEGORY(event_category_mouse | event_category_input)
	};

	class SE_API mouse_scrolled_event : public event {
	private:
		float x_offset, y_offset;
	public:
		mouse_scrolled_event(float x_offset, float y_offset)
			: x_offset(x_offset), y_offset(y_offset) {
		}

		inline float get_x_offset() const { return this->mouse_x; }
		inline float get_y_offset() const { return this->mouse_y; }

		virtual std::string to_string() const override {
			std::stringstream ss;
			ss << "Mouse Scrolled Event: (" << this->x_offset << ", " << this->y_offset << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouse_scrolled)
		EVENT_CLASS_CATEGORY(event_category_mouse | event_category_input)
	};

	class SE_API mouse_button_event : public event {
	protected:
		int button;

		mouse_button_event(int button) : button(button) {}
	public:
		inline int get_mouse_button() const { return this->button; }

		EVENT_CLASS_CATEGORY(event_category_mouse | event_category_input)
	};

	class SE_API mouse_button_pressed_event : public event {
	public:
		mouse_button_pressed_event(int button) : mouse_button_event(button) {}

		virtual std::string to_string() const override {
			std::stringstream ss;
			ss << "Mouse Button Pressed Event";
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouse_button_pressed)
	};

	class SE_API mouse_button_released_event : public event {
	public:
		mouse_button_released_event(int button) : mouse_button_event(button) {}

		virtual std::string to_string() const override {
			std::stringstream ss;
			ss << "Mouse Button Released Event";
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouse_button_released)
	};
}

#endif // !SE_EVENT