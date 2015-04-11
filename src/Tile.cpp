#include "Tile.h"


Tile::Tile()
{
}


Tile::Tile(Resources *res): res(res)
{
	body[0].x = 0;
	body[0].y = 0;
	body[0].w = 128;
	body[0].h = 128;

	body[1].x = 0;
	body[1].y = 128;
	body[1].w = 128;
	body[1].h = 128;

	body[2].x = 0;
	body[2].y = 256;
	body[2].w = 128;
	body[2].h = 128;
	
	nextTileReset();
	currentY = 0;
	vy = 2.5;
	timeDelta = BASE_TIME / vy;
	timerTile.start();
	
	for(int i=0; i < TILE_H; i++)
	{
		for(int j=0; j < TILE_V; j++)
		{
			background[i][j][0] = nextTile;
		}
	}

}


void Tile::nextTileReset()
{
	nextTile = random(0, 3);
	nextTileStep = random(5, 11);
}


void Tile::update()
{
		if (timerTile.getTicks()  >= res->timeDelta){
		// shift

		int temp[TILE_V][2];
		
		if (nextTileStep == 0){
			nextTileReset();
		}

		for(int j=0; j < TILE_V; j++)
		{
			temp[j][0] = background[0][j][0];
			background[0][j][0] = nextTile;
		}
		nextTileStep--;
		
		for(int i=1; i < TILE_H; i++)
		{
			for(int j=0; j < TILE_V; j++)
			{
				temp[j][1] = background[i][j][0];
				background[i][j][0] = temp[j][0];
				temp[j][0] = temp[j][1];
			}
		}

		timerTile.start();
	}
	
	currentY = TILE_HEIGHT * (timerTile.getTicks() / res->timeDelta);
}


void Tile::draw()
{
	for(int i=0; i < TILE_H; i++)
	{
		for(int j=0; j < TILE_V; j++)
		{
			renderTexture(res->sprites_txt, res->renderer, j * TILE_WIDTH, (i-1) * TILE_HEIGHT + currentY, &body[background[i][j][0]]);
		}
	}
}