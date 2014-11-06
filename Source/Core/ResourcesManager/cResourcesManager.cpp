#include "cResourcesManager.hpp"

std::map<std::string, Font*> ResourcesManager::fontsList;

std::string ResourcesManager::Lazy = "lazy.ttf";

void ResourcesManager::AddFont(std::string parFontName, const char* parFontPath, int parFontSize) {
	Font* newFont = new Font(parFontName, parFontPath, parFontSize);

	if (!newFont->GetTTF_Font()) {
		throw TTFException();
	}

	fontsList.insert(std::pair<std::string, Font*>(parFontName, newFont));
}

void ResourcesManager::AddAllFontsByPath(const char* parFontPath) {
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

			if (direntPointer->d_name == ResourcesManager::Lazy) {
				fontName = ResourcesManager::Lazy;
			}

			AddFont(fontName, fullName.c_str());
		}
	}

	closedir(directory);
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

void ResourcesManager::OnCleanUp() {
	DeleteFonts();
}

void ResourcesManager::OnInit(const char* parFontPath, const char* parSoundPath, const char* parMusicPath, const char* parImagePath) {
	AddAllFontsByPath(parFontPath);
}