#include "cApplication.hpp"

Application::Application() : isRunning(true), screen(NULL) {

}

int Application::OnExecute() {
	try {
		OnInit();
		
		while (isRunning) {
			while (SDL_PollEvent(&eventHandled)) {
				OnEvent(&eventHandled);
			}
			
			OnLoop();
			OnRender();
		}
		
		OnCleanUp();
	} catch (const SDLException& sdlException) {
		std::string finalMessage;
		finalMessage.append("<SDL Error>");
		finalMessage.append(" => ");
		finalMessage.append(sdlException.WhatHappens());

		Logger::WriteMessageInLogFile(finalMessage.c_str());
		return -1;
	} catch (const TTFException& ttfException) {
		std::string finalMessage;
		finalMessage.append("<TTF Error>");
		finalMessage.append(" => ");
		finalMessage.append(ttfException.WhatHappens());

		Logger::WriteMessageInLogFile(finalMessage.c_str());
		return -1;
	} catch (const GenericException& exception) {
		Logger::WriteMessageInLogFile(exception.WhatHappens());
		return -1;
	}
	
	return 0;
}

bool Application::OnInit() throw(GenericException) {
	int windowWidth, windowHeight, windowBPP, windowFullScreen;
	windowWidth = windowHeight = windowBPP = windowFullScreen = 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		throw SDLException();
	}

	SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

	SettingsCreator::ConfigureSettingsFile();
	
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

	// Initialize SDL_ttf
	if (TTF_Init() == -1) {
		throw TTFException();
	}

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

	int audioRate, audioChannels, audioBuffers;
	audioRate = audioChannels = audioBuffers = 0;
	
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
		} else if (pairItem.first == "Audio Channels") {
			audioChannels = atoi(pairItem.second.c_str());
		} else if (pairItem.first == "Audio Buffers") {
			audioBuffers = atoi(pairItem.second.c_str());
		}
	}

	// Initialize SDL_mixer
	if (Mix_OpenAudio(audioRate, audioFormat, audioChannels, audioBuffers) == -1) {
		throw MixerException();
	}

	ResourcesManager::OnInit(fontsPath.c_str(), soundsPath.c_str(), musicsPath.c_str(), imagesPath.c_str());

	return true;
}

void Application::OnLoop() {
	
}

void Application::OnRender() {
	// Increiblemente importante
	// Limpiar la pantalla de "suciedad"
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

	SDL_Surface *message = NULL;

	SDL_Color textColor = { 255, 255, 255 };

	Font* lazyFont = ResourcesManager::GetFont(ResourcesManager::Lazy);
	lazyFont->SetStyle(TTF_STYLE_UNDERLINE);
	lazyFont->SetOutline(TTF_STYLE_BOLD);
	lazyFont->SetHinting(TTF_HINTING_NONE);
	lazyFont->SetKerning(false);
	lazyFont->SetSize(26);

	message = TTF_RenderText_Solid(lazyFont->GetTTF_Font(), "Rise of Viwx", textColor);

	//Holds offsets
	SDL_Rect offset;
	//Get offsets
	offset.x = 200;
	offset.y = 150;
	//Blit
	SDL_BlitSurface(message, NULL, screen, &offset);
	
	SDL_Flip(screen);
}

void Application::OnExit() {
	isRunning = false;
}

void Application::OnEvent(SDL_Event* parEvent) {
	Event::OnEvent(parEvent);
}

void Application::OnCleanUp() {
	ResourcesManager::OnCleanUp();
	SettingsCreator::OnCleanUp();

	SDL_FreeSurface(screen);

	//Mix_CloseAudio(); // Close SDL_mixer
	TTF_Quit(); // Close SDL_ttf
	SDL_Quit(); // Close SDL
}

void Application::OnKeyDown(SDLKey parSym, SDLMod parMod, Uint16 parUnicode) {
	switch(parSym) {
		case SDLK_ESCAPE: 
			OnExit();
			break;
			
		default: { }
	}
}
