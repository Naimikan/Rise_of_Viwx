#include "cFontManager.hpp"

FontManager* FontManager::instance = NULL;
std::string FontManager::Lazy = "lazy.ttf";

FontManager* FontManager::Initialize(const char* parFontPath) {
	if (instance == NULL) {
		instance = new FontManager(parFontPath);
	}

	return instance;
}

FontManager::FontManager(const char* parFontPath) {
	fontsList = ResourcesManager::InitializeAllFontsByPath(parFontPath);
}

FontManager::~FontManager() {
	DeleteFonts();
}

Font* FontManager::GetFont(std::string parFontName) throw(TTFException) {
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

void FontManager::DeleteFonts() {
	for (std::map<std::string, Font*>::iterator mapIterator = fontsList.begin(); mapIterator != fontsList.end(); ++mapIterator) {
		delete (*mapIterator).second;
	}

	fontsList.clear();
}
