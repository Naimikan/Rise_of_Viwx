#ifndef _CRESOURCESMANAGER_HPP_
#define _CRESOURCESMANAGER_HPP_

#include "../iGlobals.hpp"

#include "Font/cFont.hpp"

class ResourcesManager {
	public:
		static void AddFont(std::string parFontName, const char* parFontPath, int parFontSize);
		static void AddAllFontsByPath(const char* parFontPath);

		static Font* GetFont(std::string parFontName) throw(TTFException);

		static void DeleteFonts();

		static std::string Lazy;

	private:
		enum Types {
			File = 0x8
			, Folder = 0x4
		};

		static std::map<std::string, Font*> fontsList;
};

#endif // End _CRESOURCESMANAGER_HPP_