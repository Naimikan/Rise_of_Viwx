#ifndef _CSETTINGSCREATOR_HPP_
#define _CSETTINGSCREATOR_HPP_

#include "../iGlobals.hpp"

class SettingsCreator {
	public:
		struct ConfigStruct {
			std::string Section;
			std::map<std::string, std::string> Values;

			ConfigStruct() {
				Section = "";
			}

			ConfigStruct(const std::string& parSection) {
				Section = parSection;
			}

			ConfigStruct(const std::string& parSection, std::map<std::string, std::string> parValues) {
				Section = parSection;
				Values = parValues;
			}

			ConfigStruct(const std::string& parSection, const std::string& parKey, const std::string& parValue) {
				Section = parSection;
				Values.insert(std::pair<std::string, std::string>(parKey, parValue));
			}

			ConfigStruct(const ConfigStruct& parStruct) {
				Section = parStruct.Section;
				Values = parStruct.Values;
			}

			ConfigStruct operator=(ConfigStruct parStruct) {
				return ConfigStruct(parStruct.Section, parStruct.Values);
			}

			bool operator==(ConfigStruct parStruct) {
				return ((Section == parStruct.Section) && (Values == parStruct.Values));
			}

			bool operator!=(ConfigStruct parStruct) {
				return ((Section != parStruct.Section) || (Values != parStruct.Values));
			}
		};

		static void OpenFile(const std::string& parFileName) throw(GenericException);
		static void CloseFile();
		static bool ExistConfigFile(const std::string& parFileName);

		static void PutSection(const std::string& parSection);
		static void PutValue(const std::string& parSection, const std::string& parKey, const std::string& parValue);
		static void PutComment(const std::string& parComment);
		static void PutBlankLine();

		static void ConfigureSettingsFile();

		static void PrepareStructFromFile(const std::string& parFileName);

		static void PutInStruct(const std::string& parSection, const std::string& parKey, const std::string& parValue);
		static std::map<std::string, std::string> GetSettingsBySection(const std::string& parSection);
		static std::vector<ConfigStruct> GetAllSettings();

		static void OnCleanUp();

	private:
		static std::string configFileName;
		static std::ofstream configFile;

		static std::vector<ConfigStruct> configFileValues;

		static ConfigStruct configStructSearcherFilter;

		static bool sectionSearcher (ConfigStruct parStruct);
};

#endif // End _CSETTINGSCREATOR_HPP_
