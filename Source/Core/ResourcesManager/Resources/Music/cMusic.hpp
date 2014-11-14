#ifndef _CMUSIC_HPP_
#define _CMUSIC_HPP_

#include "../../../iGlobals.hpp"

class Music {
	public:
		Music(std::string parName, std::string parPath);
		~Music();

		void Initialize();

		void Play(int parLoops);
		void Pause();
		void Resume();
		void Stop();

		std::string GetName() { return musicName; }
		std::string GetPath() { return musicPath; }
		Mix_Music* GetMix_Music() { return music; }

	private:
		std::string musicName;
		std::string musicPath;
		Mix_Music* music;
};

#endif // End _CMUSIC_HPP_