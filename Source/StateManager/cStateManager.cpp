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
	}
}

State* StateManager::GetActiveState() {
	return activeState;
}

void StateManager::SetActiveState(int parStateID) {
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
}




/*StateManager* StateManager::instance = NULL;

StateManager* StateManager::Initialize() {
	try {
		if (instance == NULL) {
			instance = new StateManager();
		}

		return instance;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

StateManager::StateManager() : stateCount(0) {
	try {
		//ChangeState(StateTypes.StateMenu);
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

StateManager::~StateManager() {

}

void StateManager::ChangeState(State* parState) {
	if (!states.empty()) {
		PopState();
	}

	PushState(parState);
}

void StateManager::PushState(State* parState) {
	pendingOperations.push(StateOperation(optPush, parState));
	++stateCount;
}

void StateManager::PopState() {
	pendingOperations.push(StateOperation(optPop));
	--stateCount;
}

void StateManager::PopAllStates() {
	while (stateCount) {
		PopState();
	}
}

void StateManager::ExecutePendingOperations() {
	while (!pendingOperations.empty()) {
		StateOperation operation = pendingOperations.front();

		if (operation.operationType == optPush) {
			operation.state->LoadState();
			states.push_back(operation.state);
		} else {
			State* state = states.back();
			state->ClearState();
			delete state;
			states.pop_back();
		}

		pendingOperations.pop();
	}
}

void StateManager::OnLoop() {
	ExecutePendingOperations();

	bool active = true;
	for (reverse_iterator = states.rbegin(); reverse_iterator != states.rend(); ++reverse_iterator) {
		(*reverse_iterator)->updateState(parEvent.timeSinceLastFrame, active);
		active = false;
	}
}*/
