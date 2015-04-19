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
	void setX(const float);
	void setY(const float);
	void update();
	void draw();
	void Die();
	
private:
	bool died;
	Resources *res;
	Tank tank;

};

#endif // ENEMY_H
