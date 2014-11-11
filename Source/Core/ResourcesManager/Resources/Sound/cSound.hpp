#ifndef _CSOUND_HPP_
#define _CSOUND_HPP_

#include "../../../iGlobals.hpp"

class Sound {
	public:
		Sound(std::string parName, std::string parPath);
		~Sound();

		std::string GetName() { return soundName; }
		std::string GetPath() { return soundPath; }
		Mix_Chunk* GetMix_Chunk() { return sound; }

	private:
		std::string soundName;
		std::string soundPath;
		Mix_Chunk* sound;
};

#endif // End _CSOUND_HPP_