// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 27/07/2025 //
// CharacterCodeLookup.cpp // C++ //

#include "characterCodeLookup.h"
#include <unordered_map>
#include <optional>

static std::unordered_map<std::string, CharacterCodes> characterCodeMap = {
	{"monika1a", monika1a},
	{"monika1b", monika1b},
	{"monika1c", monika1c},
	{"monika1d", monika1d},
	
	{"monika5a", monika5a},
	{"monika5b", monika5b},

	{"sayori1a", sayori1a},
	{"sayori1b", sayori1b},
	{"sayori1c", sayori1c},
	{"sayori1d", sayori1d},
	{"sayori1e", sayori1e},
	{"sayori1f", sayori1f},
	{"sayori1g", sayori1g},
	{"sayori1h", sayori1h},
	{"sayori1i", sayori1i},
	{"sayori1j", sayori1j},
	{"sayori1k", sayori1k},
	{"sayori1l", sayori1l},
	{"sayori1m", sayori1m},
	{"sayori1n", sayori1n},
	{"sayori1o", sayori1o},
	{"sayori1p", sayori1p},
	{"sayori1q", sayori1q},
	{"sayori1r", sayori1r},
	{"sayori1s", sayori1s},
	{"sayori1t", sayori1t},
	{"sayori1u", sayori1u},
	{"sayori1v", sayori1v},
	{"sayori1w", sayori1w},
	{"sayori1x", sayori1x},
	{"sayori1y", sayori1y},
	

	{"sayori4j", sayori4j},
	{"sayori4h", sayori4h},
	
	{"sayori4p", sayori4p},
	{"sayori4r", sayori4r},
	{"sayori5c", sayori5c},

	{"natsuki1a", natsuki1a},
	{"yuri1a", yuri1a},

	{"NULLER", nuller}

};

static std::unordered_map<std::string, Transform> characterTransformMap = { // Not sure if this is needed, but I'll keep it for now.
	{"t11", t11},
	{"t33", t33},
};

// This YandereDev looking stuff is needed since the cJSON returns a string. Yeah, I don't like it either but I can't figure another way out.

CharacterCodes getCharacterCodes(const std::string& name) {
	auto it = characterCodeMap.find(name);
	if (it != characterCodeMap.end()) {
		return it->second;

	} 
	else {
		return {}; // Return an empty CharacterCodes if not found
	}
}