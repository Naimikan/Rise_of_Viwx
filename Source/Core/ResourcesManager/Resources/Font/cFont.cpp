#include "cFont.hpp"

Font::Font(std::string parName, std::string parPath, int parSize) : fontName(parName), fontPath(parPath), fontSize(parSize) {
	font = TTF_OpenFont(parPath.c_str(), parSize);
}

Font::~Font() {
	TTF_CloseFont(font);
}

void Font::SetSize(int parNewSize) {
	fontSize = parNewSize;

	TTF_Font* newFont = TTF_OpenFont(fontPath.c_str(), parNewSize);

	TTF_CloseFont(font);

	font = newFont;
}