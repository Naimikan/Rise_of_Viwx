#ifndef _CIMAGEMANAGER_HPP_
#define _CIMAGEMANAGER_HPP_

#include "../../cResourcesManager.hpp"

class ImageManager {
	public:
		static ImageManager* Initialize(const char* parFontPath);
		~ImageManager();

		Image* GetImage(std::string parFontName) throw(GenericException);

	protected:
		ImageManager(const char* parFontPath);
		//ImageManager(const ImageManager &);
		ImageManager &operator= (const ImageManager &);

	private:
		static ImageManager* instance;
};

#endif // End _CIMAGEMANAGER_HPP_
