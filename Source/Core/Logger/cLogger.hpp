#ifndef _CLOGGER_HPP_
#define _CLOGGER_HPP_

#include <fstream>
#include <iostream>
#include <ctime>
#include <cstring>

#include "../Utils/cUtils.hpp"

class Logger {
	public:
		static void WriteMessageInLogFile(const char* parMessage);

	private:
		static std::fstream logFile;
};

#endif // End _CLOGGER_HPP_
