#include "cFont.hpp"

Font::Font() {
	
}

Font::Font(std::string parName, std::string parPath, int parSize) : fontName(parName), fontPath(parPath), fontSize(parSize) {
	
}

Font::Font(const Font &parFont) : fontName(parFont.fontName), fontPath(parFont.fontPath), fontSize(parFont.fontSize) {

}

Font::~Font() {
	Uninitialize();
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
	font = TTF_OpenFont(fontPath.c_str(), fontSize);

	if (!font) {
		throw TTFException();
	}
}

void Font::Uninitialize() {
	TTF_CloseFont(font);

	font = NULL;
}