#ifndef _CSTATE_HPP_
#define _CSTATE_HPP_

#include "../../Core/iGlobals.hpp"
#include "../../Core/EventListener/cEventListener.hpp"

class State : public EventListener {
	public:
		State();

		virtual void OnActivate() = 0;
		virtual void OnDeactivate() = 0;
		virtual void OnLoop() = 0;
		virtual void OnRender(SDL_Surface* parSurface) = 0;
};

#endif // End _CSTATE_HPP_
