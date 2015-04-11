#ifndef USER_H
#define USER_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string.h>

#include "Defines.h"

#include "Timer.h"

#include "Tank.h"

class User
{
public:
	User();
	User(Resources *);
	float getX();
	float getY();
	float getBarrelHead();
	bool isFired();
	void update();
	void draw();
	
private:
	bool fired;
	
	Resources *res;
	Tank tank;
	Timer bulletTimer;

};

#endif // USER_H
