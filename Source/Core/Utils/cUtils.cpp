#include "cUtils.hpp"

std::string Utils::Trim(std::string const& parSource, char const* parDelimiter) {
	std::string result(parSource);
	std::string::size_type index = result.find_last_not_of(parDelimiter);

	if (index != std::string::npos) {
		result.erase(++index);
	}

	index = result.find_first_not_of(parDelimiter);

	if (index != std::string::npos) {
		result.erase(0, index);
	} else {
		result.erase();
	}

	return result;
}

std::string Utils::UnsignedIntToString(unsigned int parNumber) {
	std::stringstream ss;
	ss << parNumber;
	return ss.str();
}

std::string Utils::IntegerToString(int parNumber) {
	std::stringstream ss;
	ss << parNumber;
	return ss.str();
}

std::string Utils::LongToString(long parNumber) {
	std::stringstream ss;
	ss << parNumber;
	return ss.str();
}

std::string Utils::DoubleToString(double parNumber) {
	std::stringstream ss;
	ss << parNumber;
	return ss.str();
}

std::string Utils::FloatToString(float parNumber) {
	std::stringstream ss;
	ss << parNumber;
	return ss.str();
}
