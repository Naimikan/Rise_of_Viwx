#ifndef _CIMAGEMANAGER_HPP_
#define _CIMAGEMANAGER_HPP_

#include "../../cResourcesManager.hpp"

class ImageManager {
	public:
		static ImageManager* Initialize(const char* parImagePath);
		~ImageManager();

		Image* GetImage(std::string parImageName);

	protected:
		ImageManager(const char* parImagePath);
		//ImageManager(const ImageManager &);
		ImageManager &operator= (const ImageManager &);

	private:
		static ImageManager* instance;
};

#endif // End _CIMAGEMANAGER_HPP_
