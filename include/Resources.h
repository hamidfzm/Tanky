#ifndef RESOURCES_H
#define RESOURCES_H

#include <SDL2/SDL.h>
#include <string.h>

// Game Tools
#include "Timer.h"

struct Resources
{
	SDL_Window *screen;
	SDL_Renderer * renderer;

	// event handler
	SDL_Event event;
	Timer timeDeltaTimer;
	float timeDelta;

	// Resources
	SDL_Texture *sprites_txt;
	TTF_Font *andy_fnt;
	TTF_Font *andy_fnt_min;
	
	// Colors
	SDL_Color white_clr = { 255, 255, 255, 255 };
	
	// Texts
	SDL_Texture *prompt_tex;
	SDL_Texture *continue_tex;

	std::string text;
};

#endif // RESOURCES_H
