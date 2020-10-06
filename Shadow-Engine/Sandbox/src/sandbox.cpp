#include <shadow-engine.h>

class sandbox : public shadow_engine::application {
private:

public:
	sandbox() {
	
	}

	~sandbox() {
	
	}
};

shadow_engine::application *shadow_engine::create_application() {
	return new sandbox();
}