// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 05/06/2025 //
// CharacterCodes.cpp // C++ //


#include <SDL.h>
#include "CharacterCodes.h"
#include "SpriteRenderer.h"

SDL_Texture* CharacterCodes::draw(SDL_Renderer* renderer, SpriteBatch* batch, Transform spriteTransform) const {
	
	int width = 1280; // Default width, just set it to the screen width for now.
	int height = 720; // Default height

	return CreateCharacterTexture(renderer, batch->surfaces[a], batch->surfaces[b], batch->surfaces[c], spriteTransform, width, height);
	// This needs to return a new sprite texture

}


CharacterCodes monika1a = { 6, 0, 1 };
CharacterCodes monika1b = { 7, 0, 1 };
CharacterCodes monika1c = { 8, 0, 1 };
CharacterCodes sayori4p = { 34, 6, 7 };



