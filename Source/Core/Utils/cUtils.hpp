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
		static std::string UnsignedIntToString(unsigned int parNumber);
		static std::string IntegerToString(int parNumber);
		static std::string LongToString(long parNumber);
		static std::string DoubleToString(double parNumber);
		static std::string FloatToString(float parNumber);
};

#endif // End _CUTILES_HPP_
