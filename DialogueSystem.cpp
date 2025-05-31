// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 30/05/2025 //
// DialogueSystem.cpp // C++ //

#include "DialogueSystem.h"
#include "SpriteRenderer.h"
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

extern SDL_Texture* textBoxTexture;


DialogueSystem::DialogueSystem(SDL_Renderer* renderer, TTF_Font* font)
	: currentLineIndex(0), currentTexture(nullptr), font(font)
	{
		
	}
DialogueSystem::~DialogueSystem() {
	if (currentTexture) {
		SDL_DestroyTexture(currentTexture);
		currentTexture = nullptr;
	}
	
}
void DialogueSystem::AddLine(const std::string& line) {
	dialogueLines.push_back(line);
}

void DialogueSystem::Advance(SDL_Renderer* renderer) {
	if (currentLineIndex < dialogueLines.size()) {
		if (currentTexture) {
			SDL_DestroyTexture(currentTexture);
			currentTexture = nullptr;
		}
		const std::string& line = dialogueLines[currentLineIndex];
		SDL_Color colour = { 255, 255, 255, 255 }; // White color

		SDL_Surface* surface = TTF_RenderText_Solid(font, line.c_str(), colour);
		if (!surface) {
			SDL_Log("Failed to create surface: %s", TTF_GetError());
			return;
		}
		currentTexture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);

		if (!currentTexture) {
			SDL_Log("Failed to create texture: %s", SDL_GetError());
			return;
		}
		currentLineIndex++; 
	
	}
}
void DialogueSystem::Render(SDL_Renderer* renderer, SDL_Rect* textRect) {
	if (currentTexture) {
		SDL_RenderCopy(renderer, currentTexture, nullptr, textRect);
	}
}
bool DialogueSystem::IsFinished() const {
	return currentLineIndex >= dialogueLines.size();
}