#ifndef _CAPPLICATION_HPP
#define _CAPPLICATION_HPP_

#include "../Core/iGlobals.hpp"

#include "../Core/EventListener/cEventListener.hpp"
#include "../Core/SettingsCreator/cSettingsCreator.hpp"

#include "../Core/ResourcesManager/Managers/FontManager/cFontManager.hpp"
#include "../Core/ResourcesManager/Managers/ImageManager/cImageManager.hpp"
#include "../Core/ResourcesManager/Managers/SoundManager/cSoundManager.hpp"

class Application : public EventListener {
	public:
		Application();
		
		int OnExecute();
		bool OnInit();
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

		FontManager* fontManager;
		ImageManager* imageManager;
		SoundManager* soundManager;

		void InitializeSDLSystem();
		void InitializeVideoSystem();
		void InitializeTTFSystem();
		void InitializeAudioSystem();
		void InitializeResources();

};

#endif // End _CAPPLICATION_HPP_

