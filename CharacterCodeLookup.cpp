
#include "characterCodeLookup.h"
#include <unordered_map>

static std::unordered_map<std::string, CharacterCodes> characterCodeMap = {
	{"monika1a", monika1a},
	{"monika1b", monika1b},
	{"monika1c", monika1c},
	{"monika1d", monika1d},
	
	{"monika5a", monika5a},
	{"monika5b", monika5b},

	{"sayori1a", sayori1a},
	{"sayori4p", sayori4p},

	{"natsuki1a", natsuki1a},
	{"yuri1a", yuri1a}

};

// This YandereDev looking stuff is needed since the cJSON returns a string. Yeah, I don't like it either but I can't figure another way out.

CharacterCodes getCharacterCodes(const std::string& name) {
	auto it = characterCodeMap.find(name);
	if (it != characterCodeMap.end()) {
		return it->second;
	} else {
		return {}; // Return an empty CharacterCodes if not found
	}
}