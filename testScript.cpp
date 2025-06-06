
// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 06/06/2025 //
// GAME IS COPYRIGHT TO TEAM SALVATO //

// Test script for the game engine


#include <iostream>
#include "audioDriver.h"
#include <SDL_mixer.h>
#include "SpriteRenderer.h"
#include "globals.h"
#include "CharacterCodes.h"
#include "DialogueSystem.h"

bool running = true;
bool waitingForAdvance = true;

//SDL_Rect testRect = { 0, 0 , 1280, 720 };  // SO IT'S (X, Y, WIDTH, HEIGHT) // NOT (X, Y, XZOOM, YZOOM) // THIS AIN'T RENPY //

SDL_Event event;

const int FPS = 60;
const int frameDelay = 1000 / FPS;

void HandleEventsAndAdvance(SDL_Renderer* renderer, bool& waitingForAdvance) {
	
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && waitingForAdvance) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				dialogue->Advance(renderer);
				waitingForAdvance = false;
			}

		}
		if (event.type == SDL_MOUSEBUTTONUP) {
			waitingForAdvance = true;
		}
	}
}

void ch_0(SDL_Renderer* renderer, TTF_Font* font){

	CreateTextBox(renderer, UIBatch);
	 // Set blend mode for Sayori texture

	while (running) {
		Uint32 frameStart = SDL_GetTicks();

		HandleEventsAndAdvance(renderer, waitingForAdvance);
		SDL_RenderClear(renderer); // clear the screen

		SDL_SetTextureBlendMode(sayoriTexture, SDL_BLENDMODE_BLEND);  // Ratchet way of doing this, but it works for now
		SDL_SetTextureBlendMode(monikaTexture, SDL_BLENDMODE_BLEND);
		SDL_SetTextureBlendMode(yuriTexture, SDL_BLENDMODE_BLEND);
		LoadBackground(renderer, backgroundBatch, 30); // Load the background image

		SDL_RenderCopy(renderer, sayoriTexture, NULL, sayoriRect);
		SDL_RenderCopy(renderer, monikaTexture, NULL, monikaRect); // Render Sayori and Monika textures
		SDL_RenderCopy(renderer, yuriTexture, NULL, yuriRect);

		
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
