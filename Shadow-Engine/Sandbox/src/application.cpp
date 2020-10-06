
namespace shadow_engine {
	__declspec(dllimport) void print();
}

int main(int argc, const char *argv[]) {
	shadow_engine::print();

	return 0;
}