#include "cMusic.hpp"

Music::Music(std::string parName, std::string parPath) : musicName(parName), musicPath(parPath) {

}

Music::~Music() {
	Mix_FreeMusic(music);

	music = NULL;
}

void Music::Initialize() {
	music = Mix_LoadMUS(parPath.c_str());

	if (!music) {
		throw MixerException();
	}
}

void Music::Play(int parLoops) {
	if (Mix_PlayingMusic() == 0) {
		if (Mix_PlayMusic(music, parLoops) == -1) {
			throw MixerException();
		}
	}
}

void Music::Pause() {
	if (Mix_PlayingMusic() == 1) {
		if (Mix_PausedMusic() == 0) {
			Mix_PauseMusic();
		}
	}
}

void Music::Resume() {
	if (Mix_PlayingMusic() == 1) {
		if (Mix_PausedMusic() == 1) {
			Mix_ResumeMusic();
		}
	}
}

void Music::Stop() {
	Mix_HaltMusic();
}
