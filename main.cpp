// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 23/05/2025 //



#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_Audio.h>
#include <SDL_mixer.h>

#include "SpriteRenderer.h"
#include "SpriteLoader.h"
#include "audioDriver.h"
#include "chapters.h"

SpriteBatch* monikaBatch;               // Global variable to hold the monika batch
SpriteBatch* backgroundBatch;           // Global variable to hold the background batch

SDL_Renderer* renderer;                // Global variable to hold the renderer

SpriteBatch* sayoriBatch;               // Global variable to hold the sayori batch
SpriteBatch* UIBatch;                  // Global variable to hold the UI batch

int s = 2000;

bool initAudio() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
	}
    return true;
}

int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_AUDIO);
	initAudio();
    

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
       
        return 1;
    }
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }
	Mix_Music* music = Mix_LoadMUS("audio/COMEUPOUTDAWAHTA.mp3");
    if (!music) {
        printf("Failed to load music: %s\n", Mix_GetError());
    }

	Mix_PlayMusic(music, -1);
     
    SDL_Window* window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    //int itemsInFolder = countFilesInFolder("images/bg"); // really ratchet way of doing this, fix at some point.

    //std::cout << "Current items in background folder: " << itemsInFolder << std::endl; // This is not currently working. IT IS NOW.

    monikaBatch = LoadSpriteFolder("images/monika", renderer);
    backgroundBatch = LoadSpriteFolder("images/bg", renderer);
	sayoriBatch = LoadSpriteFolder("images/sayori", renderer);
	UIBatch = LoadSpriteFolder("gui", renderer); // Load the UI batch, will require tweaking for folders in the directory

	LoadAllTextures(renderer, backgroundBatch, monikaBatch, sayoriBatch, UIBatch);          // Kind of pointless but it's a sanity check to make sure everything is loaded correctly.


    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
    DrawSprites(renderer, spriteHead, spriteLeft, spriteRight);
  
    SDL_RenderPresent(renderer);
    SDL_Delay(5000); // Wait for 5 seconds and then kill the music 
    //stopMusic(s);
    

	ch_0(renderer); // Call the first chapter function


    /*

    // Load image
    SDL_Surface* surface = IMG_Load("420.jpg");  // Ensure image.bmp is in your project folder
    if (!surface) {
        std::cerr << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);  // No longer need the surface once we've created the texture.

    if (!texture) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Render the texture
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_Delay(10000);  // Wait for 10 seconds to show the image

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    */

    return 0;
}

