#include "cSound.hpp"

// Callback
void SoundEnd(int parChannel) {
	std::cout << "Finished channel: " << parChannel << std::endl;
}

Sound::Sound(std::string parName, std::string parPath) : soundName(parName), soundPath(parPath), soundChannel(0) {
	sound = Mix_LoadWAV(parPath.c_str());

	if (!sound) {
		throw MixerException();
	}
}

Sound::~Sound() {
	while(Mix_Playing(soundChannel) != 0);

	Mix_FreeChunk(sound);

	sound = NULL;
}

void Sound::Play(int parLoops, int parChannel) {
	soundChannel = Mix_PlayChannel(parChannel, sound, parLoops);

	std::cout << "Sound channel: " << soundChannel << std::endl;

	if (soundChannel == -1) {
		throw MixerException();
	}
	
	Mix_ChannelFinished(SoundEnd);
}
