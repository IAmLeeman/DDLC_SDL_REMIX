
// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 24/07/2025 //
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
//#include <optional> // This is too complicated, just used a hacky workaround making NULL a transparent texture.
#include <string>

bool running = true;
bool waitingForAdvance = true;
bool mainMenu = false; // Flag to indicate if we are in the main menu#
bool firstRun = true; // Flag to indicate if this is the first run of the game

int index = 0; // Index for dialogue lines
int alpha = 0; // Alpha value for background texture

//SDL_Rect testRect = { 0, 0 , 1280, 720 };  // SO IT'S (X, Y, WIDTH, HEIGHT) // NOT (X, Y, XZOOM, YZOOM) // THIS AIN'T RENPY //

SDL_Event event;

const int FPS = 60;
const int frameDelay = 1000 / FPS;

static std::string lastSpriteStr = "";

std::string characterStr = "";
std::string emotionStr = "";

void parseNewLine(const char* dialogues[], int& index, SDL_Renderer* renderer) {

	if (dialogues[index] == nullptr) {
		firstRun = false;								// Not correct but for testing purposes it works.
		index = 0;										// Reset index to 0 for the next run
		return;											// No more dialogue to parse
	}
	cJSON* root = cJSON_Parse(dialogues[index]);

	cJSON* music = cJSON_GetObjectItem(root, "music");
	if (music && cJSON_IsString(music)) {
		std::string musicPath = music->valuestring;
		std::cout << "Music switching to: " << musicPath << std::endl;
		dialogue->ChangeMusic(music->valuestring);
		index++;
		cJSON_Delete(root); // Clean up the JSON object
		return;
	}
	cJSON* background = cJSON_GetObjectItem(root, "imgIndex");
	if (background && cJSON_IsString(background)) {
		std::string backgroundPath = background->valuestring;
		std::cout << "Background switching to: " << backgroundPath << std::endl;
		LoadBackground(renderer, backgroundBatch, std::stoi(background->valuestring), 255); // Load the background image
		index++;
		cJSON_Delete(root); // Clean up the JSON object
		return;
	}

	cJSON* command = cJSON_GetObjectItem(root, "command");
	if (command && cJSON_IsString(command)) {
		std::string commandStr = command->valuestring;
		if (commandStr == "show") {
			printf("Command 'show' detected, showing Sayori sprite.\n");
		}
		cJSON* character = cJSON_GetObjectItem(root, "character");
		if (character && cJSON_IsString(character)) {
			characterStr = std::string(character->valuestring);
		}
		cJSON* emotion = cJSON_GetObjectItem(root, "emotion");
		if (emotion && cJSON_IsString(emotion)) {
			emotionStr = std::string(emotion->valuestring);
		}
		else {
			std::cout << "No emotion specified, using default." << std::endl;
		}
		cJSON* transform = cJSON_GetObjectItem(root, "transform");
		if (transform && cJSON_IsString(transform)) {
			std::string transformStr = transform->valuestring;
		}
		else {
			std::cout << "No transform specified, using default." << std::endl;
		}
		std::string fullStr = characterStr + emotionStr;
		CharacterCodes code = getCharacterCodes(fullStr);
		dialogue->AddLine("Command executed: " + commandStr, characterStr, code); // Add the command to the dialogue system
		index++; // Increment the index to move to the next dialogue line
		cJSON_Delete(root); // Clean up the JSON object
		return;
	}
	cJSON* speaker = cJSON_GetObjectItem(root, "character");
	cJSON* text = cJSON_GetObjectItem(root, "text");
	cJSON* sprite = cJSON_GetObjectItem(root, "sprite"); // This puts in a string of "sayori4p" or "monika1a" etc, which is actually a CharacterCode enum value.

	std::string lineStr = (text && cJSON_IsString(text)) ? text->valuestring: "";
	std::string charName = (speaker && cJSON_IsString(speaker)) ? speaker->valuestring : "";
	std::string spriteStr = (sprite && cJSON_IsString(sprite)) ? sprite->valuestring : "";

	if (sprite && cJSON_IsString(sprite) && std::string(sprite->valuestring).find_first_not_of(" \t\n") != std::string::npos){
		spriteStr = sprite->valuestring;
		lastSpriteStr = spriteStr;
		}
	else {
		spriteStr = lastSpriteStr;

	}

	CharacterCodes anotherOne = getCharacterCodes(spriteStr);
	
	dialogue->AddLine(lineStr, charName, anotherOne); // sprite is not a string in this but a CharacterCode.
	std::cout << "Line added: " << lineStr << " by " << charName << " with sprite " << spriteStr << std::endl;
	
	std::cout << "Index incremented to: " << index << std::endl;
	index++;
	cJSON_Delete(root);
	return;
}

void HandleEventsAndAdvance(SDL_Renderer* renderer, bool& waitingForAdvance) {
	
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN && waitingForAdvance) {

			if (event.button.button == SDL_BUTTON_LEFT) {
				if (firstRun == true) {
					parseNewLine(firstRunDialogues, index, renderer);
					dialogue->Advance(renderer);
					waitingForAdvance = false; // Set to false to wait for the next click
				}
				else {
					parseNewLine(dialogues, index, renderer);
					dialogue->Advance(renderer);
					waitingForAdvance = false;
				}
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

		//if (backgroundTexture != currentBackgroundTexture) {
			
		//}

		if (firstRun == true) {

			HandleEventsAndAdvance(renderer, waitingForAdvance);
			

			SDL_RenderClear(renderer);
			
			LoadBackground(renderer, backgroundBatch, 39, alpha);
			LoadTextBox(renderer, UIBatch); // Load the text box
			CreateTextBox(renderer, UIBatch);
			dialogue->Render(renderer, textRect.x, textRect.y);
			SDL_RenderPresent(renderer);
			
			if (alpha < 255) {
				alpha++;
			}
			
			
		}
		else {
			
			HandleEventsAndAdvance(renderer, waitingForAdvance);
			SDL_RenderClear(renderer); // clear the screen

			SDL_SetTextureBlendMode(sayoriTexture, SDL_BLENDMODE_BLEND);  // Ratchet way of doing this, but it works for now
			SDL_SetTextureBlendMode(monikaTexture, SDL_BLENDMODE_BLEND);
			SDL_SetTextureBlendMode(yuriTexture, SDL_BLENDMODE_BLEND);
			SDL_SetTextureBlendMode(natsukiTexture, SDL_BLENDMODE_BLEND);

			LoadBackground(renderer, backgroundBatch, 30, 255); // Load the background image // alpha channel modifier added.

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
		}

		

		/*if (mainMenu == true) {
			dialogue->ChangeMusic("audio/bgm/1.ogg"); // Change to main menu music
			// Handle main menu logic here
			// 
			// For now, just break the loop to exit
			//SDL_Delay(1000); // Simulate a delay for the main menu
			continue;
		}*/

		

		

		Uint32 frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < frameDelay) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
}


