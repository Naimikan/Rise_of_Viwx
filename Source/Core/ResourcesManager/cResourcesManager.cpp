#include "cResourcesManager.hpp"

std::map<std::string, Font> ResourcesManager::fontsList;
std::map<std::string, Image*> ResourcesManager::imagesList;
std::map<std::string, Sound*> ResourcesManager::soundsList;
std::map<std::string, Music*> ResourcesManager::musicsList;

Font ResourcesManager::GetFont(std::string parFontName) {
	if (parFontName.empty()) {
		throw GenericException("FontName required.");
	}

	if (fontsList.empty()) {
		throw GenericException("Fonts list empty.");
	}

	std::map<std::string, Font>::const_iterator iteratorFontFound = fontsList.find(parFontName);

	if (iteratorFontFound != fontsList.end()) {
		return iteratorFontFound->second;
	} else {
		throw GenericException("Font not found.");
	}
}

void ResourcesManager::DeleteFonts() {
	/*for (std::map<std::string, Font>::iterator mapIterator = fontsList.begin(); mapIterator != fontsList.end(); ++mapIterator) {
		delete (*mapIterator).second;
	}*/

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

			Font newFont(fontName, fullName.c_str());
			fontsList.insert(std::pair<std::string, Font>(fontName, newFont));
		}
	}

	closedir(directory);
}

Image* ResourcesManager::CreateImage(std::string parImageName, const char* parImagePath) {
	try {
		Image* newImage = new Image(parImageName, parImagePath);

		return newImage;
	} catch (const SDLException& sdlException) {
		throw sdlException;
	}
}

Image* ResourcesManager::GetImage(std::string parImageName) {
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

			try {
				Image* newImage = CreateImage(imageName, fullName.c_str());
				imagesList.insert(std::pair<std::string, Image*>(imageName, newImage));
			} catch (const SDLException& sdlException) {
				throw sdlException;
			}
		}
	}

	closedir(directory);
}

Sound* ResourcesManager::CreateSound(std::string parSoundName, const char* parSoundPath) {
	try {
		Sound* newSound = new Sound(parSoundName, parSoundPath);

		return newSound;
	} catch (const MixerException& mixerException) {
		throw mixerException;
	}
}

Sound* ResourcesManager::GetSound(std::string parSoundName) {
	if (parSoundName.empty()) {
		throw GenericException("SoundName required.");
	}

	if (soundsList.empty()) {
		throw GenericException("Sounds list empty.");
	}

	std::map<std::string, Sound*>::const_iterator iteratorSoundFound = soundsList.find(parSoundName);

	if (iteratorSoundFound != soundsList.end()) {
		return iteratorSoundFound->second;
	} else {
		throw GenericException("Sound not found.");
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

			try {
				Sound* newSound = CreateSound(soundName, fullName.c_str());
				soundsList.insert(std::pair<std::string, Sound*>(soundName, newSound));
			} catch (const MixerException& mixerException) {
				throw mixerException;
			}
		}
	}

	closedir(directory);
}

Music* ResourcesManager::CreateMusic(std::string parMusicName, const char* parMusicPath) {
	try {
		Music* newMusic = new Music(parMusicName, parMusicPath);

		return newMusic;
	} catch (const MixerException& mixerException) {
		throw mixerException;
	}
}

Music* ResourcesManager::GetMusic(std::string parMusicName) {
	if (parMusicName.empty()) {
		throw GenericException("MusicName required.");
	}

	if (musicsList.empty()) {
		throw GenericException("Musics list empty.");
	}

	std::map<std::string, Music*>::const_iterator iteratorMusicFound = musicsList.find(parMusicName);

	if (iteratorMusicFound != musicsList.end()) {
		return iteratorMusicFound->second;
	} else {
		throw GenericException("Music not found.");
	}
}

void ResourcesManager::DeleteMusics() {
	for (std::map<std::string, Music*>::iterator mapIterator = musicsList.begin(); mapIterator != musicsList.end(); ++mapIterator) {
		delete (*mapIterator).second;
	}

	musicsList.clear();
}

void ResourcesManager::InitializeAllMusicsByPath(const char* parMusicPath) {
	DIR* directory;
	struct dirent *direntPointer;
	std::string musicName;

	if((directory = opendir(parMusicPath)) == NULL) {
		throw GenericException("Error al abrir el directorio.");
	}

	while ((direntPointer = readdir(directory)) != NULL) {
		if (direntPointer->d_type == File) {
			std::string fullName = parMusicPath;
			fullName.append("/");
			fullName.append(direntPointer->d_name);

			musicName = direntPointer->d_name;

			try {
				Music* newMusic = CreateMusic(musicName, fullName.c_str());
				musicsList.insert(std::pair<std::string, Music*>(musicName, newMusic));
			} catch (const MixerException& mixerException) {
				throw mixerException;
			}
		}
	}

	closedir(directory);
}
