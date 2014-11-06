#include "cSettingsCreator.hpp"

SettingsCreator::ConfigStruct SettingsCreator::configStructSearcherFilter = SettingsCreator::ConfigStruct();

std::string SettingsCreator::configFileName;
std::ofstream SettingsCreator::configFile;

std::vector<SettingsCreator::ConfigStruct> SettingsCreator::configFileValues;

void SettingsCreator::OnCleanUp() {
	configFileValues.clear();
}

void SettingsCreator::OpenFile(const std::string& parFileName) throw(GenericException) {
	//configFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);

	configFile.open(parFileName.c_str());
	configFile.clear();

	configFileName = parFileName;

}

void SettingsCreator::CloseFile() {
    configFile.close();
}

void SettingsCreator::PutSection(const std::string& parSection) {
	configFile << "[" << parSection << "]" << std::endl;
}

void SettingsCreator::PutValue(const std::string& parSection, const std::string& parKey, const std::string& parValue) {
	configFile << parKey << "=" << parValue << std::endl;

	ConfigStruct configStruct;

	bool sectionFound = false;

	unsigned int iterator = 0;
	while (!sectionFound && iterator < configFileValues.size()) {
		if (configFileValues[iterator].Section == parSection) {
			sectionFound = true;
		} else {
			iterator++;
		}
	}

	if (sectionFound) {
		// Si se ha encontrado, se añaden las opciones al hashmap
		configFileValues[iterator].Values.insert(std::pair<std::string, std::string>(parKey, parValue));
	} else {
		// Si no se ha encontrado, es una sección nueva y se añade
		configStruct.Section = parSection;
		configStruct.Values.insert(std::pair<std::string, std::string>(parKey, parValue));

		configFileValues.push_back(configStruct);
	}
}

void SettingsCreator::PutComment(const std::string& parComment) {
	configFile << "# " << parComment << std::endl;
}

void SettingsCreator::PutBlankLine() {
	configFile << std::endl;
}

void SettingsCreator::ConfigureSettingsFile() {
	if (!ExistConfigFile("./Settings.cfg")) {
		OpenFile("./Settings.cfg");

		PutSection("Resolution");
		PutValue("Resolution", "Width", "640");
		PutValue("Resolution", "Height", "480");
		PutValue("Resolution", "BPP", "32");
		PutComment("FullScreen (0 = false, 1 = true)");
		PutValue("Resolution", "FullScreen", "0");

		PutBlankLine();

		PutSection("Media Routes");
		PutValue("Media Routes", "Sounds", "./Media/Sounds");
		PutValue("Media Routes", "Musics", "./Media/Musics");
		PutValue("Media Routes", "Images", "./Media/Images");
		PutValue("Media Routes", "Fonts", "./Media/Fonts");

		PutBlankLine();

		PutSection("Audio Settings");
		/*
			11025 - Calidad baja
			22050 - Calidad media
			44100 - Calidad alta
		*/
		PutValue("Audio Settings", "Audio Rate", "44100");

		/*
        	1 - AUDIO_U8 - Unsigned 8-bit samples
        	2 - AUDIO_S8 - Signed 8-bit samples
        	3 - AUDIO_U16LSB - Unsigned 16-bit samples in little-endian byte order
        	4 - AUDIO_S16LSB - Signed 16-bit samples in little-endian byte order
        	5 - AUDIO_U16MSB - Unsigned 16-bit samples in big-endian byte order
        	6 - AUDIO_S16MSB - Signed 16-bit samples in big-endian byte order
        	7 - AUDIO_U16 - Same as AUDIO_U16LSB
        	8 - AUDIO_S16 - Same as AUDIO_S16LSB
        	9 - AUDIO_U16SYS - Unsigned 16-bit samples in the system's byte order
        	10 - AUDIO_S16SYS - Signed 16-bit samples in the system's byte order
        	11 - MIX_DEFAULT_FORMAT
		*/
		PutValue("Audio Settings", "Audio Format", "11"); 

		/*
			1 - Mono
			2 - Estereo
		*/
		PutValue("Audio Settings", "Audio Channels", "2");
		PutValue("Audio Settings", "Audio Buffers", "4096"); // Valor recomendado

		PutBlankLine();

		PutSection("Other Settings");
		PutValue("Other Settings", "Application Name", "RiseOfViwx");
		PutValue("Other Settings", "Version", "0.01");

		// El formato es sin las comillas, pero existe la posibilidad de ponerlas. Estudiar el impacto en la clase
		//PutValue("Media Routes", "Sounds", "\"./Media/Sounds\"");
		//PutValue("Media Routes", "Musics", "\"./Media/Musics\"");
		//PutValue("Media Routes", "Images", "\"./Media/Images\"");

		//PutSection("Other Section");
		//PutComment("New Section");
		//PutValue("Other Section", "Key", "Value");
		CloseFile();
	} else {
		PrepareStructFromFile("./Settings.cfg");
	}
}

bool SettingsCreator::ExistConfigFile(const std::string& parFileName) {
	bool blnReturn = false;

	std::ifstream confFile(parFileName.c_str());

	if(confFile.good()) {
		confFile.close();
		blnReturn = true;
	} else {
		confFile.close();
		blnReturn = false;
	}

	return blnReturn;
}

std::map<std::string, std::string> SettingsCreator::GetSettingsBySection(const std::string& parSection) {
	std::map<std::string, std::string> returnHashMap;

	for (std::vector<ConfigStruct>::iterator iterator = configFileValues.begin(); iterator != configFileValues.end(); ++iterator) {
		ConfigStruct tempItem = (*iterator);

		if (tempItem.Section == parSection) {
			for (std::map<std::string, std::string>::iterator insideIterator = tempItem.Values.begin(); insideIterator != tempItem.Values.end(); ++insideIterator) {
				std::pair<std::string, std::string> newPair = (*insideIterator);

				returnHashMap.insert(newPair);
			}
		}
	}

	return returnHashMap;
}

std::vector<SettingsCreator::ConfigStruct> SettingsCreator::GetAllSettings() {
	return configFileValues;
}

void SettingsCreator::PutInStruct(const std::string& parSection, const std::string& parKey, const std::string& parValue) {
	//ConfigStruct newStruct(parSection, parKey, parValue);

	//configFileValues.push_back(newStruct);

	ConfigStruct configStruct;

	bool sectionFound = false;

	unsigned int iterator = 0;
	while (!sectionFound && iterator < configFileValues.size()) {
		if (configFileValues[iterator].Section == parSection) {
			sectionFound = true;
		} else {
			iterator++;
		}
	}

	if (sectionFound) {
		// Si se ha encontrado, se añaden las opciones al hashmap
		configFileValues[iterator].Values.insert(std::pair<std::string, std::string>(parKey, parValue));
	} else {
		// Si no se ha encontrado, es una sección nueva y se añade
		configStruct.Section = parSection;
		configStruct.Values.insert(std::pair<std::string, std::string>(parKey, parValue));

		configFileValues.push_back(configStruct);
	}
}

void SettingsCreator::PrepareStructFromFile(const std::string& parFileName) {
	std::ifstream infile(parFileName.c_str());

	std::string currentSection;
	std::string eachLine;
	std::string key;
	std::string value;

	int equalPosition = 0;
	while (std::getline(infile, eachLine)) {
		std::istringstream iString(eachLine);

		// Si hay linea
		if (eachLine.length()) {
			// Comprobamos si es sección
			if (eachLine[0] == '[') {
				currentSection = Utils::Trim(eachLine.substr(1, eachLine.find(']') - 1));
			} else {
				// Comprobamos si no es comentario
				if (eachLine[0] != '#' && eachLine[0] != ';') {
					equalPosition = eachLine.find('=');

					key = Utils::Trim(eachLine.substr(0, equalPosition));
					value = Utils::Trim(eachLine.substr(equalPosition + 1));

					PutInStruct(currentSection, key, value);
				}
			}
		}
	}
}

bool SettingsCreator::sectionSearcher(ConfigStruct parStruct) {
	return (parStruct.Section == SettingsCreator::configStructSearcherFilter.Section);
}
