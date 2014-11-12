#include "cImage.hpp"

Image::Image(std::string parName, std::string parPath) : imageName(parName), imagePath(parPath) {
	SDL_Surface* tempSurface = NULL;

	if((tempSurface = SDL_LoadBMP(parPath.c_str())) == NULL) {
		throw SDLException();
	}

	image = SDL_DisplayFormat(tempSurface);

	if (!image) {
		throw SDLException();
	}

	SDL_FreeSurface(tempSurface);
}

Image::~Image() {
	if (image) {
        SDL_FreeSurface(image);
    }

    image = NULL;
}
