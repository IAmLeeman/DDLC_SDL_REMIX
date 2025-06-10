// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 10/06/2025 //
// globals.h // HEADER //


#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL.h>
#include "SpriteRenderer.h"
#include <SDL_ttf.h>
#include "DialogueSystem.h"



extern SpriteBatch* backgroundBatch;
extern SpriteBatch* monikaBatch;
extern SpriteBatch* sayoriBatch;
extern SpriteBatch* natsukiBatch;

extern SpriteBatch* yuriBatch;
extern SpriteBatch* UIBatch;

extern TTF_Font* font;
extern DialogueSystem* dialogue;

#ifdef __cplusplus
extern "C" {
#endif

extern const char* dialogues[];
#ifdef __cplusplus
}
#endif

#endif

