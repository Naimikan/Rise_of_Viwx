#ifndef _CUTILES_HPP_
#define _CUTILES_HPP_

#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

class Utils {
	public:
		static std::string Trim(std::string const& parSource, char const* parDelimiter = "\t\r\n");

		// ToString
		template <typename T> static std::string ToString(const T& parValue) {
			std::ostringstream stm;
			stm << parValue;
			return stm.str();
		}
};

#endif // End _CUTILES_HPP_
