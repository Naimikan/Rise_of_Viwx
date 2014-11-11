#ifndef _CRESOURCESMANAGER_HPP_
#define _CRESOURCESMANAGER_HPP_

#include "../iGlobals.hpp"

#include "Resources/Font/cFont.hpp"
#include "Resources/Image/cImage.hpp"
#include "Resources/Sound/cSound.hpp"

class ResourcesManager {
	public:
		// Fonts
		// Por defecto, el tamaño de la fuente será de 16
		static Font* CreateFont(std::string parFontName, const char* parFontPath, int parFontSize = 16);
		static Font* GetFont(std::string parFontName);
		static void DeleteFonts();
		static void InitializeAllFontsByPath(const char* parFontPath);

		// Sounds
		static Sound* CreateSound(std::string parSoundName, const char* parSoundPath);
		static Sound* GetSound(std::string parSoundName);
		static void DeleteSounds();
		static void InitializeAllSoundsByPath(const char* parSoundPath);

		// Musics

		// Images
		static Image* CreateImage(std::string parImageName, const char* parImagePath);
		static Image* GetImage(std::string parImageName);
		static void DeleteImages();
		static void InitializeAllImagesByPath(const char* parImagePath);

	private:
		enum Types {
			File = 0x8
			, Folder = 0x4
		};
		
		static std::map<std::string, Font*> fontsList;
		static std::map<std::string, Image*> imagesList;
		static std::map<std::string, Sound*> soundsList;
};

#endif // End _CRESOURCESMANAGER_HPP_
