#include "cTTFException.hpp"

TTFException::TTFException() : GenericException(TTF_GetError()) {

}

TTFException::TTFException(const std::string& parMessage) : GenericException(parMessage) {

}

TTFException::~TTFException() throw() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}