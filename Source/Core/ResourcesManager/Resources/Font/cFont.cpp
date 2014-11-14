#include "cFont.hpp"

Font::Font(std::string parName, std::string parPath, int parSize) : fontName(parName), fontPath(parPath), fontSize(parSize) {
	
}

Font::~Font() {
	TTF_CloseFont(font);

	font = NULL;
}

void Font::SetSize(int parNewSize) {
	fontSize = parNewSize;

	TTF_Font* newFont = TTF_OpenFont(fontPath.c_str(), parNewSize);

	if (!newFont) {
		throw TTFException();
	} else {
		TTF_CloseFont(font);

		font = newFont;
	}
}

void Font::Initialize() {
	font = TTF_OpenFont(parPath.c_str(), parSize);

	if (!font) {
		throw TTFException();
	}
}