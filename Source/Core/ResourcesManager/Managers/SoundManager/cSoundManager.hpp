#ifndef _CSOUNDMANAGER_HPP_
#define _CSOUNDMANAGER_HPP_

#include "../../cResourcesManager.hpp"

class SoundManager {
	public:
		static SoundManager* Initialize(const char* parSoundPath);
		~SoundManager();

		Sound* GetSound(std::string parSoundPath);

	protected:
		SoundManager(const char* parSoundPath);
		//SoundManager(const SoundManager &);
		SoundManager &operator= (const SoundManager &);

	private:
		static SoundManager* instance;
};

#endif // End _CSOUNDMANAGER_HPP_