#ifndef SE7_APPLICATION
#define SE7_APPLICATION

#include "core.h"

namespace shadow_engine {
	class SE_API application {
	private:

	public:
		application();
		virtual ~application();
		
		void run();
	};

	// Define in client
	application *create_application();
}

#endif // !SE7_APPLICATION
