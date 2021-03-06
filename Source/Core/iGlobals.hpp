#ifndef _IGLOBALS_HPP_
#define _IGLOBALS_HPP_

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <exception>

#include <fstream>
#include <sstream>

// Directorios
#include <sys/types.h>
#include <dirent.h>

// Utiles
#include "Utils/cUtils.hpp"

// Logger
#include "Logger/cLogger.hpp"

// Exceptions
#include "Exception/cGenericException.hpp"

// SDL Exceptions
#include "Exception/SDLException/cSDLException.hpp"

// TTF Exceptions
#include "Exception/TTFException/cTTFException.hpp"

// Mixer Exceptions
#include "Exception/MixerException/cMixerException.hpp"

// SDL
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#endif // End _IGLOBALS_HPP_
