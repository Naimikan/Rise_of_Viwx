#ifndef _CGAMESTATE_HPP_
#define _CGAMESTATE_HPP_

#include "../cState.hpp"
#include "../../../Core/ResourcesManager/Managers/FontManager/cFontManager.hpp"

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

		FontManager* fontManager;
};

#endif // End _CGAMESTATE_HPP_
