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
	float getBarrelHead();
	SDL_Rect getBox();
	
	void setX(const float);
	void setY(const float);
	void setVX(const float);
	void setVY(const float);
	void setAngle(const double);
	void fire();
	void move(const int);
	void draw();

private:
	Resources *res;
	static SDL_Rect body[];
	static SDL_Rect barrel[];
	static SDL_Rect smoke[];
	int kind;
	int fireFrame;
	Timer fireFrameTimer;
	float x, y, vx, vy;
	double angle;
};

#endif // TANK_H
