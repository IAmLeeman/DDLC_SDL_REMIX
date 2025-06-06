// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 02/06/2025 //
// CharacterCodes.h // HEADER //

#pragma once

#ifndef CHARACTER_CODES_H
#define CHARACTER_CODES_H

#include <SDL.h>
#include "SpriteRenderer.h"

struct CharacterCodes{
	int a;
	int b;
	int c;
	SDL_Texture* draw(SDL_Renderer* renderer, SpriteBatch* batch, Transform spriteTransform) const;
	
};

extern CharacterCodes monika1a;
extern CharacterCodes monika1b;
extern CharacterCodes monika1c;
extern CharacterCodes monika1d;

extern CharacterCodes sayori1a;
extern CharacterCodes sayori4p;

extern CharacterCodes yuri1a;
#endif // CHARACTER_CODES_H


