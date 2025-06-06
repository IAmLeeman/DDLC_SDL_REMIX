// DOKI DOKI LITERATURE CLUB //
// PS3 PORT // SDL REMIX
// SUPAHAXOR // 25/05/2025 //
// audioDriver.cpp // C++ //

#include <SDL.h>
#include <SDL_audio.h>
#include <iostream>
#include <SDL_mixer.h>
#include "audioDriver.h"

// AUDIO CHANGER, TO BE COMPLETED



void stopMusic(int s) {
	Mix_FadeOutMusic(s); // stop the music
	return;
}