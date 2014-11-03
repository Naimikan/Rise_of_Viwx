#include "cGenericException.hpp"

GenericException::GenericException() : exception(), exceptionMessage(SDL_GetError()) {

}

GenericException::GenericException(const std::string& parMessage) : exception(), exceptionMessage(parMessage) {

}

GenericException::~GenericException() throw() {

}

const char* GenericException::WhatHappens() const throw() {
    return exceptionMessage.c_str();
}
