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
	
	{"sayori4a", sayori4a},
	{"sayori4b", sayori4b},
	{"sayori4c", sayori4c},
	{"sayori4d", sayori4d},
	{"sayori4e", sayori4e},
	{"sayori4f", sayori4f},
	{"sayori4g", sayori4g},
	{"sayori4h", sayori4h},
	{"sayori4i", sayori4i},
	{"sayori4j", sayori4j},
	{"sayori4k", sayori4k},
	{"sayori4l", sayori4l},
	{"sayori4m", sayori4m},
	{"sayori4n", sayori4n},
	{"sayori4o", sayori4o},
	{"sayori4p", sayori4p},
	{"sayori4q", sayori4q},
	{"sayori4r", sayori4r},
	{"sayori4s", sayori4s},
	{"sayori4t", sayori4t},
	{"sayori4u", sayori4u},
	{"sayori4v", sayori4v},
	{"sayori4w", sayori4w},
	{"sayori4x", sayori4x},
	{"sayori4y", sayori4y},

	
	
	
	
	{"sayori5c", sayori5c},
	{"sayori5d", sayori5d},
	

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