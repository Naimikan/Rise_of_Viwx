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
	fontManager = FontManager::GetInstance();
	imageManager = ImageManager::GetInstance();
	musicManager = MusicManager::GetInstance();
}

void GameState::OnActivate() {
	// Cargar recursos
	try {
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
		
		backgroundImage = imageManager->GetImage("background.bmp");
		backgroundImage->Initialize();
		
		backgroundMusic = musicManager->GetMusic("beat.wav");
		backgroundMusic->Initialize();
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

void GameState::OnDeactivate() {
	// Liberar memoria de recursos
	if (message) {
		SDL_FreeSurface(message);
	}

	message = NULL;
	
	if (lazyFont) {
		lazyFont->Uninitialize();
	}
	
	if (backgroundImage) {
		backgroundImage->Uninitialize();
	}
	
	if (backgroundMusic) {
		backgroundMusic->Uninitialize();
	}
}

void GameState::OnLoop() {
	musicManager->PlayMusic(backgroundMusic);
}

void GameState::OnRender(SDL_Surface* parSurface) {
	// Holds offsets
	SDL_Rect offset;

	// Get offsets
	offset.x = 200;
	offset.y = 150;
	
	// Blit
	if (SDL_BlitSurface(backgroundImage->GetSDL_Surface(), NULL, parSurface, NULL) == -1) {
		throw SDLException();
	}
	
	if (SDL_BlitSurface(message, NULL, parSurface, &offset) == -1) {
		throw SDLException();
	}
}
