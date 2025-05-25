// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 25/05/2025 //
// CharacterCodes.cpp // C++ //


#include <SDL.h>
#include "CharacterCodes.h"
#include "SpriteRenderer.h"

void CharacterCodes::draw(SDL_Renderer* renderer, SpriteBatch* batch) const {
	DrawSprites(renderer, batch->surfaces[a], batch->surfaces[b], batch->surfaces[c]);
}


CharacterCodes monika1a = { 6, 0, 1 };
CharacterCodes monika1b = { 7, 0, 1 };
CharacterCodes monika1c = { 8, 0, 1 };
CharacterCodes sayori4p = { 34, 6, 7 };



