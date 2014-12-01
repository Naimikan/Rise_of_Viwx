#include "cFontManager.hpp"

FontManager* FontManager::instance = NULL;
std::string FontManager::Lazy = "lazy.ttf";

FontManager* FontManager::GetInstance() {
	if (instance == NULL) {
		instance = new FontManager();
	}

	return instance;
}

FontManager::FontManager() {
	
}

FontManager::~FontManager() {
	ResourcesManager::DeleteFonts();
}

void FontManager::Initialize(const char* parFontPath) {
	try {
		ResourcesManager::InitializeAllFontsByPath(parFontPath);
	} catch (const TTFException& ttfException) {
		throw ttfException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

Font FontManager::GetFont(std::string parFontName) {
	try {
		Font foundFont = ResourcesManager::GetFont(parFontName);
		return foundFont;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}
