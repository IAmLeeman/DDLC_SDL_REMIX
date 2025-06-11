
// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 11/06/2025 //
// GAME IS COPYRIGHT TO TEAM SALVATO //

// Test script for the game engine


#include <iostream>
#include "audioDriver.h"
#include <SDL_mixer.h>
#include "SpriteRenderer.h"
#include "globals.h"
#include "CharacterCodes.h"
#include "DialogueSystem.h"
#include "cJSON.h"
#include "characterCodeLookup.h"

bool running = true;
bool waitingForAdvance = true;

int index = 0; // Index for dialogue lines

//SDL_Rect testRect = { 0, 0 , 1280, 720 };  // SO IT'S (X, Y, WIDTH, HEIGHT) // NOT (X, Y, XZOOM, YZOOM) // THIS AIN'T RENPY //

SDL_Event event;

const int FPS = 60;
const int frameDelay = 1000 / FPS;

void parseNewLine(const char* dialogues[], int& index) {

	if (dialogues[index] == nullptr) {
		return; // No more dialogue to parse
	}
	cJSON* root = cJSON_Parse(dialogues[index]);

	cJSON* speaker = cJSON_GetObjectItem(root, "character");
	cJSON* text = cJSON_GetObjectItem(root, "text");
	cJSON* sprite = cJSON_GetObjectItem(root, "sprite"); // This puts in a string of "sayori4p" or "monika1a" etc, which is actually a CharacterCode enum value.

	std::string lineStr = (text && cJSON_IsString(text)) ? text->valuestring: "";
	std::string charName = (speaker && cJSON_IsString(speaker)) ? speaker->valuestring : "";
	std::string spriteStr = (sprite && cJSON_IsString(sprite)) ? sprite->valuestring : "";

	CharacterCodes anotherOne = getCharacterCodes(spriteStr);

	
	dialogue->AddLine(lineStr, charName, anotherOne); // sprite is not a string in this but a CharacterCode.
	std::cout << "Line added: " << lineStr << " by " << charName << " with sprite " << spriteStr << std::endl;
	
	std::cout << "Index incremented to: " << index << std::endl;
	index++;
	return;
	

}

void HandleEventsAndAdvance(SDL_Renderer* renderer, bool& waitingForAdvance) {
	
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && waitingForAdvance) {

			if (event.button.button == SDL_BUTTON_LEFT) {
				parseNewLine(dialogues, index);
				dialogue->Advance(renderer);
				
				waitingForAdvance = false;
			}

		}
		if (event.type == SDL_MOUSEBUTTONUP) {
			waitingForAdvance = true;
		}
	}
}

void ch_0(SDL_Renderer* renderer, TTF_Font* font) {

	CreateTextBox(renderer, UIBatch);
	// Set blend mode for Sayori texture

	while (running) {
		Uint32 frameStart = SDL_GetTicks();

		if (music != currentMusic) {
			Mix_PlayMusic(currentMusic, -1); // Play music if it has changed
		}
		music = currentMusic; // Update current music

		HandleEventsAndAdvance(renderer, waitingForAdvance);
		SDL_RenderClear(renderer); // clear the screen

		SDL_SetTextureBlendMode(sayoriTexture, SDL_BLENDMODE_BLEND);  // Ratchet way of doing this, but it works for now
		SDL_SetTextureBlendMode(monikaTexture, SDL_BLENDMODE_BLEND);
		SDL_SetTextureBlendMode(yuriTexture, SDL_BLENDMODE_BLEND);
		SDL_SetTextureBlendMode(natsukiTexture, SDL_BLENDMODE_BLEND);

		LoadBackground(renderer, backgroundBatch, 30); // Load the background image

		SDL_RenderCopy(renderer, sayoriTexture, NULL, sayoriRect);
		SDL_RenderCopy(renderer, monikaTexture, NULL, monikaRect); // Render Sayori and Monika textures
		SDL_RenderCopy(renderer, yuriTexture, NULL, yuriRect);
		SDL_RenderCopy(renderer, natsukiTexture, NULL, natsukiRect); // Render Natsuki texture


		//sayori4p.draw(renderer, sayoriBatch, monikaTransform); // Draws Sayori4p sprite

		/// Need to add a sytem to handle the sprite update with the dialogue system

		//monika1a.draw(renderer, monikaBatch, t44);

		LoadTextBox(renderer, UIBatch); // Load the text box
		dialogue->Render(renderer, textRect.x, textRect.y);


		SDL_RenderPresent(renderer); // Present the renderer

		Uint32 frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < frameDelay) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}


