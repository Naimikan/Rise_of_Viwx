#include "cGameState.hpp"
#include "../../cStateManager.hpp"

GameState* GameState::instance = NULL;

GameState* GameState::GetInstance() {
	if (instance == NULL) {
		instance = new GameState();
	}

	return instance;
}

GameState::GameState() {
	
}

void GameState::OnActivate() {
	// Cargar recursos
	fontManager = FontManager::GetInstance();
	lazyFont = fontManager->GetFont(FontManager::Lazy);
	lazyFont->Initialize();
	
	SDL_Color textColor = {255, 255, 255};
	
	lazyFont->SetStyle(TTF_STYLE_UNDERLINE);
	lazyFont->SetOutline(TTF_STYLE_BOLD);
	lazyFont->SetHinting(TTF_HINTING_NONE);
	lazyFont->SetKerning(false);
	lazyFont->SetSize(26);

	message = TTF_RenderText_Solid(lazyFont->GetTTF_Font(), "GameState", textColor);

	if (!message) {
		throw TTFException();
	}
}

void GameState::OnDeactivate() {
	// Liberar memoria de recursos
	if (message) {
		SDL_FreeSurface(message);
	}

	message = NULL;
}

void GameState::OnLoop() {

}

void GameState::OnRender(SDL_Surface* parSurface) {
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
