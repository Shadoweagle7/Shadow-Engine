#include "se-pch.h"

#ifndef SE_EVENT
#define SE_EVENT

#include "Shadow-Engine/core.h"

namespace shadow_engine {
	// Use std::future to defer events as well as buffer events with an event queue?

	enum class event_type {
		none = 0,
		window_close, window_resize, window_focus, window_lost_focus, window_moved,
		app_tick, app_update, app_render,
		key_pressed, key_released,
		mouse_button_pressed, mouse_button_released, mouse_moved, mouse_scrolled,
		touch_screen_pressed, touch_screen_released, touch_screen_swiped
	};

	enum event_category {
		event_category_none = 0,
		event_category_application = CREATE_BIT_FLAG(0),
		event_category_input = CREATE_BIT_FLAG(1),
		event_category_keyboard = CREATE_BIT_FLAG(2),
		event_category_mouse = CREATE_BIT_FLAG(3),
		event_category_mouse_button = CREATE_BIT_FLAG(4),
		event_category_touch_screen = CREATE_BIT_FLAG(5)
	};

#define EVENT_CLASS_TYPE(type) \
static event_type get_static_type() { return event_type::##type; }\
virtual event_type get_event_type() const override { return get_static_type(); }\
virtual const char *get_name() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
virtual int get_category_flags() const override { return category; }

	class event_dispatcher;

	class SE_API event {
	private:
		friend class event_dispatcher;
		bool handled = false;
	public:
		virtual event_type get_event_type() const = 0;
		virtual const char *get_name() const = 0;
		virtual int get_category_flags() const = 0;
		virtual std::string to_string() const { return this->get_name(); }

		inline bool is_in_category(event_category category) {
			return this->get_category_flags() & category;
		}
	};

	class event_dispatcher {
	public:
		template<
			class T,
			std::enable_if_t<
				std::disjunction_v<
					std::is_same<event, T>,
					std::is_base_of<event, T>
				>,
				int
			> = 0
		>
		using event_func_t = std::function<bool(T &)>;
	private:
		event &e;
	public:
		event_dispatcher(event &e) : e(e) {}

		template<class T>
		bool dispatch(event_func_t<T> func) {
			if (e.get_event_type() == T::get_static_type()) {
				e.handled = func(*(T *)&this->e);
				return true;
			}

			return false;
		}
	};

	inline std::ostream &operator<<(std::ostream &os, const event &e) {
		return (os << e.to_string());
	}
}

#endif // !SE_EVENT
