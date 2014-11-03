#include "cLogger.hpp"

std::fstream Logger::logFile;

void Logger::WriteMessageInLogFile(const char* parMessage) {
	logFile.open("Logger/Game.log", std::fstream::in | std::fstream::out | std::fstream::app);

	std::string finalLogMessage;

	time_t now = time(0);
	tm *datetimeNow = localtime(&now);

	std::string dateForLog;
	dateForLog.append("{");
	dateForLog.append(Utils::ToString(1900 + datetimeNow->tm_year));
	dateForLog.append("-");
	dateForLog.append(Utils::ToString(1 + datetimeNow->tm_mon));
	dateForLog.append("-");

	if (datetimeNow->tm_mday < 10) {
		dateForLog.append("0");
	}

	dateForLog.append(Utils::ToString(datetimeNow->tm_mday));
	dateForLog.append(" ");
	dateForLog.append(Utils::ToString(datetimeNow->tm_hour));
	dateForLog.append(":");
	dateForLog.append(Utils::ToString(datetimeNow->tm_min));
	dateForLog.append(":");
	dateForLog.append(Utils::ToString(datetimeNow->tm_sec));
	dateForLog.append("} - ");

	finalLogMessage.append(dateForLog);
	finalLogMessage.append(parMessage);
	finalLogMessage.append("\n");

	logFile << finalLogMessage.c_str();

	logFile.close();
}
