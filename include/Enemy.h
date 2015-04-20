#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string.h>

#include "Defines.h"

#include "Tank.h"

class Enemy
{
public:
	Enemy();
	Enemy(Resources * , const int );
	float getX();
	float getY();
	SDL_Rect getBox();
	float getWidth();
	float getHeight();
	int getPower();
	void setX(const float);
	void setY(const float);
	void update();
	void draw();
	void Die();
	bool isDied();
	bool isDestroyed();
	
private:
	bool died;
	bool destroyed;
	Resources *res;
	Tank tank;
	int power;

};

#endif // ENEMY_H
