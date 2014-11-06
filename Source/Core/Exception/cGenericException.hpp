#ifndef _CGENERICEXCEPTION_HPP_
#define _CGENERICEXCEPTION_HPP_

#include <exception>
#include <cstring>
#include <string>

#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"

class GenericException : public std::exception {
	public:
		GenericException();
		GenericException(const std::string& parMessage);
		virtual ~GenericException() throw();
		virtual const char* WhatHappens() const throw();

	private:
		std::string exceptionMessage;
};

#endif // _CGENERICEXCEPTION_HPP_
