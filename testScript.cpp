
// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 28/05/2025 //
// GAME IS COPYRIGHT TO TEAM SALVATO //

// Test script for the game engine


#include <iostream>
#include "audioDriver.h"
#include <SDL_mixer.h>
#include "SpriteRenderer.h"
#include "globals.h"
#include "CharacterCodes.h"
#include "DialogueSystem.h"

//extern SDL_Rect textRect;

void ch_0(SDL_Renderer* renderer){

	SDL_Rect textRect = { 100, 500, 600, 50 };

	stopMusic(2000); // stop music with a 2 second fadeout
	SDL_RenderClear(renderer); // clear the screen
	//LoadBackground(renderer, backgroundBatch, 30); // Load the background image
	LoadTextBox(renderer, UIBatch, 24); // Load the text box

	//sayori4p.draw(renderer, sayoriBatch); // Draws Sayori4p sprite
	DialogueSystem dialogue(renderer, font);
	dialogue.AddLine("I LOVE YOU SUPAHAXOR"); 
	dialogue.AddLine("IDI NAHUI BLYAT");

	if (!dialogue.IsFinished()) {
		dialogue.Advance(renderer);
		SDL_Log("ADVANCE CALLED");
	}
	dialogue.Render(renderer, &textRect);
	SDL_RenderPresent(renderer);					// Present the renderer to the screen
	

	//SDL_RenderPresent(renderer); // This is required because of double buffering, a secret background buffer is cleared but not shown on the screen until this is called, yeah...
	/*SetText(renderer, "I LOVE YOU SUPAHAXOR");
	LoadTextBox(renderer, UIBatch, 24); // Currently takes a default text string
	SDL_RenderPresent(renderer); // Present the renderer to the screen
	SDL_Delay(3000); // Wait for 3 seconds to show the text box
	
	SetText(renderer, "IDI NAHUI BLYAT"); // Incorrect render loop - this text gets layered on top of the previous text box.
	LoadTextBox(renderer, UIBatch, 24);
	SDL_RenderPresent(renderer);

	SDL_Delay(3000); // Wait for 3 seconds to show the text box

	SetText(renderer, "Ah nu cheeki breeki i v damke"); // Incorrect render loop - this text gets layered on top of the previous text box.
	LoadTextBox(renderer, UIBatch, 24);
	SDL_RenderPresent(renderer);
	// We need to call the residential scene here
	//scene bg residential_day
	//play audio t2
	startMusic("audio/bgm/2.ogg"); // start the music
	SDL_RenderPresent(renderer);
	
	
	SDL_RenderPresent(renderer);
	*/
	SDL_Delay(5000);
	
}
