#ifndef BULLET_H
#define BULLET_H

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

class Bullet
{
public:
	Bullet();
	Bullet(Resources *, const int, const int, const int, const int);
	float getX();
	float getY();
	float getVX();
	float getVY();
	float getWidth();
	float getHeight();
	SDL_Rect getBox();
	double getAngle();
	
	void setX(const float);
	void setY(const float);
	void setVX(const float);
	void setVY(const float);
	void setAngle(const double);
	void update();
	void draw();

private:
	Resources *res;
	static SDL_Rect body[];
	int kind;
	int direction;
	float x, y, vx, vy;
	double angle;
};

#endif // BULLET_H
