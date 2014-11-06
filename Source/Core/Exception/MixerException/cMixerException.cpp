#include "cMixerException.hpp"

MixerException::MixerException() : GenericException(Mix_GetError()) {

}

MixerException::MixerException(const std::string& parMessage) : GenericException(parMessage) {

}

MixerException::~MixerException() throw() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}