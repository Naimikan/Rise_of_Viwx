#include "cMusicManager.hpp"

MusicManager* MusicManager::instance = NULL;

MusicManager* MusicManager::Initialize(const char* parMusicPath) {
	try {
		if (instance == NULL) {
			instance = new MusicManager(parMusicPath);
		}

		return instance;
	} catch (const MixerException& mixerException) {
		throw mixerException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

MusicManager::MusicManager(const char* parMusicPath) {
	try {
		ResourcesManager::InitializeAllMusicsByPath(parMusicPath);
	} catch (const MixerException& mixerException) {
		throw mixerException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

MusicManager::~MusicManager() {
	ResourcesManager::DeleteMusics();
}

Music* MusicManager::GetMusic(std::string parMusicName) {
	try {
		Music* foundMusic = ResourcesManager::GetMusic(parMusicName);
		return foundMusic;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}

void MusicManager::PlayMusic(Music* parMusic, int parLoops) {
	try {
		parMusic->Play(parLoops);
	} catch (const MixerException& mixerException) {
		throw mixerException;
	}
}

void MusicManager::PauseMusic(Music* parMusic) {
	parMusic->Pause();
}

void MusicManager::ResumeMusic(Music* parMusic) {
	parMusic->Resume();
}

void MusicManager::StopMusic(Music* parMusic) {
	parMusic->Stop();
}
