#ifndef _CRESOURCESMANAGER_HPP_
#define _CRESOURCESMANAGER_HPP_

#include "../iGlobals.hpp"

#include "Font/cFont.hpp"

class ResourcesManager {
	public:
		// Fonts
		// Por defecto, el tamaño de la fuente será de 16
		static void AddFont(std::string parFontName, const char* parFontPath, int parFontSize = 16);
		static void AddAllFontsByPath(const char* parFontPath);
		static Font* GetFont(std::string parFontName) throw(TTFException);
		static void DeleteFonts();

		// Sounds

		// Musics

		// Images


		static void OnInit(const char* parFontPath, const char* parSoundPath, const char* parMusicPath, const char* parImagePath);
		static void OnCleanUp();

		static std::string Lazy;

	private:
		enum Types {
			File = 0x8
			, Folder = 0x4
		};

		static std::map<std::string, Font*> fontsList;
};

#endif // End _CRESOURCESMANAGER_HPP_