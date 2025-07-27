// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 27/07/2025 //
// CharacterCodes.h // HEADER //


#ifndef CHARACTER_CODES_H
#define CHARACTER_CODES_H

#include <SDL.h>
#include "SpriteRenderer.h"
#include <string>

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

extern CharacterCodes monika5a;
extern CharacterCodes monika5b;

extern CharacterCodes sayori1a;
extern CharacterCodes sayori1b;
extern CharacterCodes sayori1c;
extern CharacterCodes sayori1d;
extern CharacterCodes sayori1e;
extern CharacterCodes sayori1f;
extern CharacterCodes sayori1g;
extern CharacterCodes sayori1h;
extern CharacterCodes sayori1i;
extern CharacterCodes sayori1j;	
extern CharacterCodes sayori1k;
extern CharacterCodes sayori1q;
extern CharacterCodes sayori1l;
extern CharacterCodes sayori1m;
extern CharacterCodes sayori1n;
extern CharacterCodes sayori1o;
extern CharacterCodes sayori1p;
extern CharacterCodes sayori1r;
extern CharacterCodes sayori1s;
extern CharacterCodes sayori1t;
extern CharacterCodes sayori1u;
extern CharacterCodes sayori1v;
extern CharacterCodes sayori1w;
extern CharacterCodes sayori1x;
extern CharacterCodes sayori1y;

extern CharacterCodes sayori4p;
extern CharacterCodes sayori4j;
extern CharacterCodes sayori5c;


extern CharacterCodes yuri1a;

extern CharacterCodes natsuki1a;
extern CharacterCodes nuller;
#endif // CHARACTER_CODES_H


