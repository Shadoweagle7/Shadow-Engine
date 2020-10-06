#ifndef SE_KEY_EVENT
#define SE_KEY_EVENT

#include "event.h"

namespace shadow_engine {
	class SE_API key_event : public event {
	protected:
		int keycode;

		key_event(int keycode) : keycode(keycode) {}
	public:
		inline int get_key_code() const { return this->keycode; }

		EVENT_CLASS_CATEGORY(event_category_keyboard | event_category_input)
	};

	class SE_API key_pressed_event : public key_event {
	private:
		int repeat_count;
	public:
		key_pressed_event(int keycode, int repeat_count) 
			: key_event(keycode), repeat_count(repeat_count) {}

		inline int get_repeat_count() const { return this->repeat_count; }

		virtual std::string to_string() const override {
			std::stringstream ss;
			ss << "Key Pressed Event: ( keycode: " 
				<< this->keycode << ", repeat count:" 
				<< this->repeat_count << " )";
			return ss.str();
		}

		EVENT_CLASS_TYPE(key_pressed)
	}

	class SE_API key_released_event : public key_event {
	public:
		key_released_event(int keycode) : key_event(keycode) {}

		virtual std::string to_string() const override {
			std::stringstream ss;
			ss << "Key Pressed Event: [" << this->keycode << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(key_released)
	};
}

#endif // !SE_EVENT