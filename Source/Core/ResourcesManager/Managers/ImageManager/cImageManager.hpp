#ifndef _CIMAGEMANAGER_HPP_
#define _CIMAGEMANAGER_HPP_

#include "../../cResourcesManager.hpp"

class ImageManager {
	public:
		static ImageManager* GetInstance();
		~ImageManager();

		Image* GetImage(std::string parImageName);
		void Initialize(const char* parImagePath);
		
	protected:
		ImageManager();
		//ImageManager(const ImageManager &);
		ImageManager &operator= (const ImageManager &);

	private:
		static ImageManager* instance;
};

#endif // End _CIMAGEMANAGER_HPP_
