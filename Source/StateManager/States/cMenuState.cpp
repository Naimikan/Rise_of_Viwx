#include "cMenuState.hpp"
#include "../cStateManager.hpp"

MenuState* MenuState::instance = NULL;

MenuState::MenuState() : fontManager(NULL) {
	
}

void MenuState::OnActivate() {
	// Cargar recursos
}

void MenuState::OnDeactivate() {
	// Liberar memoria de recursos
}

void MenuState::OnLoop() {

}

void MenuState::OnRender(SDL_Surface* parSurface) {
	SDL_Surface *message = NULL;

	SDL_Color textColor = { 255, 255, 255 };

	Font* lazyFont = fontManager->GetFont(FontManager::Lazy);
	lazyFont->SetStyle(TTF_STYLE_UNDERLINE);
	lazyFont->SetOutline(TTF_STYLE_BOLD);
	lazyFont->SetHinting(TTF_HINTING_NONE);
	lazyFont->SetKerning(false);
	lazyFont->SetSize(26);

	message = TTF_RenderText_Solid(lazyFont->GetTTF_Font(), "Rise of Viwx", textColor);

	if (!message) {
		throw TTFException();
	}

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

MenuState* MenuState::GetInstance() {
	if (instance == NULL) {
		instance = new MenuState();
	}

	return instance;
}