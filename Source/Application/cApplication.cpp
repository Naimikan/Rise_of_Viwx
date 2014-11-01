#include "cApplication.hpp"

Application::Application() : isRunning(true) {

}

int Application::OnExecute() {
	std::cout << "Rise of Viwx" << std::endl;
	
	return 0;
}
