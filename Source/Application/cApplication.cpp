#include "cApplication.hpp"

Application::Application() : isRunning(true) {

}

int Application::OnExecute() {
	std::cout << "Rise of Viwx" << std::endl;
	Logger::WriteMessageInLogFile("Test Log - Rise of Viwx");
	
	return 0;
}
