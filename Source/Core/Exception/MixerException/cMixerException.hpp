#ifndef _CMIXEREXCEPTION_HPP_
#define _CMIXEREXCEPTION_HPP_

#include "../cGenericException.hpp"

class MixerException : public GenericException {
	public:
		MixerException();
		MixerException(const std::string& parMessage);
		~MixerException() throw();
};

#endif // End _CMIXEREXCEPTION_HPP_