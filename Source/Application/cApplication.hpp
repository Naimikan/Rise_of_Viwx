#ifndef _CAPPLICATION_HPP
#define _CAPPLICATION_HPP_

#include "../Core/iGlobals.hpp"
#include "../Core/SettingsCreator/cSettingsCreator.hpp"

class Application {
	public:
		Application();
		
		int OnExecute();
		bool OnInit() throw (GenericException);
		
	private:
		bool isRunning;
		
		SDL_Surface* screen;
};

#endif // End _CAPPLICATION_HPP_

