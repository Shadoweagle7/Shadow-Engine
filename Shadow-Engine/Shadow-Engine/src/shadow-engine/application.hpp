#ifndef SE7_APPLICATION
#define SE7_APPLICATION

#include "core.hpp"

namespace SE7 {
	class SE7_API application {
	private:

	public:
		application();
		virtual ~application();

		void run();
	};

	application *create_application();
}

#endif // !SE7_APPLICATION


