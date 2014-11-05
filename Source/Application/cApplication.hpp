#ifndef _CAPPLICATION_HPP
#define _CAPPLICATION_HPP_

#include "../Core/iGlobals.hpp"

#include "../Core/Event/cEvent.hpp"
#include "../Core/SettingsCreator/cSettingsCreator.hpp"
#include "../Core/ResourcesManager/cResourcesManager.hpp"

class Application : public Event {
	public:
		Application();
		
		int OnExecute();
		bool OnInit() throw (GenericException);
		void OnEvent(SDL_Event* parEvent);
		void OnRender();
		void OnLoop();
		void OnExit();
		void OnCleanUp();
		
		void OnKeyDown(SDLKey parSym, SDLMod parMod, Uint16 parUnicode);
		
	private:
		bool isRunning;
		
		SDL_Event eventHandled;
		SDL_Surface* screen;
};

#endif // End _CAPPLICATION_HPP_

