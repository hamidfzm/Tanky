#ifndef RESOURCES_H
#define RESOURCES_H

#include <SDL2/SDL.h>
#include <string.h>
#include <map>

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
	const SDL_Color white_clr = { 255, 255, 255, 255 };
	const SDL_Color black_clr = { 0, 0, 0, 0 };
	
	// Texts
	SDL_Texture *prompt_tex;
	SDL_Texture *continue_tex;
	SDL_Texture *start_tex;
	SDL_Texture *quit_tex;
	SDL_Texture *resume_tex;
	SDL_Texture *mainmenu_tex;

	std::string text;
	
	std::map<std::string, int> players;
};

#endif // RESOURCES_H
