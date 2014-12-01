#ifndef _CFONTMANAGER_HPP_
#define _CFONTMANAGER_HPP_

#include "../../cResourcesManager.hpp"

class FontManager {
	public:
		static FontManager* GetInstance();
		~FontManager();

		Font GetFont(std::string parFontName);
		void Initialize(const char* parFontPath);

		static std::string Lazy;

	protected:
		FontManager();
		//FontManager(const FontManager &);
		FontManager &operator= (const FontManager &);

	private:
		static FontManager* instance;
};

#endif // End _CFONTMANAGER_HPP_
