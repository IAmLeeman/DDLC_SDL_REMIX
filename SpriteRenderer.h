// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 24/05/2025 //
// SpriteRenderer.h // HEADER //

extern SDL_Texture* spriteHead;
extern SDL_Texture* spriteLeft;
extern SDL_Texture* spriteRight; // Hardcoded to test spriteRenderer - will require a spriteLoader at some point.
extern SDL_Texture* backgroundTexture;

#pragma once

#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <unordered_map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

struct SpriteBatch {
	SDL_Texture** surfaces;
	int count;
};

struct Transform {
	float x, y;
	float scaleX, scaleY;
	float rotation;

};


extern Transform monikaTransform;
extern Transform right;
extern Transform textBoxTransform;

int countFilesInFolder(const char* folderpath);

SpriteBatch* LoadSpriteFolder(const char* folderpath, SDL_Renderer* renderer);
void free_sprite(SpriteBatch* batch);

void DrawSprites(SDL_Renderer* x, SDL_Texture* spriteHead, SDL_Texture* spriteLeft, SDL_Texture* spriteRight);
void LoadBackground(SDL_Renderer* renderer, SpriteBatch* x, int index);
void LoadTextBox(SDL_Renderer* renderer, SpriteBatch* UI, int index);
void SetText(SDL_Renderer* renderer, const std::string& newText);
void LoadAllTextures(SDL_Renderer* renderer, SpriteBatch* x, SpriteBatch* y, SpriteBatch* z, SpriteBatch* UI, SpriteBatch* v, SpriteBatch* u);
void UnloadAllTextures();

SDL_Texture* createSpriteTexture(SDL_Renderer* renderer, int width, int height);

void RenderSpriteLayer(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* layer, SDL_Rect* srcRect, SDL_Rect* destRect);

void renderFinalSprite(SDL_Renderer* renderer, SDL_Texture* spriteTexture, SDL_Rect* destRect);

#endif

