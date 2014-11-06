#ifndef _CSDLEXCEPTION_HPP_
#define _CSDLEXCEPTION_HPP_

#include "../cGenericException.hpp"

class SDLException : public GenericException {
	public:
		SDLException();
		SDLException(const std::string& parMessage);
		~SDLException() throw();
};

#endif // End _CSDLEXCEPTION_HPP_