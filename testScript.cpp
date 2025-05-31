
// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 31/05/2025 //
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
SDL_Event event;

const int FPS = 60;
const int frameDelay = 1000 / FPS;

void ch_0(SDL_Renderer* renderer, TTF_Font* font){

	while (running) {
		Uint32 frameStart = SDL_GetTicks();


		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		SDL_RenderClear(renderer); // clear the screen
		SDL_Rect* textRect = {}; // Needs to be the actual coordinates for the textbox, currently covers whole screen.

		LoadBackground(renderer, backgroundBatch, 30); // Load the background image
		LoadTextBox(renderer, UIBatch, 24); // Load the text box

		//dialogue->Advance(renderer);
		//dialogue->Render(renderer, textRect);

		
		//sayori4p.draw(renderer, sayoriBatch); // Draws Sayori4p sprite
		

		



		SDL_RenderPresent(renderer); // Present the renderer
		
		Uint32 frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < frameDelay) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}
