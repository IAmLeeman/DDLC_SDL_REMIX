// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 14/06/2025 //
// DialogueSystem.cpp // C++ //

#include "DialogueSystem.h"
#include "SpriteRenderer.h"
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include "CharacterCodes.h"
#include "globals.h"
#include <iostream>
#include <SDL_mixer.h> // For music handling
#include <fstream> // For file handling
#include <optional> // For optional character expressions

extern SDL_Texture* textBoxTexture;
std::vector<CharacterCodes> characterExpressions;

SDL_Texture* monikaTexture = nullptr;
SDL_Texture* sayoriTexture = nullptr;
SDL_Texture* yuriTexture = nullptr;
SDL_Texture* natsukiTexture = nullptr;

SDL_Rect* monikaRect = nullptr;
SDL_Rect* sayoriRect = nullptr;
SDL_Rect* yuriRect = nullptr;
SDL_Rect* natsukiRect = nullptr;

Mix_Music* music = nullptr;
Mix_Music* currentMusic = nullptr;


DialogueSystem::DialogueSystem(SDL_Renderer* renderer, TTF_Font* font)
	: currentLineIndex(0), currentTexture(nullptr), font(font), nameTexture(nullptr)
	{
		
	}
DialogueSystem::~DialogueSystem() {
	if (currentTexture) {
		SDL_DestroyTexture(currentTexture);
		currentTexture = nullptr;
	}
	if (nameTexture) {
		SDL_DestroyTexture(nameTexture);
		nameTexture = nullptr;
	}
	
}
void DialogueSystem::AddLine(const std::string& line, const std::string& name, const CharacterCodes& characterExpressions) {
	dialogueLines.push_back(line);
	characterNames.push_back(name);
	characterExpressionsList.push_back(characterExpressions);
}

void DialogueSystem::Advance(SDL_Renderer* renderer) {
	if (currentLineIndex < dialogueLines.size()) {
		if (currentTexture) {
			SDL_DestroyTexture(currentTexture);
			currentTexture = nullptr;
		}
		const std::string& line = dialogueLines[currentLineIndex];
		const std::string& name = characterNames[currentLineIndex];
		const CharacterCodes& expressions = characterExpressionsList[currentLineIndex];

		std::cout << "Expression values: " << expressions.a << ", " 
			<< expressions.b << ", " << expressions.c << ", " 
			<< std::endl;

		// Set the character expression based on the current line index
		if (name == "Monika") {
			monikaTexture = expressions.draw(renderer, monikaBatch, monikaTransform); // Adjust for global transform
			int texWidth, texHeight;
			SDL_QueryTexture(monikaTexture, nullptr, nullptr, &texWidth, &texHeight);
			
			if (!monikaRect) {
				monikaRect = new SDL_Rect; // Initialize newRect if it doesn't exist
			}
			monikaRect->x = static_cast<int>(monikaTransform.x);
			std::cout << "Monika Rect X: " << monikaRect->x << std::endl;
			monikaRect->y = static_cast<int>(monikaTransform.y);
			std::cout << "Monika Rect Y: " << monikaRect->y << std::endl;
			monikaRect->w = texWidth;
			std::cout << "Monika Rect W: " << monikaRect->w << std::endl;
			monikaRect->h = texHeight;
			std::cout << "Monika Rect H: " << monikaRect->h << std::endl;


		}
		if (name == "Sayori") {
			sayoriTexture = expressions.draw(renderer, sayoriBatch, t44); // Adjust for global transform

			int texWidth, texHeight;
			SDL_QueryTexture(sayoriTexture, nullptr, nullptr, &texWidth, &texHeight);

			if (!sayoriRect) {
				sayoriRect = new SDL_Rect; // Initialize newRect if it doesn't exist
			}

			
			sayoriRect->x = static_cast<int>(t44.x);
			sayoriRect->y = static_cast<int>(t44.y);
			sayoriRect->w = texWidth;
			sayoriRect->h = texHeight;
		}
		if (name == "Yuri") {
			yuriTexture = expressions.draw(renderer, yuriBatch, t33); // Adjust for global transform
			int texWidth, texHeight;
			SDL_QueryTexture(yuriTexture, nullptr, nullptr, &texWidth, &texHeight);
			if (!yuriRect) {
				yuriRect = new SDL_Rect; // Initialize newRect if it doesn't exist
			}

			yuriRect->x = static_cast<int>(t33.x);
			yuriRect->y = static_cast<int>(t33.y);
			yuriRect->w = texWidth;
			yuriRect->h = texHeight;
		}
		if (name == "Natsuki") {
			natsukiTexture = expressions.draw(renderer, natsukiBatch, t33); // Adjust for global transform
			int texWidth, texHeight;
			SDL_QueryTexture(natsukiTexture, nullptr, nullptr, &texWidth, &texHeight);
			if (!natsukiRect) {
				natsukiRect = new SDL_Rect; // Initialize newRect if it doesn't exist
			}
			natsukiRect->x = static_cast<int>(t33.x);
			natsukiRect->y = static_cast<int>(t33.y);
			natsukiRect->w = texWidth;
			natsukiRect->h = texHeight;
		}
		

		SDL_Color white = { 255, 255, 255, 255 }; // White colour
		SDL_Color black = { 0,0,0,0 };				// Black

		int wrapLength = 800;

		
		SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(font, line.c_str(), white, wrapLength);
		SDL_Surface* nameSurface = TTF_RenderText_Solid(font, name.c_str(), black);

		if (!surface || !nameSurface) {
			SDL_Log("Failed to create surface: %s", TTF_GetError());
			return;
		}
		currentTexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
		nameTexture = SDL_CreateTextureFromSurface(renderer, nameSurface);

		if (!currentTexture) {
			SDL_Log("Failed to create texture: %s", SDL_GetError());
			return;
		}
		currentLineIndex++; 
	
	}
}
void DialogueSystem::Render(SDL_Renderer* renderer, int x, int y) {
	if (currentTexture) {
		int w, h;
		
		SDL_QueryTexture(currentTexture, nullptr, nullptr, &w, &h);
		
		SDL_Rect destRect = { x,y,w,h };
		SDL_RenderCopy(renderer, currentTexture, nullptr, &destRect);
		
	}
	if (nameTexture) {
		int w, h;
		SDL_QueryTexture(nameTexture, nullptr, nullptr, &w, &h);
		SDL_Rect destRect = { x,y-50,w,h };
		SDL_RenderCopy(renderer, nameTexture, nullptr, &destRect);
	}
}
void DialogueSystem::ChangeMusic(const char* file) {
	currentMusic = Mix_LoadMUS(file); // load the music file
	if (music == NULL) {
		std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
		return;
	}
}
bool DialogueSystem::IsFinished() const {
	return currentLineIndex >= dialogueLines.size();
}

void saveToFile(const std::string& filename, const std::string content) {
	std::ofstream outFile(filename);

	if (!outFile) {
		std::cerr << "Error opening file for writing: " << filename << std::endl;
		return;
	}

	outFile << content;
	outFile.close();

}