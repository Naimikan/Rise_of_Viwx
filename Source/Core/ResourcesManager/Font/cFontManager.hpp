#ifndef _CFONTMANAGER_HPP_
#define _CFONTMANAGER_HPP_

#include "cFont.hpp"
#include "../cResourcesManager.hpp"

class FontManager {
	public:
		static FontManager* Initialize(const char* parFontPath);
		virtual ~FontManager();

		Font* GetFont(std::string parFontName) throw(TTFException);
		void DeleteFonts();

		static std::string Lazy;

	protected:
		FontManager(const char* parFontPath);
		//FontManager(const FontManager &) ;
		FontManager &operator= (const FontManager &);

	private:
		static FontManager* instance;

		std::map<std::string, Font*> fontsList;
};

#endif // End _CFONTMANAGER_HPP_
