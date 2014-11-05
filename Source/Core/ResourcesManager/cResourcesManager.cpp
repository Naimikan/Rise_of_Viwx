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

	int defaultFontSize = 16;

	if((directory = opendir(parFontPath)) == NULL) {
		throw GenericException("Error al abrir el directorio.");
	}

	while ((direntPointer = readdir(directory)) != NULL) {
		if (direntPointer->d_type == File) {
			std::string fullName = parFontPath;
			fullName.append("/");
			fullName.append(direntPointer->d_name);

			// Caca C++, no deja hacer switch de strings
			if (direntPointer->d_name == ResourcesManager::Lazy) {
				fontName = ResourcesManager::Lazy;
			}

			AddFont(fontName, fullName.c_str(), defaultFontSize);
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

	return (fontsList.find(parFontName)->second);
}

void ResourcesManager::DeleteFonts() {
	for (std::map<std::string, Font*>::iterator mapIterator = fontsList.begin(); mapIterator != fontsList.end(); ++mapIterator) {
		delete (*mapIterator).second;
	}

	fontsList.clear();
}

