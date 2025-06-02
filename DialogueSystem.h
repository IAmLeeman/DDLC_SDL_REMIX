// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 02/06/2025 //
// DialogueSystem.h // HEADER //

#ifndef DIALOGUESYSTEM_H			// You don't need both #ifndef and #pragma once - since this is going on a PS3, it's better to use #ifndef for compatibility
#define DIALOGUESYSTEM_H

#include "DialogueSystem.h"
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>



class DialogueSystem {
public:
	DialogueSystem(SDL_Renderer* renderer, TTF_Font* font);
	~DialogueSystem();

	void AddLine(const std::string& line);
	void Advance(SDL_Renderer* renderer);
	void Render(SDL_Renderer* renderer, int x, int y);
	bool IsFinished() const;

private:
	std::vector<std::string> dialogueLines;
	size_t currentLineIndex;
	SDL_Texture* currentTexture;
	TTF_Font* font;

	void UpdateTextTexture(SDL_Renderer* renderer);
};
	

#endif // DIALOGUESYSTEM_H
