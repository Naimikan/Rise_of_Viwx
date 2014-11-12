#include "cImageManager.hpp"

ImageManager* ImageManager::instance = NULL;

ImageManager* ImageManager::Initialize(const char* parImagePath) {
	try {
		if (instance == NULL) {
			instance = new ImageManager(parImagePath);
		}

		return instance;
	} catch (const SDLException& sdlException) {
		throw sdlException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

ImageManager::ImageManager(const char* parImagePath) {
	try {
		ResourcesManager::InitializeAllImagesByPath(parImagePath);
	} catch (const SDLException& sdlException) {
		throw sdlException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

ImageManager::~ImageManager() {
	ResourcesManager::DeleteImages();
}

Image* ImageManager::GetImage(std::string parImageName) {
	try {
		Image* foundImage = ResourcesManager::GetImage(parImageName);
		return foundImage;
	} catch (const SDLException& sdlException) {
		throw sdlException;
	}
}
