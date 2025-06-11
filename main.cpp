// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 08/06/2025 //
// GAME IS COPYRIGHT TO TEAM SALVATO //

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_Audio.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "SpriteRenderer.h"
#include "SpriteLoader.h"
#include "audioDriver.h"
#include "chapters.h"
#include "DialogueSystem.h"
#include "cJSON.h" // Include cJSON for lazy loading

SpriteBatch* monikaBatch;               // Global variable to hold the monika batch
SpriteBatch* backgroundBatch;           // Global variable to hold the background batch
SpriteBatch* sayoriBatch;               // Global variable to hold the sayori batch
SpriteBatch* yuriBatch;                 // Global variable to hold the yuri batch
SpriteBatch* UIBatch;                   // Global variable to hold the UI batch
SpriteBatch* natsukiBatch;              // Global variable to hold the natsuki batch

SDL_Renderer* renderer;                 // Global variable to hold the renderer

TTF_Font* font;                         // Global variable to hold the font

DialogueSystem* dialogue = nullptr; // Pointer to the dialogue system
bool dialogueInitialized = false; // Flag to check if dialogue is initialized

int s = 2000;


bool initAudio() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
	}
    return true;
}

void InitDialogue(SDL_Renderer* renderer, TTF_Font* font) {
    dialogue = new DialogueSystem(renderer, font);
    dialogueInitialized = true; // Set the flag to true
    dialogue->AddLine("I LOVE YOU SUPAHAXOR", "Sayori", sayori4p);
    dialogue->AddLine("IDI NAHUI BLYAT", "Monika", monika1a);
    dialogue->AddLine("Ah nu cheeki breeki i v damke", "Sayori", sayori4p); // Lines for testing purposes, system will read each line at runtime.
    dialogue->AddLine("Need to write our names out SUPAHAXOR", "Monika", monika1b);
    dialogue->AddLine("Monika says some shit", " ", monika1c);
    dialogue->AddLine("Where is Yuri?", "Sayori", sayori4p);
    dialogue->AddLine("Monika couldn't move due to dodgy sprite logic", " ", monika1c);
	dialogue->AddLine("Monika is now moving", "Monika", monika1d);
	dialogue->AddLine("Sayori says some shit", "Sayori", sayori1a);  // As it stands, the system will only change expression if a name is provided.
	dialogue->AddLine("DEBUG", "Yuri", yuri1a); // This is a test line to see if the dialogue system works, it will not be displayed in the game.
    dialogue->AddLine("C++ gang rise up", "Natsuki", natsuki1a);
	dialogue->ChangeMusic("audio/bgm/1.ogg"); // Change the music to the first track in the game
    dialogue->AddLine("Booting into Doki Doki Literature Club...", "Monika", monika5a);
    dialogue->AddLine("For some reason this will not work when called elsewhere", "Yuri", yuri1a);
   
   
    // Debug mode over //

    // Current main issue is that this runs all at once, so the song is called immediately within the render loop.
    // Something called a "lazy loader" is required here.
    // Install cJSON to create the lazy loader.

	dialogue->AddLine("Song changed to 1.ogg", "Monika", monika1a); // This is a test line to see if the dialogue system works, it will not be displayed in the game.
    
}
bool initTTF() {                // Initialize the TTF library, will not work on a PS3 but for debugging purposes it is useful to have this function.
    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_AUDIO);
	initAudio();
    initTTF();
    font = TTF_OpenFont("font/Aller_Rg.ttf", 40);  // Problem with the ptsize variable
    InitDialogue(renderer, font);

   
    
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
       
        return 1;
    }
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }
	music = Mix_LoadMUS("audio/COMEUPOUTDAWAHTA.mp3");
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
    yuriBatch = LoadSpriteFolder("images/yuri", renderer);
	natsukiBatch = LoadSpriteFolder("images/natsuki", renderer); // Load the natsuki batch, will require tweaking for folders in the directory

	LoadAllTextures(renderer, backgroundBatch, monikaBatch, sayoriBatch, UIBatch, yuriBatch, natsukiBatch);   // Kind of pointless but it's a sanity check to make sure 
    //everything is loaded correctly.

    // Random debug statements here
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
    DrawSprites(renderer, spriteHead, spriteLeft, spriteRight, monikaTransform); // Debug - Renders monika 1a.
  
    SDL_RenderPresent(renderer);
    SDL_Delay(5000); // Wait for 5 seconds and then kill the music 
    //stopMusic(s);


    
    InitDialogue(renderer, font);
	ch_0(renderer, font); // Call the first chapter function

    // SLEEP TOMORROW BUT TONIGHT GO CRAZY, ALL YOU GOTTA DO IS MEET ME AT THE AHPAHTAHPAHTUH, APAHTAHPAHTUH, APAHTAHPAHTUH. 
    

    return 0;
}

