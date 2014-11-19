#ifndef _CMENUSTATE_HPP_
#define _CMENUSTATE_HPP_

#include "cState.hpp"
#include "../../Core/ResourcesManager/Managers/FontManager/cFontManager.hpp"

class MenuState : public State {
	public:
		static MenuState* GetInstance();

		void OnActivate();
		void OnDeactivate(); // OnCleanUp
		void OnLoop();
		void OnRender(SDL_Surface* parSurface);

	private:
		static MenuState* instance;

		FontManager* fontManager;
};

#endif // End _CMENUSTATE_HPP_