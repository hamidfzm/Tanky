#ifndef TILE_HH
#define TILE_HH

#include <SDL2/SDL.h>

// Constants
#include "Defines.h"

// Game Tools
#include "Timer.h"
#include "Utils.h"

// Game
#include "Resources.h"


class Tile
{
public:
	
	Tile();
	Tile(Resources *);
	void update();
	void draw();

private:
	Timer timerTile;

	int background[TILE_H][TILE_V][3];
	int nextTile;
	int nextTileStep;
	float currentY;
	float vy;
	float timeDelta;
	void nextTileReset();
	
	Resources *res;
	SDL_Rect body[6];
};

#endif // TILE_HH
