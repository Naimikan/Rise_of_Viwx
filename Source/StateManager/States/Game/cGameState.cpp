#include "cGameState.hpp"
#include "../../cStateManager.hpp"

GameState* GameState::instance = NULL;

GameState* GameState::GetInstance() {
	if (instance == NULL) {
		instance = new GameState();
	}

	return instance;
}

GameState::GameState() : fontManager(NULL) {
	
}

void GameState::OnActivate() {
	// Cargar recursos
	fontManager = FontManager::GetInstance();
}

void GameState::OnDeactivate() {
	// Liberar memoria de recursos
}

void GameState::OnLoop() {

}

void GameState::OnRender(SDL_Surface* parSurface) {
	SDL_Surface *message = NULL;

	SDL_Color textColor = { 255, 255, 255 };

	Font* lazyFont = fontManager->GetFont(FontManager::Lazy);
	lazyFont->Initialize();
	
	lazyFont->SetStyle(TTF_STYLE_UNDERLINE);
	lazyFont->SetOutline(TTF_STYLE_BOLD);
	lazyFont->SetHinting(TTF_HINTING_NONE);
	lazyFont->SetKerning(false);
	lazyFont->SetSize(26);

	message = TTF_RenderText_Solid(lazyFont->GetTTF_Font(), "GameState", textColor);

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
