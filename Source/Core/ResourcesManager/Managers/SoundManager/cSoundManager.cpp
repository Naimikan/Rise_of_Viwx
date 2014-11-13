#include "cSoundManager.hpp"

SoundManager* SoundManager::instance = NULL;

SoundManager* SoundManager::Initialize(const char* parSoundPath) {
	try {
		if (instance == NULL) {
			instance = new SoundManager(parSoundPath);
		}

		return instance;
	} catch (const MixerException& mixerException) {
		throw mixerException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

SoundManager::SoundManager(const char* parSoundPath) {
	try {
		ResourcesManager::InitializeAllSoundsByPath(parSoundPath);
	} catch (const MixerException& mixerException) {
		throw mixerException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

SoundManager::~SoundManager() {
	ResourcesManager::DeleteSounds();
}

Sound* SoundManager::GetSound(std::string parSoundName) {
	try {
		Sound* foundSound = ResourcesManager::GetSound(parSoundName);
		return foundSound;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

void SoundManager::PlaySound(Sound* parSound, int parLoops, int parChannel) {
	try {
		parSound->Play(parLoops, parChannel);
	} catch (const MixerException& mixerException) {
		throw mixerException;
	}
}