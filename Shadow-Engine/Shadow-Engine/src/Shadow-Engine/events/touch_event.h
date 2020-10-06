#ifndef SE_TOUCH_EVENT
#define SE_TOUCH_EVENT

#include "event.h"

namespace shadow_engine {
	class SE_API touch_event : public event {
	protected:
		float touch_x, touch_y;

		touch_event(float touch_x, float touch_y)
			: touch_x(touch_x), touch_y(touch_y) {
		}
	public:

		inline float get_x() const { return this->touch_x; }
		inline float get_y() const { return this->touch_y; }

		virtual std::string to_string() const override {
			std::stringstream ss;
			ss << "Touch Event: (" << this->touch_x << ", " << this->touch_y << ")";
			return ss.str();
		}

		//EVENT_CLASS_TYPE(mouse_scrolled)
		EVENT_CLASS_CATEGORY(event_category_touch_screen | event_category_input) // How else to classify?
	};

	class SE_API touch_pressed_event : public touch_event {
	private:

	public:
		touch_pressed_event(float touch_x, float touch_y)
			: touch_event(touch_x, touch_y) {
		}

		virtual std::string to_string() const override {
			std::stringstream ss;
			ss << "Touch Pressed Event: (" << this->touch_x << ", " << this->touch_y << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(touch_screen_pressed)
	};

	class SE_API touch_released_event : public touch_event {
	private:

	public:
		touch_released_event(float touch_x, float touch_y)
			: touch_event(touch_x, touch_y) {
		}

		virtual std::string to_string() const override {
			std::stringstream ss;
			ss << "Touch Released Event: (" << this->touch_x << ", " << this->touch_y << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(touch_screen_released)
	};

	class SE_API touch_swipe_event : public touch_event {
	private:

	public:
		touch_swipe_event(float touch_x, float touch_y)
			: touch_event(touch_x, touch_y) {
		}

		virtual std::string to_string() const override {
			std::stringstream ss;
			ss << "Touch Swipe Event: (" << this->touch_x << ", " << this->touch_y << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(touch_screen_swiped)
	};
}

#endif // !SE_TOUCH_EVENT
