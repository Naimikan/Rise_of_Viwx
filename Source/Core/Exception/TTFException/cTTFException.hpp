#ifndef _CTTFEXCEPTION_HPP_
#define _CTTFEXCEPTION_HPP_

#include "../cGenericException.hpp"

class TTFException : public GenericException {
	public:
		TTFException();
		TTFException(const std::string& parMessage);
		~TTFException() throw();
};

#endif // End _CTTFEXCEPTION_HPP_