#include "User.h"

User::User()
{}

User::User(Resources *res): res(res)
{
	tank = Tank(res, 0);
	tank.setX(WINDOW_WIDTH/2);
	tank.setY(WINDOW_HEIGHT - tank.getHeight());
}

float User::getX()
{
	return tank.getX();
}

float User::getY()
{
	return tank.getY();
}

void User::update()
{
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);
	int move = 0;
	
	if (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W]){
		move += MOVE_UP;
	}
	if (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S]){
		move += MOVE_DOWN;
	}
	if (keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A]){
		move += MOVE_LEFT;
	}
	if (keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D]){
		move += MOVE_RIGHT;
	}
	tank.move(move);
}

void User::draw()
{
	tank.draw();
}

