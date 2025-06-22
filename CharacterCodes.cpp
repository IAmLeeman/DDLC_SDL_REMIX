// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 14/06/2025 //
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
//CharacterCodes monika5a = { NULL, NULL, 4 };  // Calling this doesn't erase the other sprite // just layer 3 over each other? Ratchet? Yeah.
CharacterCodes monika5a = { 5, 5, 5 };
CharacterCodes monika5b = { 6, 6, 6 };

CharacterCodes sayori1a = { 13, 3, 4 };
CharacterCodes sayori1q = { 3, 4, 25 };
CharacterCodes sayori4p = { 35, 7, 8 };
CharacterCodes sayori5c = { 11,11,11 };

CharacterCodes yuri1a = { 13, 5, 6 };

CharacterCodes natsuki1a = { 6, 5 ,4 };
CharacterCodes nuller = {NULL, NULL, NULL}; // This is a nuller for the sprite renderer to use when no character is present/ just renders a transparent texture.



