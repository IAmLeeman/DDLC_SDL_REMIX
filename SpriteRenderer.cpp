// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 04/06/2025 //
// SpriteRenderer.cpp // C++ //

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "SpriteRenderer.h"
#include "dirent.h"
#include "globals.h"

SDL_Texture* spriteHead = NULL;
SDL_Texture* spriteLeft = NULL;
SDL_Texture* spriteRight = NULL;
SDL_Texture* backgroundTexture = NULL;
SDL_Texture* textBoxTexture = NULL;

SDL_Texture* nameBox = NULL;

SDL_Rect destRect;
SDL_Rect textRect;
SDL_Rect nameRect;


#define MAX_SPRITES 1000;
#define MAX_PATH 256;

int textBoxWidth = 850; // Default width for text box.
int textBoxHeight = 150; // Default height for text box.

int nameBoxWidth = 50;		// Default width for name box.
int nameBoxHeight = 20;		// Default height for name box.

struct SpritePart {
	SDL_Texture* texture;
	int offsetX;
	int offsetY;
	int width;
	int height;
};

// Screen is 1280 x 720
Transform monikaTransform = { 0.0f, -20.0f, 1.5f, 1.5f, 0.0f };			// Default transform values for Monika's sprite.
Transform t44 = { 700.0f, -20.0f, 1.5f, 1.5f, 0.0f };					// Default transform values for sprite on right side.
Transform textBoxTransform = { 215.0f, 560.0f, 1.0f, 1.0f, 0.0f };		// Default transform values for text box.
Transform t33 = { 600.0f - 20.0f, 1.5f, 1.5f, 0.0f };
Transform t11 = { 0.0f, 0.0f, 1.5f, 1.5f, 0.0f }; // Default transform values for sprite on left side.

Transform spriteTransform;

SDL_Texture* CreateCharacterTexture(SDL_Renderer* renderer, SDL_Texture* spriteHead, SDL_Texture* spriteLeft, SDL_Texture* spriteRight, Transform spriteTransform, int width, int height) {
	SDL_Texture* targetTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
	
	if (!targetTexture) {
		std::cerr << "Failed to create target texture: " << SDL_GetError() << std::endl;
		return nullptr;
	}
	SDL_Texture* oldTarget = SDL_GetRenderTarget(renderer);
	SDL_SetRenderTarget(renderer, targetTexture);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // Clear with transparent color
	SDL_RenderClear(renderer);

	DrawSprites(renderer, spriteHead, spriteLeft, spriteRight, monikaTransform); // Draw the sprites onto the target texture
	SDL_SetRenderTarget(renderer, oldTarget); // Reset the render target

	return targetTexture; // Return the combined texture
}
void DrawSprites(SDL_Renderer* x, SDL_Texture* spriteHead, SDL_Texture* spriteLeft, SDL_Texture* spriteRight, Transform spriteTransform) {

	SpritePart monikaParts[] = {
	{spriteHead, 0, 0, 500, 500},           // Sprite parts do not require any sort of offset, that's pretty handy.
	{spriteLeft, 0, 0, 500, 500},
	{spriteRight, 0, 0, 500, 500}
	};

	if (!x) {
		std::cerr << "Renderer is null" << std::endl;
	}

	for (const auto& part : monikaParts) {
		SDL_Rect dstRect;
		dstRect.w = static_cast<int>(part.width * spriteTransform.scaleX);
		dstRect.h = static_cast<int>(part.height * spriteTransform.scaleY);
		dstRect.x = static_cast<int>(spriteTransform.x + part.offsetX * spriteTransform.scaleX);
		dstRect.y = static_cast<int>(spriteTransform.y + part.offsetY * spriteTransform.scaleY);

		SDL_RenderCopyEx(
			x,
			part.texture,
			nullptr,        // srcRect (full texture)
			&dstRect,
			spriteTransform.rotation,
			nullptr,        // rotation center (nullptr = center of dstRect)
			SDL_FLIP_NONE
		);
	}
}

void LoadBackground(SDL_Renderer* renderer, SpriteBatch* x, int index, int alpha) {
	backgroundTexture = x[0].surfaces[index]; // Loads background texture from RAM.
	SDL_SetTextureAlphaMod(backgroundTexture, alpha); // Set the alpha value for the background texture.
	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL); // NULL destRect means it will render to the whole screen.
}

void CreateTextBox(SDL_Renderer* renderer, SpriteBatch* UI) { // Creates text box - should only run once.
	textBoxTexture = UI[0].surfaces[24];
	nameBox = UI[0].surfaces[19];
	
	destRect = {
	(int)textBoxTransform.x,
	(int)textBoxTransform.y,
	textBoxWidth,
	textBoxHeight
	};

	int texW, texH, nameW, nameH;

	textRect = {
		destRect.x + 10,  // Add padding from the left
		destRect.y + 10,  // Add padding from the top
		0, 0              // Width/height will be set next
	};
	SDL_QueryTexture(textBoxTexture, NULL, NULL, &texW, &texH);
	textRect.w = texW; // Set width of text rectangle
	textRect.h = texH; // Set height of text rectangle

	SDL_QueryTexture(nameBox, NULL, NULL, &nameW, &nameH);

	nameRect = {
		destRect.x + 10,
		destRect.y - nameH,
		nameW,
		nameH
	};
}

void LoadTextBox(SDL_Renderer* renderer, SpriteBatch* UI) {
	
	SDL_RenderCopy(renderer, textBoxTexture, NULL, &destRect);			// Renders text box at the bottom of the screen.
	SDL_RenderCopy(renderer, nameBox, NULL, &nameRect);					// Renders name box above text box.	
}

void LoadAllTextures(SDL_Renderer* renderer, SpriteBatch* x, SpriteBatch* y, SpriteBatch* z, SpriteBatch* UI, SpriteBatch* v, SpriteBatch* u) {  // Debug purposes
	//textureMonika1 = loadTexture(renderer, "images/monika/a.png");		// Default sprite textures.
	//textureMonika2 = loadTexture(renderer, "images/monika/1l.png");		//
	//textureMonika3 = loadTexture(renderer, "images/monika/1r.png");		//
	//backgroundTexture = loadTexture(renderer, "images/bg/bedroom.png"); // Default background texture.

	std::cout << "Number of background sprites: " << x->count << std::endl;
	std::cout << "Number of monika sprites: " << y->count << std::endl;
	std::cout << "Number of UI sprites: " << UI->count << std::endl;
	std::cout << "Number of yuri sprites: " << v->count << std::endl;
	std::cout << "Number of natsuki sprites: " << u->count << std::endl;
	
	if (!x) {
		std::cerr << "SpriteBatch is null" << std::endl;
		return;
	}

	if (!x[0].surfaces) {
		printf("Batch 0 surfaces pointer is null. No sprites loaded?\n");
		return;
	}

	if (x && x[0].surfaces && x[0].count >= 2) {
		// safe to access x[10].surfaces[2]
	}
	else {
		std::cout << "Index out of bounds or null pointer" << std::endl;
	}

	backgroundTexture = x[0].surfaces[1]; // Loads background texture from RAM.
	spriteHead = y[0].surfaces[6];
	spriteLeft = y[0].surfaces[0];
	spriteRight = y[0].surfaces[1]; // Loads monika textures from RAM.

	if (!spriteHead || !spriteLeft || !spriteRight || !backgroundTexture) {
		printf("Failed to load one or more textures\n");
	}
	else {
		printf("All textures loaded successfully\n");
	}
}
void UnloadAllTextures() {
	SDL_DestroyTexture(spriteHead);
	SDL_DestroyTexture(spriteLeft);
	SDL_DestroyTexture(spriteRight);
	SDL_DestroyTexture(backgroundTexture);

	spriteHead = NULL;
	spriteLeft = NULL;
	spriteRight = NULL;
	backgroundTexture = NULL;

}


SDL_Texture* createSpriteTexture(SDL_Renderer* renderer, int width, int height) {
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

	return texture;
}

void RenderSpriteLayer(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Texture* layer, SDL_Rect* srcRect, SDL_Rect* destRect) {
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderCopy(renderer, layer, srcRect, destRect);
	SDL_SetRenderTarget(renderer, NULL);
}
void renderFinalSprite(SDL_Renderer* renderer, SDL_Texture* spriteTexture, SDL_Rect* destRect) {
	SDL_RenderCopy(renderer, spriteTexture, NULL, destRect);
}



SpriteBatch* LoadSpriteFolder(const char* folderpath, SDL_Renderer* renderer) {
	SpriteBatch* batch = new SpriteBatch();

	int count = countFilesInFolder(folderpath);
	batch->surfaces = new SDL_Texture*[count];
	batch->count = 0;

	DIR* dir = opendir(folderpath);
	if (dir == NULL) {
		printf("Error opening directory: %s\n", folderpath);
		delete batch;
		return NULL;
	}
	struct dirent* entry;
	int index = 0;
	while ((entry = readdir(dir)) != NULL && index < count) {
		if (entry->d_name[0] == '.') {
			continue;
		}
		std::cout << "Found Sprite File: " << entry->d_name << std::endl;
		std::string fullPath = std::string(folderpath) + "/" + entry->d_name;	// Likely don't need this line.

		// Load Texture rather than just a filename and crash everything.

		SDL_Texture* tex = IMG_LoadTexture(renderer, fullPath.c_str());
		if (tex == NULL) {
			std::cerr << "Failed to load texture: " << fullPath << "SDL_Error: " << SDL_GetError() << std::endl;
			continue;
		}
		batch->surfaces[index++] = tex;


	}
	closedir(dir);
	batch->count = index;
	return batch;
}

int countFilesInFolder(const char* folderpath) {						/// More spaghetti than bolognese. 
	int count = 0;
	DIR* dir = opendir(folderpath);
	if (!dir) {
		std::cout << "Cannot open folder: " << folderpath << std::endl;
	}
	struct dirent* entry;
	while ((entry = readdir(dir)) != nullptr) {
		if (entry->d_name[0] == '.')
			continue;

		char filepath[512];
		snprintf(filepath, sizeof(filepath), "%s/%s", folderpath, entry->d_name);

		struct stat st;

		if (stat(filepath, &st) == 0) {
			if (S_ISREG(st.st_mode)) {
				std::cout << "Counting file: " << entry->d_name << std::endl;
				++count;
			}
			else {
				std::cout << "Skipping non-regular file: " << entry->d_name << std::endl;
			}
		}
		else {
			std::cout << "Stat failed on: " << filepath << std::endl;
		}
	}
	closedir(dir);
	return count;
}


