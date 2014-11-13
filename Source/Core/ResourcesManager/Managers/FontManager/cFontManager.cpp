#include "cFontManager.hpp"

FontManager* FontManager::instance = NULL;
std::string FontManager::Lazy = "lazy.ttf";

FontManager* FontManager::Initialize(const char* parFontPath) {
	try {
		if (instance == NULL) {
			instance = new FontManager(parFontPath);
		}

		return instance;
	} catch (const TTFException& ttfException) {
		throw ttfException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

FontManager::FontManager(const char* parFontPath) {
	try {
		ResourcesManager::InitializeAllFontsByPath(parFontPath);
	} catch (const TTFException& ttfException) {
		throw ttfException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

FontManager::~FontManager() {
	ResourcesManager::DeleteFonts();
}

Font* FontManager::GetFont(std::string parFontName) {
	try {
		Font* foundFont = ResourcesManager::GetFont(parFontName);
		return foundFont;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}
