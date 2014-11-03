#include "cApplication.hpp"

Application::Application() : isRunning(true), screen(NULL) {

}

int Application::OnExecute() {
	OnInit();
	
	std::cout << "Rise of Viwx" << std::endl;
	Logger::WriteMessageInLogFile("Test Log - Rise of Viwx");
	
	return 0;
}

bool Application::OnInit() {
	int windowWidth, windowHeight, windowBPP, windowFullScreen;

	windowWidth = windowHeight = windowBPP = windowFullScreen = 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

	SettingsCreator::ConfigureSettingsFile();
	
	std::map<std::string, std::string> resultPair = SettingsCreator::GetSettingsBySection("Resolution");

	for (std::map<std::string, std::string>::iterator mapIterator = resultPair.begin(); mapIterator != resultPair.end(); ++mapIterator) {
		std::pair<std::string, std::string> pairItem = (*mapIterator);

		if (pairItem.first == "Width") {
			windowWidth = atoi(pairItem.second.c_str());
		} else if (pairItem.first == "Height") {
			windowHeight = atoi(pairItem.second.c_str());
		} else if (pairItem.first == "BPP") {
			windowBPP = atoi(pairItem.second.c_str());
		} else if (pairItem.first == "FullScreen") {
			windowFullScreen = atoi(pairItem.second.c_str());
		}
	}

	Uint32 flags = SDL_HWSURFACE | SDL_DOUBLEBUF;

	if (windowFullScreen == 1) {
		flags = flags | SDL_FULLSCREEN;
	}

	if ((screen = SDL_SetVideoMode(windowWidth, windowHeight, windowBPP, flags)) == NULL) {
		return false;
	}

	std::string applicationName, version;
	applicationName = version = "";

	std::map<std::string, std::string> otherPair = SettingsCreator::GetSettingsBySection("Other Settings");

	for (std::map<std::string, std::string>::iterator mapIterator = otherPair.begin(); mapIterator != otherPair.end(); ++mapIterator) {
		std::pair<std::string, std::string> pairItem = (*mapIterator);

		if  (pairItem.first == "Application Name") {
			applicationName = pairItem.second;
		} else if (pairItem.first == "Version") {
			version = pairItem.second;
		}
	}

	// Set the window caption
	std::string caption;
	caption.append(applicationName);
	caption.append(" v. ");
	caption.append(version);

	SDL_WM_SetCaption(caption.c_str(), NULL);

	return true;
}
