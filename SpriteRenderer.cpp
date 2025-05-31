// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 24/05/2025 //
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
SDL_Texture* textTexture = NULL;

std::string currentText;

SDL_Rect textRect;
SDL_Rect* TRectPTR = &textRect;

#define MAX_SPRITES 1000;
#define MAX_PATH 256;

int textBoxWidth = 500; // Default width for text box.
int textBoxHeight = 100; // Default height for text box.

struct SpritePart {
	SDL_Texture* texture;
	int offsetX;
	int offsetY;
	int width;
	int height;
};

Transform monikaTransform = { 0.0f, -20.0f, 1.5f, 1.5f, 0.0f };  // Default transform values for Monika's sprite.
//Transform right = { 200.0f, 210.0f, 1.0f, 1.0f, 0.0f }; // Default transform values for sprite on right side.
Transform textBoxTransform = { 500.0f, 500.0f, 1.0f, 1.0f, 0.0f }; // Default transform values for text box.



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
	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL); // NULL destRect means it will render to the whole screen.
}

void SetText(SDL_Renderer* renderer, const std::string& newText) {
	
	if (textTexture) {
		SDL_DestroyTexture(textTexture);
		textTexture = nullptr;
	}

	currentText = newText;
	SDL_Color colour = { 255, 255, 255, 255 }; // White color for the text.
	
	if (font == nullptr) {
		printf("Font is null, cannot render text\n");
		return;
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, newText.c_str(), colour);

	if (textSurface == nullptr) {
		printf("Failed to create text surface: %s\n", TTF_GetError());
		return;
	}
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	if (!textTexture) {
		SDL_Log("Failed to create text texture: %s", SDL_GetError());
		return;
	}
}
void LoadTextBox(SDL_Renderer* renderer, SpriteBatch* UI, int index) {
	
	//SDL_DestroyTexture(textBoxTexture); // Destroy previous texture if it exists
	//SDL_DestroyTexture(textTexture); // Destroy previous text texture if it exists
	textBoxTexture = UI[0].surfaces[index];

	SDL_Rect destRect = {
	(int)textBoxTransform.x,
	(int)textBoxTransform.y,
	textBoxWidth,
	textBoxHeight
	};

	//std::string testText = "SUPAHAXOR, I LOVE YOU!"; // Example text to render in the text box.
	
	SDL_RenderCopyEx(renderer, textBoxTexture, NULL, &destRect, 0.0, NULL, SDL_FLIP_NONE);
	int texW, texH;

	// Position text inside textbox
	textRect = {
		destRect.x + 10,  // Add padding from the left
		destRect.y + 10,  // Add padding from the top
		0, 0              // Width/height will be set next
	};
	SDL_QueryTexture(textTexture, NULL, NULL, &texW, &texH);
	textRect.w = texW; // Set width of text rectangle
	textRect.h = texH; // Set height of text rectangle
	SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
}

void LoadAllTextures(SDL_Renderer* renderer, SpriteBatch* x, SpriteBatch* y, SpriteBatch* z, SpriteBatch* UI, SpriteBatch* v, SpriteBatch* u) {
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


