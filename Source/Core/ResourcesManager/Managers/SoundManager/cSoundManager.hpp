#ifndef _CSOUNDMANAGER_HPP_
#define _CSOUNDMANAGER_HPP_

#include "../../cResourcesManager.hpp"

class SoundManager {
	public:
		static SoundManager* GetInstance();
		~SoundManager();

		void Initialize(const char* parSoundPath);

		Sound* GetSound(std::string parSoundPath);
		void PlaySound(Sound* parSound, int parLoops = 0, int parChannel = -1);

	protected:
		SoundManager();
		//SoundManager(const SoundManager &);
		SoundManager &operator= (const SoundManager &);

	private:
		static SoundManager* instance;
};

#endif // End _CSOUNDMANAGER_HPP_
