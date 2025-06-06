// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 06/06/2025 //
// CharacterCodes.cpp // C++ //


#include <SDL.h>
#include "CharacterCodes.h"
#include "SpriteRenderer.h"

SDL_Texture* CharacterCodes::draw(SDL_Renderer* renderer, SpriteBatch* batch, Transform spriteTransform) const {
	
	int width = 960; // Default width
	int height = 960; // Default height

	return CreateCharacterTexture(renderer, batch->surfaces[a], batch->surfaces[b], batch->surfaces[c], spriteTransform, width, height);
	// This needs to return a new sprite texture

}


CharacterCodes monika1a = { 6, 0, 1 };    // {head, left, right}
CharacterCodes monika1b = { 7, 0, 1 };
CharacterCodes monika1c = { 8, 0, 1 };
CharacterCodes monika1d = { 9, 0, 1 };

CharacterCodes sayori1a = { 12, 2, 3 };
CharacterCodes sayori4p = { 34, 6, 7 };

CharacterCodes yuri1a = { 12, 4, 5 };



