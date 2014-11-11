#include "cSound.hpp"

Sound::Sound(std::string parName, std::string parPath) : soundName(parName), soundPath(parPath) {
	sound = Mix_LoadWAV(parPath.c_str());
}

Sound::~Sound() {
	Mix_FreeChunk(sound);
}