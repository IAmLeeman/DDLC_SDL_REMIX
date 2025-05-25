// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 24/05/2025 //
// SpriteRenderer.cpp // C++ //



#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "SpriteRenderer.h"
#include <iostream>

#include "dirent.h"



SDL_Texture* spriteHead = NULL;
SDL_Texture* spriteLeft = NULL;
SDL_Texture* spriteRight = NULL;
SDL_Texture* backgroundTexture = NULL;

#define MAX_SPRITES 1000;
#define MAX_PATH 256;



struct SpritePart {
	SDL_Texture* texture;
	int offsetX;
	int offsetY;
	int width;
	int height;
};

Transform monikaTransform = { 0.0f, -20.0f, 1.5f, 1.5f, 0.0f };  // Default transform values for Monika's sprite.
//Transform right = { 200.0f, 210.0f, 1.0f, 1.0f, 0.0f }; // Default transform values for sprite on right side.



void DrawSprites(SDL_Renderer* x, SDL_Texture* spriteHead, SDL_Texture* spriteLeft, SDL_Texture* spriteRight) {  // Change to accept global transform

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
		dstRect.w = static_cast<int>(part.width * monikaTransform.scaleX);
		dstRect.h = static_cast<int>(part.height * monikaTransform.scaleY);
		dstRect.x = static_cast<int>(monikaTransform.x + part.offsetX * monikaTransform.scaleX);
		dstRect.y = static_cast<int>(monikaTransform.y + part.offsetY * monikaTransform.scaleY);

		SDL_RenderCopyEx(
			x,
			part.texture,
			nullptr,        // srcRect (full texture)
			&dstRect,
			monikaTransform.rotation,
			nullptr,        // rotation center (nullptr = center of dstRect)
			SDL_FLIP_NONE
		);
	}
}



/*SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path) {					/// Will not need this to load from RAM.
	SDL_Surface* surface = IMG_Load(path);
	if (!surface) {
		printf("Image failed to load\n");
		return NULL;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (!texture) {
		printf("Texture creation failed %s\n", SDL_GetError());
	}
	return texture;
}*/
void LoadBackground(SDL_Renderer* renderer, SpriteBatch* x, int index) {
	backgroundTexture = x[0].surfaces[index]; // Loads background texture from RAM.
	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
}

void LoadAllTextures(SDL_Renderer* renderer, SpriteBatch* x, SpriteBatch* y, SpriteBatch* z, SpriteBatch* UI) {
	//textureMonika1 = loadTexture(renderer, "images/monika/a.png");		// Default sprite textures.
	//textureMonika2 = loadTexture(renderer, "images/monika/1l.png");		//
	//textureMonika3 = loadTexture(renderer, "images/monika/1r.png");		//
	//backgroundTexture = loadTexture(renderer, "images/bg/bedroom.png"); // Default background texture.

	std::cout << "Number of background sprites: " << x->count << std::endl;
	std::cout << "Number of monika sprites: " << y->count << std::endl;
	std::cout << "Number of UI sprites: " << UI->count << std::endl;
	
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


