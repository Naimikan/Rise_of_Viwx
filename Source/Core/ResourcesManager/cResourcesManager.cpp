#include "cResourcesManager.hpp"

std::map<std::string, Font*> ResourcesManager::fontsList;
std::map<std::string, Image*> ResourcesManager::imagesList;
std::map<std::string, Sound*> ResourcesManager::soundsList;

Font* ResourcesManager::CreateFont(std::string parFontName, const char* parFontPath, int parFontSize) {
	Font* newFont = new Font(parFontName, parFontPath, parFontSize);

	if (!newFont->GetTTF_Font()) {
		throw TTFException();
	}

	return newFont;
}

Font* ResourcesManager::GetFont(std::string parFontName) throw(TTFException) {
	if (parFontName.empty()) {
		throw TTFException("FontName required.");
	}

	if (fontsList.empty()) {
		throw TTFException("Fonts list empty.");
	}

	std::map<std::string, Font*>::const_iterator iteratorFontFound = fontsList.find(parFontName);

	if (iteratorFontFound != fontsList.end()) {
		return iteratorFontFound->second;
	} else {
		throw TTFException("Font not found.");
	}
}

void ResourcesManager::DeleteFonts() {
	for (std::map<std::string, Font*>::iterator mapIterator = fontsList.begin(); mapIterator != fontsList.end(); ++mapIterator) {
		delete (*mapIterator).second;
	}

	fontsList.clear();
}

void ResourcesManager::InitializeAllFontsByPath(const char* parFontPath) {
	DIR* directory;
	struct dirent *direntPointer;
	std::string fontName;

	if((directory = opendir(parFontPath)) == NULL) {
		throw GenericException("Error al abrir el directorio.");
	}

	while ((direntPointer = readdir(directory)) != NULL) {
		if (direntPointer->d_type == File) {
			std::string fullName = parFontPath;
			fullName.append("/");
			fullName.append(direntPointer->d_name);

			fontName = direntPointer->d_name;

			/*if (direntPointer->d_name == ResourcesManager::Lazy) {
				fontName = ResourcesManager::Lazy;
			}*/

			Font* newFont = CreateFont(fontName, fullName.c_str());
			fontsList.insert(std::pair<std::string, Font*>(fontName, newFont));
		}
	}

	closedir(directory);
}

Image* ResourcesManager::CreateImage(std::string parImageName, const char* parImagePath) {
	Image* newImage = new Image(parImageName, parImagePath);
	
	if (!newImage->GetSDL_Surface()) {
		throw GenericException();
	}

	return newImage;
}

Image* ResourcesManager::GetImage(std::string parImageName) throw(GenericException) {
	if (parImageName.empty()) {
		throw GenericException("ImageName required.");
	}

	if (imagesList.empty()) {
		throw GenericException("Images list empty.");
	}

	std::map<std::string, Image*>::const_iterator iteratorImageFound = imagesList.find(parImageName);

	if (iteratorImageFound != imagesList.end()) {
		return iteratorImageFound->second;
	} else {
		throw GenericException("Image not found.");
	}
}

void ResourcesManager::DeleteImages() {
	for (std::map<std::string, Image*>::iterator mapIterator = imagesList.begin(); mapIterator != imagesList.end(); ++mapIterator) {
		delete (*mapIterator).second;
	}

	imagesList.clear();
}

void ResourcesManager::InitializeAllImagesByPath(const char* parImagePath) {
	DIR* directory;
	struct dirent *direntPointer;
	std::string imageName;

	if((directory = opendir(parImagePath)) == NULL) {
		throw GenericException("Error al abrir el directorio.");
	}

	while ((direntPointer = readdir(directory)) != NULL) {
		if (direntPointer->d_type == File) {
			std::string fullName = parImagePath;
			fullName.append("/");
			fullName.append(direntPointer->d_name);

			imageName = direntPointer->d_name;

			Image* newImage = CreateImage(imageName, fullName.c_str());
			imagesList.insert(std::pair<std::string, Image*>(imageName, newImage));
		}
	}

	closedir(directory);
}

Sound* ResourcesManager::CreateSound(std::string parSoundName, const char* parSoundPath) {
	Sound* newSound = new Sound(parSoundName, parSoundPath);
	
	if (!newSound->GetMix_Chunk()) {
		throw MixerException();
	}

	return newSound;
}

Sound* ResourcesManager::GetSound(std::string parSoundName) throw(MixerException) {
	if (parSoundName.empty()) {
		throw MixerException("SoundName required.");
	}

	if (soundsList.empty()) {
		throw MixerException("Sounds list empty.");
	}

	std::map<std::string, Sound*>::const_iterator iteratorSoundFound = soundsList.find(parSoundName);

	if (iteratorSoundFound != soundsList.end()) {
		return iteratorSoundFound->second;
	} else {
		throw MixerException("Sound not found.");
	}
}

void ResourcesManager::DeleteSounds() {
	for (std::map<std::string, Sound*>::iterator mapIterator = soundsList.begin(); mapIterator != soundsList.end(); ++mapIterator) {
		delete (*mapIterator).second;
	}

	soundsList.clear();
}

void ResourcesManager::InitializeAllSoundsByPath(const char* parSoundPath) {
	DIR* directory;
	struct dirent *direntPointer;
	std::string soundName;

	if((directory = opendir(parSoundPath)) == NULL) {
		throw GenericException("Error al abrir el directorio.");
	}

	while ((direntPointer = readdir(directory)) != NULL) {
		if (direntPointer->d_type == File) {
			std::string fullName = parSoundPath;
			fullName.append("/");
			fullName.append(direntPointer->d_name);

			soundName = direntPointer->d_name;

			Sound* newSound = CreateSound(soundName, fullName.c_str());
			soundsList.insert(std::pair<std::string, Sound*>(soundName, newSound));
		}
	}

	closedir(directory);
}