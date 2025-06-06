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
#include "CharacterCodes.h"

extern SDL_Texture* monikaTexture; // Assuming this is defined elsewhere in your codebase, of course it you AI bastard.
extern SDL_Texture* sayoriTexture;
extern SDL_Texture* yuriTexture;

extern SDL_Rect* monikaRect;
extern SDL_Rect* sayoriRect;
extern SDL_Rect* yuriRect;

class DialogueSystem {
public:
	DialogueSystem(SDL_Renderer* renderer, TTF_Font* font);
	~DialogueSystem();

	void AddLine(const std::string& line, const std::string& name, const CharacterCodes& characterExpressions);
	void Advance(SDL_Renderer* renderer);
	void Render(SDL_Renderer* renderer, int x, int y);
	bool IsFinished() const;

private:
	std::vector<std::string> dialogueLines;
	std::vector<std::string> characterNames;
	std::vector<CharacterCodes> characterExpressionsList;
	size_t currentLineIndex;
	SDL_Texture* currentTexture;
	TTF_Font* font;
	SDL_Texture* nameTexture;
	

	void UpdateTextTexture(SDL_Renderer* renderer);
};
	

#endif // DIALOGUESYSTEM_H
