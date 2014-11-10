#ifndef _CIMAGE_HPP_
#define _CIMAGE_HPP_

#include "../../../iGlobals.hpp"

class Image {
	public:
		Image(std::string parName, std::string parPath) throw(GenericException);
		~Image();

		std::string GetPath() { return imagePath; }
		SDL_Surface* GetSDL_Surface() { return image; }

	private:
		std::string imageName;
		std::string imagePath;
		SDL_Surface* image;
};

#endif // End _CIMAGE_HPP_
