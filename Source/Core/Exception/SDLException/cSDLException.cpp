#include "cSDLException.hpp"

SDLException::SDLException() : GenericException(SDL_GetError()) {

}

SDLException::SDLException(const std::string& parMessage) : GenericException(parMessage) {

}

SDLException::~SDLException() throw() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}
