// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 27/07/2025 //
// CharacterCodes.cpp // C++ //


#include <SDL.h>
#include "CharacterCodes.h"
#include "SpriteRenderer.h"
#include <optional>

SDL_Texture* CharacterCodes::draw(SDL_Renderer* renderer, SpriteBatch* batch, Transform spriteTransform) const {
	
	int width = 960; // Default width
	int height = 960; // Default height

	return CreateCharacterTexture(renderer, batch->surfaces[a], batch->surfaces[b], batch->surfaces[c], spriteTransform, width, height);
	// This needs to return a new sprite texture

}


CharacterCodes monika1a = { 7, 1, 2 };    // {head, left, right}
CharacterCodes monika1b = { 8, 1, 2 };
CharacterCodes monika1c = { 9, 1, 2 };
CharacterCodes monika1d = { 10, 1, 2 };


CharacterCodes monika5a = { 5, 5, 5 };
CharacterCodes monika5b = { 6, 6, 6 };

CharacterCodes sayori1a = { 13, 3, 4 };
CharacterCodes sayori1b = { 14, 3, 4 };
CharacterCodes sayori1c = { 15, 3, 4 };
CharacterCodes sayori1d = { 16, 3, 4 };
CharacterCodes sayori1e = { 17, 3, 4 };
CharacterCodes sayori1f = { 20, 3, 4 };
CharacterCodes sayori1g = { 21, 3, 4 };
CharacterCodes sayori1h = { 24, 3, 4 };
CharacterCodes sayori1i = { 25, 3, 4 };
CharacterCodes sayori1j = { 26, 3, 4 };
CharacterCodes sayori1k = { 27, 3, 4 };
CharacterCodes sayori1l = { 28, 3, 4 };
CharacterCodes sayori1m = { 29, 3, 4 };
CharacterCodes sayori1n = { 30, 3, 4 };
CharacterCodes sayori1o = { 34, 3, 4 };
CharacterCodes sayori1p = { 35, 3, 4 };
CharacterCodes sayori1q = { 36, 3, 4 };
CharacterCodes sayori1r = { 37, 3, 4 };
CharacterCodes sayori1s = { 38, 3, 4 };
CharacterCodes sayori1t = { 39, 3, 4 };
CharacterCodes sayori1u = { 40, 3, 4 };
CharacterCodes sayori1v = { 41, 3, 4 };
CharacterCodes sayori1w = { 42, 3, 4 };
CharacterCodes sayori1x = { 43, 3, 4 };
CharacterCodes sayori1y = { 44, 3, 4 };



CharacterCodes sayori4a = { 13 ,7 ,8 };
CharacterCodes sayori4b = { 14, 7, 8 };
CharacterCodes sayori4c = { 15, 7, 8 };
CharacterCodes sayori4d = { 16, 7, 8 };
CharacterCodes sayori4e = { 17, 7, 8 };
CharacterCodes sayori4f = { 20, 7, 8 };
CharacterCodes sayori4g = { 21, 7, 8 };
CharacterCodes sayori4h = { 24, 7, 8 };
CharacterCodes sayori4i = { 25, 7, 8 };
CharacterCodes sayori4j = { 26, 7, 8 };
CharacterCodes sayori4k = { 27, 7, 8 };
CharacterCodes sayori4l = { 28, 7, 8 };
CharacterCodes sayori4m = { 29, 7, 8 };
CharacterCodes sayori4n = { 30, 7, 8 };
CharacterCodes sayori4o = { 34, 7, 8 };
CharacterCodes sayori4q = { 36, 7, 8 };
CharacterCodes sayori4r = { 37, 7, 8 };
CharacterCodes sayori4s = { 38, 7, 8 };
CharacterCodes sayori4t = { 39, 7, 8 };
CharacterCodes sayori4u = { 40, 7, 8 };
CharacterCodes sayori4v = { 41, 7, 8 };
CharacterCodes sayori4w = { 42, 7, 8 };
CharacterCodes sayori4x = { 43, 7, 8 };
CharacterCodes sayori4y = { 44, 7, 8 };


CharacterCodes sayori5c = { 11,11,11 };

CharacterCodes yuri1a = { 13, 5, 6 };

CharacterCodes natsuki1a = { 6, 5 ,4 };
CharacterCodes nuller = {NULL, NULL, NULL}; // This is a nuller for the sprite renderer to use when no character is present/ just renders a transparent texture.



