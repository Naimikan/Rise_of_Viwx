#include "cImageManager.hpp"

ImageManager* ImageManager::instance = NULL;

ImageManager* ImageManager::GetInstance() {
	if (instance == NULL) {
		instance = new ImageManager();
	}

	return instance;
}

ImageManager::ImageManager() {
	
}

ImageManager::~ImageManager() {
	ResourcesManager::DeleteImages();
}

void ImageManager::Initialize(const char* parImagePath) {
	try {
		ResourcesManager::InitializeAllImagesByPath(parImagePath);
	} catch (const SDLException& sdlException) {
		throw sdlException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

Image* ImageManager::GetImage(std::string parImageName) {
	try {
		Image* foundImage = ResourcesManager::GetImage(parImageName);
		return foundImage;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}
