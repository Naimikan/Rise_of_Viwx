#ifndef _CFONT_HPP_
#define _CFONT_HPP_

#include "../../../iGlobals.hpp"

class Font {
	public:
		Font(std::string parName, std::string parPath, int parSize);
		~Font();

		/*
		 * Font Style
		 *
		 * TTF_STYLE_NORMAL = 0x00
		 * TTF_STYLE_BOLD = 0x01
		 * TTF_STYLE_ITALIC = 0x02
		 * TTF_STYLE_UNDERLINE = 0x04
		 * TTF_STYLE_STRIKETHROUGH = 0x08
		 *
		 */

		int GetStyle() const { return TTF_GetFontStyle(font); }
		void SetStyle(int parNewStyle) { TTF_SetFontStyle(font, parNewStyle); }

		int GetOutline() const { return TTF_GetFontOutline(font); }
		void SetOutline(int parNewOutline) { TTF_SetFontOutline(font, parNewOutline); }

		/*
		 * Font Hinting
		 *
		 * TTF_HINTING_NORMAL = 0
		 * TTF_HINTING_LIGHT = 1
		 * TTF_HINTING_MONO = 2
		 * TTF_HINTING_NONE = 3
		 *
		 */

		int GetHinting() const { return TTF_GetFontHinting(font); }
		void SetHinting(int parNewHinting) { TTF_SetFontHinting(font, parNewHinting); }

		/*
		 * Font Kerning
		 *
		 * False = 0
		 * True = 1
		 *
		 */

		bool GetKerning() const { return (TTF_GetFontKerning(font) > 0); }
		void SetKerning(bool parKerning) { if (parKerning) { TTF_SetFontKerning(font, 1); } else { TTF_SetFontKerning(font, 0); } }

		int GetSize() const { return fontSize; }
		void SetSize(int parNewSize);

		std::string GetName() { return fontName; }
		std::string GetPath() { return fontPath; }
		TTF_Font* GetTTF_Font() { return font; }

	private:
		TTF_Font* font;
		std::string fontName;
		std::string fontPath;
		int fontSize;
};

#endif // End _CFONT_HPP_
