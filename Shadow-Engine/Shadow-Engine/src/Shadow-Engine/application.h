#ifndef SE7_APPLICATION
#define SE7_APPLICATION

#include "core.h"
#include "window.h"

namespace shadow_engine {
	class SE_API application {
	private:
		std::unique_ptr<window> application_window;
		std::atomic_bool running = true;
	public:
		application();
		virtual ~application();
		
		void run();
	};

	// Define in client
	application *create_application();
}

#endif // !SE7_APPLICATION
