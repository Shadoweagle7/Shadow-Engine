#ifndef SE_ENTRYPOINT
#define SE_ENTRYPOINT

#ifdef SE_PLATFORM_WINDOWS

extern shadow_engine::application *shadow_engine::create_application();

int main(int argc, const char *argv[]) {
	shadow_engine::log::init();

	shadow_engine::application *app = shadow_engine::create_application();
	
	SE_CORE_TRACE("Trace test");
	SE_CORE_WARN("Warn test");
	SE_CORE_ERROR("Error test");
	SE_CORE_CRITICAL("Critical test");
	SE_CORE_DEBUG("Debug test");
	SE_CORE_INFO("Info test");

	SE_TRACE("Trace test");
	SE_WARN("Warn test");
	SE_ERROR("Error test");
	SE_CRITICAL("Critical test");
	SE_DEBUG("Debug test");
	SE_INFO("Info test");

	int a = 27;

	SE_CORE_TRACE("Trace test printing variables: {0}", a);
	SE_TRACE("Trace test printing variables: {0}", a);

	app->run();

	delete app;

	return 0;
}

#else
#error Shadow Engine only supports Windows
#endif // SE_PLATFORM_WINDOWS


#endif // !SE_ENTRYPOINT
