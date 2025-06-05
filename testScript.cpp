
// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 02/06/2025 //
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

//SDL_Rect testRect = {384, 0 , 2, 2};

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

	while (running) {
		Uint32 frameStart = SDL_GetTicks();

		HandleEventsAndAdvance(renderer, waitingForAdvance);
		SDL_RenderClear(renderer); // clear the screen

		//LoadBackground(renderer, backgroundBatch, 30); // Load the background image

		//SDL_RenderCopy(renderer, sayoriTexture, NULL, NULL); // Very odd...
		//SDL_RenderCopy(renderer, monikaTexture, NULL, NULL); // Render Sayori and Monika textures

		
		sayori4p.draw(renderer, sayoriBatch, monikaTransform); // Draws Sayori4p sprite
		
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
