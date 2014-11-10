#include "cImageManager.hpp"

ImageManager* ImageManager::instance = NULL;

ImageManager* ImageManager::Initialize(const char* parImagePath) {
	if (instance == NULL) {
		instance = new ImageManager(parImagePath);
	}

	return instance;
}

ImageManager::ImageManager(const char* parImagePath) {
	ResourcesManager::InitializeAllImagesByPath(parImagePath);
}

ImageManager::~ImageManager() {
	ResourcesManager::DeleteImages();
}

Image* ImageManager::GetImage(std::string parImageName) throw(GenericException) {
	Image* foundImage = ResourcesManager::GetImage(parImageName);
	return foundImage;
}
