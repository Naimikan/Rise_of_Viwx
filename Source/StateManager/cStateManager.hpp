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








/*class StateManager {
	public:
		static StateManager* Initialize();
		~StateManager();

		void ChangeState(State* parState);

		void PushState(State* parState);
		void PopState();
		void PopAllStates();

		void OnLoop();

	protected:
		StateManager();
		//StateManager(const StateManager &);
		StateManager &operator= (const StateManager &);

	private:
		static StateManager* instance;

		std::vector<State*> states;
		std::vector<State*>::const_reverse_iterator reverseIterator;

		int stateCount;

		enum OperationType {
			optPush,
			optPop
		};

		struct StateOperation {
			OperationType operationType;
			State* state;

			StateOperation(OperationType parOperationType, State* parState = 0) : operationType(parOperationType), state(parState) { };
		};

		std::queue<StateOperation> pendingOperations;

		void ExecutePendingOperations();
};*/

#endif // End _CSTATEMANAGER_HPP_