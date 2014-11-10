#include "cImage.hpp"

Image::Image(std::string parPath) throw(GenericException) : imagePath(parPath) {
	SDL_Surface* tempSurface = NULL;

	if((tempSurface = SDL_LoadBMP(parPath.c_str())) == NULL) {
		throw GenericException();
	}

	image = SDL_DisplayFormat(tempSurface);
	SDL_FreeSurface(tempSurface);
}

Image::~Image() {
	if (image) {
        SDL_FreeSurface(image);
    }

    image = NULL;
}