#include "cMenuState.hpp"
#include "../../cStateManager.hpp"

MenuState* MenuState::instance = NULL;

MenuState* MenuState::GetInstance() {
	if (instance == NULL) {
		instance = new MenuState();
	}

	return instance;
}

MenuState::MenuState() {
	
}

void MenuState::OnActivate() {
	try {
		// Cargar recursos
		fontManager = FontManager::GetInstance();
		lazyFont = new Font(fontManager->GetFont(FontManager::Lazy));
		lazyFont->Initialize();
		
		SDL_Color textColor = {255, 255, 255};
		
		lazyFont->SetStyle(TTF_STYLE_UNDERLINE);
		lazyFont->SetOutline(TTF_STYLE_BOLD);
		lazyFont->SetHinting(TTF_HINTING_NONE);
		lazyFont->SetKerning(false);
		lazyFont->SetSize(26);

		message = TTF_RenderText_Solid(lazyFont->GetTTF_Font(), "MenuState", textColor);

		if (!message) {
			throw TTFException();
		}
	} catch (const TTFException& ttfException) {
		throw ttfException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

void MenuState::OnDeactivate() {
	// Liberar memoria de recursos
	if (message) {
		SDL_FreeSurface(message);
	}

	message = NULL;

	delete lazyFont;
}

void MenuState::OnLoop() {

}

void MenuState::OnRender(SDL_Surface* parSurface) {
	//Holds offsets
	SDL_Rect offset;
	
	//Get offsets
	offset.x = 200;
	offset.y = 150;

	//Blit
	if (SDL_BlitSurface(message, NULL, parSurface, &offset) == -1) {
		throw SDLException();
	}
}
