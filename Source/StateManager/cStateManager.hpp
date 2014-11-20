#ifndef _CSTATEMANAGER_HPP_
#define _CSTATEMANAGER_HPP_

#include "../Core/iGlobals.hpp"
#include "States/cState.hpp"

enum {
	STATE_NONE = 0,
	STATE_MENU = 1,
	STATE_GAME = 2
};

class StateManager {
	public:
		static State* GetActiveState();
		static void SetActiveState(int parStateID);

		static void OnEvent(SDL_Event* parEvent);
		static void OnLoop();
		static void OnRender(SDL_Surface* parSurface);

	private:
		static State* activeState;
};

#endif // End _CSTATEMANAGER_HPP_