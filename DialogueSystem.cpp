// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 02/06/2025 //
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

extern SDL_Texture* textBoxTexture;
std::vector<CharacterCodes> characterExpressions;

SDL_Texture* monikaTexture = nullptr;
SDL_Texture* sayoriTexture = nullptr;

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
			monikaTexture = expressions.draw(renderer, monikaBatch, monikaTransform);

		}
		if (name == "Sayori") {
			sayoriTexture = expressions.draw(renderer, sayoriBatch, t44); // Adjust for global transform
		}
		

		SDL_Color white = { 255, 255, 255, 255 }; // White colour
		SDL_Color black = { 0,0,0,0 };				// Black

		SDL_Surface* surface = TTF_RenderText_Solid(font, line.c_str(), white);
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
bool DialogueSystem::IsFinished() const {
	return currentLineIndex >= dialogueLines.size();
}