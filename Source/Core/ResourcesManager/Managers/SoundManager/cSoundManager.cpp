#include "cSoundManager.hpp"

SoundManager* SoundManager::instance = NULL;

SoundManager* SoundManager::Initialize(const char* parSoundPath) {
	if (instance == NULL) {
		instance = new SoundManager(parSoundPath);
	}

	return instance;
}

SoundManager::SoundManager(const char* parSoundPath) {
	ResourcesManager::InitializeAllSoundsByPath(parSoundPath);
}

SoundManager::~SoundManager() {
	ResourcesManager::DeleteSounds();
}

Sound* SoundManager::GetSound(std::string parSoundName) {
	Sound* foundSound = ResourcesManager::GetSound(parSoundName);
	return foundSound;
}
