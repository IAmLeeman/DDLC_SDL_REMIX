
//stop music fadeout 2.0  // Python script to  stop music with a two second fadeout
// rewritten in C++ and added a fadeout effect

#include <iostream>
#include "audioDriver.h"
#include <SDL_mixer.h>
#include "SpriteRenderer.h"
#include "globals.h"
#include "CharacterCodes.h"





void ch_0(SDL_Renderer* renderer){

	stopMusic(2000); // stop music with a 2 second fadeout
	SDL_RenderClear(renderer); // clear the screen
	SDL_RenderPresent(renderer); // This is required because of double buffering, a secret background buffer is cleared but not shown on the screen until this is called, yeah...

	// We need to call the residential scene here
	LoadBackground(renderer, backgroundBatch, 30); // Load the background image
	//scene bg residential_day
	//play audio t2
	startMusic("audio/bgm/2.ogg"); // start the music
	SDL_RenderPresent(renderer);
	//DrawSprites(renderer,); // Draw the background image

	
	sayori4p.draw(renderer, sayoriBatch); // Draws Sayori4p sprite
	SDL_RenderPresent(renderer);
	
	SDL_Delay(5000);

	

}
