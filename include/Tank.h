#ifndef TANK_H
#define TANK_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string.h>

// Constants
#include "Defines.h"

// Game Tools
#include "Utils.h"
#include "Timer.h"

// Game
#include "Resources.h"

class Tank
{
public:
	Tank();
	Tank(Resources *, const int);
	float getX();
	float getY();
	float getVX();
	float getVY();
	float getWidth();
	float getHeight();
	double getAngle();
	
	void setX(const float);
	void setY(const float);
	void setVX(const float);
	void setVY(const float);
	void setAngle(const double);
	void move(const int);
	void draw();

private:
	Resources *res;
	static SDL_Rect body[];
	static SDL_Rect barrel[];
	int kind;
	float x, y, vx, vy;
	double angle;
};

#endif // TANK_H
