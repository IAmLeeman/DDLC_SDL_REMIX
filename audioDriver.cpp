// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 25/05/2025 //
// audioDriver.cpp // C++ //

#include <SDL.h>
#include <SDL_audio.h>
#include <iostream>
#include <SDL_mixer.h>

// AUDIO CHANGER, TO BE COMPLETED

void stopMusic(int s) {
	Mix_FadeOutMusic(s); // stop the music
	return;
}

void startMusic(const char* file) {
	Mix_Music* music = Mix_LoadMUS(file); // load the music file
	if (music == NULL) {
		std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
		return;
	}
	Mix_PlayMusic(music, -1); // play the music indefinitely
	return;
}