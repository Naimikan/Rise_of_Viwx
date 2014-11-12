#ifndef _CMUSICMANAGER_HPP_
#define _CMUSICMANAGER_HPP_

#include "../../cResourcesManager.hpp"

class MusicManager {
	public:
		static MusicManager* Initialize(const char* parMusicPath);
		~MusicManager();

		Music* GetMusic(std::string parMusicPath);
		void PlayMusic(Music* parMusic, int parLoops = -1);
		void PauseMusic(Music* parMusic);
		void ResumeMusic(Music* parMusic);
		void StopMusic(Music* parMusic);

	protected:
		MusicManager(const char* parMusicPath);
		//MusicManager(const MusicManager &);;
		MusicManager &operator= (const MusicManager &);

	private:
		static MusicManager* instance;
};

#endif // End _CMUSICMANAGER_HPP_