#include <shadow-engine.hpp>

class sandbox : public SE7::application {
private:

public:
	sandbox() {}

	~sandbox() {}
};

SE7::application *SE7::create_application() {
	return new sandbox();
}