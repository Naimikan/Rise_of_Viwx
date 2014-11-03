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
