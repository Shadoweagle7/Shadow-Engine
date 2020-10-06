#ifndef SE_ENTRYPOINT
#define SE_ENTRYPOINT

#ifdef SE_PLATFORM_WINDOWS

extern shadow_engine::application *shadow_engine::create_application();

int main(int argc, const char *argv[]) {
	shadow_engine::application *app = shadow_engine::create_application();

	app->run();

	delete app;

	return 0;
}

#else
#error Shadow Engine only supports Windows
#endif // SE_PLATFORM_WINDOWS


#endif // !SE_ENTRYPOINT
