#ifndef SE7_ENTRYPOINT
#define SE7_ENTRYPOINT

#include "application.hpp"

#ifdef SE7_WINDOWS

extern SE7::application *SE7::create_application();

int main(int argc, const char *argv[]) {
	auto app = SE7::create_application();
	app->run();
	delete app;
}

#else
#error Windows is currently the only supported platform.
#endif // SE7_WINDOWS


#endif // !SE7_ENTRYPOINT
