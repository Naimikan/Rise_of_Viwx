#ifndef _CSOUND_HPP_
#define _CSOUND_HPP_

#include "../../../iGlobals.hpp"

class Sound {
	public:
		Sound(std::string parName, std::string parPath);
		~Sound();

		void Initialize();

		void Play(int parLoops, int parChannel);
		void Pause();
		void Resume();
		void Stop();

		std::string GetName() { return soundName; }
		std::string GetPath() { return soundPath; }
		int GetChannel() { return soundChannel; }
		Mix_Chunk* GetMix_Chunk() { return sound; }

	private:
		std::string soundName;
		std::string soundPath;
		int soundChannel;
		Mix_Chunk* sound;
};

#endif // End _CSOUND_HPP_
