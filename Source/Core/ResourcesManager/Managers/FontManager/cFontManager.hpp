#ifndef _CFONTMANAGER_HPP_
#define _CFONTMANAGER_HPP_

#include "../../cResourcesManager.hpp"

class FontManager {
	public:
		static FontManager* Initialize(const char* parFontPath);
		~FontManager();

		Font* GetFont(std::string parFontName) throw(TTFException);

		static std::string Lazy;

	protected:
		FontManager(const char* parFontPath);
		//FontManager(const FontManager &);
		FontManager &operator= (const FontManager &);

	private:
		static FontManager* instance;
};

#endif // End _CFONTMANAGER_HPP_
