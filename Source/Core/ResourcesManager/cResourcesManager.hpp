#ifndef _CRESOURCESMANAGER_HPP_
#define _CRESOURCESMANAGER_HPP_

#include "../iGlobals.hpp"

#include "Font/cFont.hpp"

class ResourcesManager {
	public:
		// Fonts
		// Por defecto, el tamaño de la fuente será de 16
		static Font* CreateFont(std::string parFontName, const char* parFontPath, int parFontSize = 16);
		static std::map<std::string, Font*> InitializeAllFontsByPath(const char* parFontPath);

		// Sounds

		// Musics

		// Images

	private:
		enum Types {
			File = 0x8
			, Folder = 0x4
		};
};

#endif // End _CRESOURCESMANAGER_HPP_