#include "cResourcesManager.hpp"

Font* ResourcesManager::CreateFont(std::string parFontName, const char* parFontPath, int parFontSize) {
	Font* newFont = new Font(parFontName, parFontPath, parFontSize);

	if (!newFont->GetTTF_Font()) {
		throw TTFException();
	}

	return newFont;
}

std::map<std::string, Font*> ResourcesManager::InitializeAllFontsByPath(const char* parFontPath) {
	std::map<std::string, Font*> fontsList;

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
			fontsList.insert(std::pair<std::string, Font*>(parFontName, newFont));
			delete newFont;
		}
	}

	closedir(directory);

	return fontsList;
}