#include "cApplication.hpp"

Application::Application() : isRunning(true), screen(NULL) {

}

int Application::OnExecute() {
	std::string finalMessage;
	
	try {
		Timer fpsManager;

		OnInit();
		
		while (isRunning) {
			fpsManager.Start();

			while (SDL_PollEvent(&eventHandled)) {
				OnEvent(&eventHandled);
			}
			
			OnLoop();
			OnRender();

			fpsManager.FrameRate();
		}
		
		OnCleanUp();
	} catch (const SDLException& sdlException) {
		finalMessage.append("<SDL Error>");
		finalMessage.append(" => ");
		finalMessage.append(sdlException.WhatHappens());

		Logger::WriteMessageInLogFile(finalMessage.c_str());
		return -1;
	} catch (const TTFException& ttfException) {
		finalMessage.append("<TTF Error>");
		finalMessage.append(" => ");
		finalMessage.append(ttfException.WhatHappens());

		Logger::WriteMessageInLogFile(finalMessage.c_str());
		return -1;
	} catch (const MixerException& mixerException) {
		finalMessage.append("<Mixer Error>");
		finalMessage.append(" => ");
		finalMessage.append(mixerException.WhatHappens());

		Logger::WriteMessageInLogFile(finalMessage.c_str());
		return -1;
	} catch (const GenericException& exception) {
		Logger::WriteMessageInLogFile(exception.WhatHappens());
		return -1;
	}
	
	return 0;
}

bool Application::OnInit() {
	std::string textException = "OnInit() => ";
	
	try {
		SettingsCreator::ConfigureSettingsFile();

		InitializeSDLSystem();
		InitializeVideoSystem();
		InitializeTTFSystem();
		InitializeAudioSystem();
		InitializeResources();

		StateManager::SetActiveState(STATE_MENU);

		return true;
	} catch (const SDLException& sdlException) {
		textException.append(sdlException.WhatHappens());

		throw SDLException(textException);
	} catch (const TTFException& ttfException) {
		textException.append(ttfException.WhatHappens());

		throw TTFException(textException);
	} catch (const MixerException& mixerException) {
		textException.append(mixerException.WhatHappens());

		throw MixerException(textException);
	} catch (const GenericException& exception) {
		textException.append(exception.WhatHappens());

		throw GenericException(textException);
	}

	return false;
}

void Application::OnLoop() {
	StateManager::OnLoop();
}

void Application::OnRender() {
	try {
		// Increiblemente importante
		// Limpiar la pantalla de "suciedad"
		if (SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0)) == -1) {
			throw SDLException();
		}

		StateManager::OnRender(screen);
		
		if (SDL_Flip(screen) == -1) {
			throw SDLException();
		}
	} catch (const SDLException& sdlException) {
		throw sdlException;
	} catch (const TTFException& ttfException) {
		throw ttfException;
	}
}

void Application::OnExit() {
	isRunning = false;
}

void Application::OnEvent(SDL_Event* parEvent) {
	EventListener::OnEvent(parEvent);

	StateManager::OnEvent(parEvent);
}

void Application::OnCleanUp() {
	StateManager::SetActiveState(STATE_NONE);
	SettingsCreator::OnCleanUp();

	SDL_FreeSurface(screen);

	Mix_CloseAudio(); // Close SDL_mixer
	TTF_Quit(); // Close SDL_ttf
	SDL_Quit(); // Close SDL
}

void Application::OnKeyDown(SDLKey parSym, SDLMod parMod, Uint16 parUnicode) {
	switch(parSym) {
		case SDLK_ESCAPE: OnExit(); break;
		case SDLK_h:
			StateManager::SetActiveState(STATE_MENU);
			break;
		case SDLK_j:
			StateManager::SetActiveState(STATE_GAME);
			break;
		default: { };
	}
}

void Application::InitializeSDLSystem() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		throw SDLException();
	}

	if (SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3) == -1) {
		throw SDLException();
	}
}

void Application::InitializeVideoSystem() {
	int windowWidth, windowHeight, windowBPP, windowFullScreen;
	windowWidth = windowHeight = windowBPP = windowFullScreen = 0;
	
	std::map<std::string, std::string> resolutionSection = SettingsCreator::GetSettingsBySection("Resolution");

	for (std::map<std::string, std::string>::iterator mapIterator = resolutionSection.begin(); mapIterator != resolutionSection.end(); ++mapIterator) {
		std::pair<std::string, std::string> pairItem = (*mapIterator);

		if (pairItem.first == "Width") {
			windowWidth = atoi(pairItem.second.c_str());
		} else if (pairItem.first == "Height") {
			windowHeight = atoi(pairItem.second.c_str());
		} else if (pairItem.first == "BPP") {
			windowBPP = atoi(pairItem.second.c_str());
		} else if (pairItem.first == "FullScreen") {
			windowFullScreen = atoi(pairItem.second.c_str());
		}
	}

	Uint32 flags = SDL_HWSURFACE | SDL_DOUBLEBUF;

	if (windowFullScreen == 1) {
		flags = flags | SDL_FULLSCREEN;
	}

	if ((screen = SDL_SetVideoMode(windowWidth, windowHeight, windowBPP, flags)) == NULL) {
		throw SDLException();
	}

	std::string applicationName, version;
	applicationName = version = "";

	std::map<std::string, std::string> otherSection = SettingsCreator::GetSettingsBySection("Other Settings");

	for (std::map<std::string, std::string>::iterator mapIterator = otherSection.begin(); mapIterator != otherSection.end(); ++mapIterator) {
		std::pair<std::string, std::string> pairItem = (*mapIterator);

		if (pairItem.first == "Application Name") {
			applicationName = pairItem.second;
		} else if (pairItem.first == "Version") {
			version = pairItem.second;
		}
	}

	// Set the window caption
	std::string caption;
	caption.append(applicationName);
	caption.append(" v. ");
	caption.append(version);

	SDL_WM_SetCaption(caption.c_str(), NULL);
}

void Application::InitializeAudioSystem() {
	int audioRate, audioType, audioBuffers, audioChannels;
	audioRate = audioType = audioBuffers = audioChannels = 0;
	
	Uint16 audioFormat = 0;

	std::map<std::string, std::string> audioSettingsSection = SettingsCreator::GetSettingsBySection("Audio Settings");

	for (std::map<std::string, std::string>::iterator mapIterator = audioSettingsSection.begin(); mapIterator != audioSettingsSection.end(); ++mapIterator) {
		std::pair<std::string, std::string> pairItem = (*mapIterator);

		if (pairItem.first == "Audio Rate") {
			audioRate = atoi(pairItem.second.c_str());
		} else if (pairItem.first == "Audio Format") {
			int tempAudioFormat = atoi(pairItem.second.c_str());
			
			switch (tempAudioFormat) {
				case 1: audioFormat = AUDIO_U8; break;
				case 2: audioFormat = AUDIO_S8; break;
				case 3: audioFormat = AUDIO_U16LSB; break;
				case 4: audioFormat = AUDIO_S16LSB; break;
				case 5: audioFormat = AUDIO_U16MSB; break;
				case 6: audioFormat = AUDIO_S16MSB; break;
				case 7: audioFormat = AUDIO_U16; break;
				case 8: audioFormat = AUDIO_S16; break;
				case 9: audioFormat = AUDIO_U16SYS; break;
				case 10: audioFormat = AUDIO_S16SYS; break;
				case 11: audioFormat = MIX_DEFAULT_FORMAT; break;
			}
		} else if (pairItem.first == "Audio Type") {
			audioType = atoi(pairItem.second.c_str());
		} else if (pairItem.first == "Audio Buffers") {
			audioBuffers = atoi(pairItem.second.c_str());
		} else if (pairItem.first == "Audio Channels") {
			audioChannels = atoi(pairItem.second.c_str());
		}
	}

	// Initialize SDL_mixer
	if (Mix_OpenAudio(audioRate, audioFormat, audioType, audioBuffers) == -1) {
		throw MixerException();
	}
	
	// Allocate Channels
	Mix_AllocateChannels(audioChannels);
}

void Application::InitializeTTFSystem() {
	// Initialize SDL_ttf
	if (TTF_Init() == -1) {
		throw TTFException();
	}
}

void Application::InitializeResources() {
	std::string fontsPath, soundsPath, musicsPath, imagesPath;
	fontsPath = soundsPath = musicsPath = imagesPath = "";

	std::map<std::string, std::string> mediaRoutesSection = SettingsCreator::GetSettingsBySection("Media Routes");

	for (std::map<std::string, std::string>::iterator mapIterator = mediaRoutesSection.begin(); mapIterator != mediaRoutesSection.end(); ++mapIterator) {
		std::pair<std::string, std::string> pairItem = (*mapIterator);

		if (pairItem.first == "Fonts") {
			fontsPath = pairItem.second;
		} else if (pairItem.first == "Musics") {
			musicsPath = pairItem.second;
		} else if (pairItem.first == "Sounds") {
			soundsPath = pairItem.second;
		} else if (pairItem.first == "Images") {
			imagesPath = pairItem.second;
		}
	}

	// Initialize Managers
	try {
		FontManager::GetInstance()->Initialize(fontsPath.c_str());
		ImageManager::GetInstance()->Initialize(imagesPath.c_str());
		SoundManager::GetInstance()->Initialize(soundsPath.c_str());
		MusicManager::GetInstance()->Initialize(musicsPath.c_str());
	} catch (const SDLException& sdlException) {
		throw sdlException;
	} catch (const TTFException& ttfException) {
		throw ttfException;
	} catch (const MixerException& mixerException) {
		throw mixerException;
	} catch (const GenericException& genericException) {
		throw genericException;
	}
}
