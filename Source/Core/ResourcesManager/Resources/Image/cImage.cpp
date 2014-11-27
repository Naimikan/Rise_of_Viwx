#include "cImage.hpp"

Image::Image(std::string parName, std::string parPath) : imageName(parName), imagePath(parPath) {

}

Image::~Image() {
	Uninitialize();
}

void Image::Initialize() {
	SDL_Surface* tempSurface = NULL;

	if((tempSurface = SDL_LoadBMP(imagePath.c_str())) == NULL) {
		throw SDLException();
	}

	image = SDL_DisplayFormat(tempSurface);

	if (!image) {
		throw SDLException();
	}

	SDL_FreeSurface(tempSurface);
}

void Image::Uninitialize() {
	if (image) {
        SDL_FreeSurface(image);
    }

    image = NULL;
}
