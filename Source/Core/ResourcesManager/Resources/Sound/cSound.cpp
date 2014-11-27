#include "cSound.hpp"

// Callback
void SoundEnd(int parChannel) {
	std::cout << "Finished channel: " << parChannel << std::endl;
}

Sound::Sound(std::string parName, std::string parPath) : soundName(parName), soundPath(parPath), soundChannel(-1) {

}

Sound::~Sound() {
	Uninitialize();
}

void Sound::Initialize() {
	sound = Mix_LoadWAV(soundPath.c_str());

	if (!sound) {
		throw MixerException();
	}
}

void Sound::Uninitialize() {
	// Check if works
	//Mix_HaltChannel(soundChannel);

	while(Mix_Playing(soundChannel) != 0);

	Mix_FreeChunk(sound);

	sound = NULL;
}

void Sound::Play(int parLoops, int parChannel) {
	if (soundChannel > -1) {
		if (Mix_Playing(soundChannel) == 0) {
			soundChannel = Mix_PlayChannel(soundChannel, sound, parLoops);
		}
	} else {
		soundChannel = Mix_PlayChannel(parChannel, sound, parLoops);
	}

	std::cout << "Sound channel: " << soundChannel << std::endl;

	if (soundChannel == -1) {
		throw MixerException();
	}
	
	Mix_ChannelFinished(SoundEnd);
}

void Sound::Pause() {
	if (Mix_Playing(soundChannel) == 1) {
		if (Mix_Paused(soundChannel) == 0) {
			Mix_Pause(soundChannel);
		}
	}
}

void Sound::Resume() {
	if (Mix_Playing(soundChannel) == 1) {
		if (Mix_Paused(soundChannel) == 1) {
			Mix_Resume(soundChannel);
		}
	}
}

void Sound::Stop() {
	Mix_HaltChannel(soundChannel);
}
