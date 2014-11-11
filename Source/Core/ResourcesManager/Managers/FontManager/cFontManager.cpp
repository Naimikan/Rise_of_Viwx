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
	ResourcesManager::InitializeAllFontsByPath(parFontPath);
}

FontManager::~FontManager() {
	ResourcesManager::DeleteFonts();
}

Font* FontManager::GetFont(std::string parFontName) {
	Font* foundFont = ResourcesManager::GetFont(parFontName);
	return foundFont;
}
