#ifndef _CSTATE_HPP_
#define _CSTATE_HPP_

#include "../../Core/iGlobals.hpp"

class State {
	public:
		virtual void OnEvent() = 0;
		virtual void OnLoop() = 0;
		virtual void OnRender() = 0;
		virtual ~State() { }
};

#endif // End _CSTATE_HPP_