
#include "characterCodeLookup.h"
#include <unordered_map>

static std::unordered_map<std::string, CharacterCodes> characterCodeMap = {
	{"monika1a", monika1a},
	{"monika1b", monika1b},
	{"monika1c", monika1c},
	{"sayori4p", sayori4p},
	{"natsuki1a", natsuki1a},
	{"yuri1a", yuri1a}

};

CharacterCodes getCharacterCodes(const std::string& name) {
	auto it = characterCodeMap.find(name);
	if (it != characterCodeMap.end()) {
		return it->second;
	} else {
		return {}; // Return an empty CharacterCodes if not found
	}
}