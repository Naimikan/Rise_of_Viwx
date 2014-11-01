#ifndef _CAPPLICATION_HPP
#define _CAPPLICATION_HPP_

#include "../Core/iGlobals.hpp"

class Application {
	public:
		Application();
		
		int OnExecute();
		
	private:
		bool isRunning;
};

#endif // End _CAPPLICATION_HPP_

