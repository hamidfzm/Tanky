#ifndef USER_H
#define USER_H

#include <SDL2/SDL.h>
#include <iostream>
#include <string.h>

#include "Defines.h"

#include "Tank.h"

class User
{
public:
	User();
	User(Resources *);
	float getX();
	float getY();
	void update();
	void draw();
	
private:
	Resources *res;
	Tank tank;

};

#endif // USER_H
