#include "Tank.h"

SDL_Rect Tank::body[] = {	{671, 0, 75, 70},  // black
							{730, 340, 75, 70},  // beige
							{568, 440, 75, 70},  // red
							{671, 70, 75, 70},  // blue
							{669, 182, 75, 70}};  // green

SDL_Rect Tank::barrel[] = {	{840, 426, 16, 50},  // black
							{842, 108, 16, 50},  // beige
							{842, 158, 16, 50},  // red
							{850, 58, 16, 50},  // blue
							{834, 58, 16, 50}};  // green

SDL_Rect Tank::smoke[] = {	{324, 107, 92, 89},
							{396, 285, 90, 99}, 
							{590, 182, 79, 79}, 
							{128, 0, 100, 97}, 
							{226, 194, 98, 107},
							{418, 0, 87, 87}};

Tank::Tank()
{
}

Tank::Tank(Resources *res, const int kind) :kind(kind), res(res)
{
	x = y = angle = 0;
	setVX(1);
	setVY(1);
	fireFrame = 7;
}

void Tank::setX(const float x)
{
	this->x = x;
}

void Tank::setY(const float y)
{
	this->y = y;
}

void Tank::setVX(const float vx)
{
	
	this->vx = vx;
}

void Tank::setVY(const float vy)
{
	this->vy = vy;
}

void Tank::setAngle(const double angle)
{
	this->angle = angle;
}

float Tank::getX()
{
	return x;
}

float Tank::getY()
{
	return y;
}

float Tank::getVX()
{
	return vx;
}

float Tank::getVY()
{
	return vy;
}

float Tank::getWidth()
{
	return body[kind].w;
}

float Tank::getHeight()
{
	return body[kind].h;
}

float Tank::getBarrelHead()
{
	return y - barrel[kind].h - 5;
}

double Tank::getAngle()
{
	return angle;
}

SDL_Rect Tank::getBox()
{
	SDL_Rect box = { x - body[kind].w/2, y - body[kind].h/2, body[kind].w, body[kind].h};
	return box;
}

void Tank::fire()
{
	fireFrame = 0;
	fireFrameTimer.start();
}

void Tank::move(const int direction)
{
	if (direction & MOVE_UP){
		y -= (vy / BASE_TIME) * (res->timeDelta);
	} else if (direction & MOVE_DOWN){
		y += (vy / BASE_TIME) * (res->timeDelta);
	}

	if (direction & MOVE_LEFT){
		x -= (vx / BASE_TIME) * (res->timeDelta);
	} else if (direction & MOVE_RIGHT){
		x += (vx / BASE_TIME) * (res->timeDelta);
	}
}

void Tank::draw()
{
	renderTexture(res->sprites_txt, res->renderer, x - body[kind].w/2, y - body[kind].h/2, angle, &body[kind]);
	renderTexture(res->sprites_txt, res->renderer, x - barrel[kind].w/2, y - barrel[kind].h + 5, angle, barrel[kind].w/2, barrel[kind].h - 5, &barrel[kind]);
	
//	if (fireFrame < 7){
//		renderTexture(res->sprites_txt, res->renderer, x - smoke[kind].w/2 , y - 2 * body[kind].h, &smoke[fireFrame]);
//		if (fireFrameTimer.getTicks() > res->timeDelta / 4){
//			fireFrame++;
//			fireFrameTimer.start();
//		}
//	}
}