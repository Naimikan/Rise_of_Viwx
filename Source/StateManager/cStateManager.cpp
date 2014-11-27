#include "cStateManager.hpp"

// Incluir aqui los otros estados, por referencias cíclicas
#include "States/Menu/cMenuState.hpp"
#include "States/Game/cGameState.hpp"

State* StateManager::activeState = 0;
 
void StateManager::OnEvent(SDL_Event* parEvent) {
	if (activeState) {
		activeState->OnEvent(parEvent);
	}
}

void StateManager::OnLoop() {
	if (activeState) {
		activeState->OnLoop();
	}
}

void StateManager::OnRender(SDL_Surface* parSurface) {
	try {
		if (activeState) {
			activeState->OnRender(parSurface);
		}
	} catch (const SDLException& sdlException) {
		throw sdlException;
	} catch (const TTFException& ttfException) {
		throw ttfException;
	} catch (const MixerException& mixerException) {
		throw mixerException;
	}
}

State* StateManager::GetActiveState() {
	return activeState;
}

void StateManager::SetActiveState(int parStateID) {
	try {
		if (activeState) {
			activeState->OnDeactivate();
		}

		switch (parStateID) {
			case STATE_NONE:
				activeState = 0;
				break;

			case STATE_MENU:
				activeState = MenuState::GetInstance();
				break;
				
			case STATE_GAME:
				activeState = GameState::GetInstance();
				break;
		}

		if (activeState) {
			activeState->OnActivate();
		}
	} catch (const SDLException& sdlException) {
		throw sdlException;
	} catch (const TTFException& ttfException) {
		throw ttfException;
	} catch (const MixerException& mixerException) {
		throw mixerException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}
