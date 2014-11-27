#ifndef _CGAMESTATE_HPP_
#define _CGAMESTATE_HPP_

#include "../cState.hpp"
#include "../../../Core/ResourcesManager/Managers/FontManager/cFontManager.hpp"
#include "../../../Core/ResourcesManager/Managers/ImageManager/cImageManager.hpp"
#include "../../../Core/ResourcesManager/Managers/MusicManager/cMusicManager.hpp"

class GameState : public State {
	public:
		static GameState* GetInstance();

		void OnActivate();
		void OnDeactivate(); // OnCleanUp
		void OnLoop();
		void OnRender(SDL_Surface* parSurface);

	private:
		GameState();
		
		static GameState* instance;

		SDL_Surface *message;
		Font* lazyFont;
		Image* backgroundImage;
		Music* backgroundMusic;

		FontManager* fontManager;
		ImageManager* imageManager;
		MusicManager* musicManager;
};

#endif // End _CGAMESTATE_HPP_
