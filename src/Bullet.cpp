#include "Bullet.h"

SDL_Rect Bullet::body[] = {	{84, 481, 12, 26},  // silver
							{48, 481, 12, 26},  // beige
							{120, 481, 12, 26},  // red
							{0, 481, 12, 26},  // blue
							{96, 481, 12, 26},  // yellow
							{24, 481, 12, 26}};  // green

Bullet::Bullet()
{
}

bool Bullet::isDestroyed()
{
	return destroyed;
}

void Bullet::Destroy()
{
	destroyed = true;
}

Bullet::Bullet(Resources *res, const int kind, const int direction, const int x, const int  y) :kind(kind), res(res), direction(direction), x(x), y(y)
{
	if (direction & MOVE_UP){
		angle = 0;
	} else {
		angle = 180;
	}
	
	destroyed = false;
	setVX(1);
	setVY(1);
}

void Bullet::setX(const float x)
{
	this->x = x;
}

void Bullet::setY(const float y)
{
	this->y = y;
}

void Bullet::setVX(const float vx)
{
	
	this->vx = vx;
}

void Bullet::setVY(const float vy)
{
	this->vy = vy;
}

void Bullet::setAngle(const double angle)
{
	this->angle = angle;
}

float Bullet::getX()
{
	return x;
}

float Bullet::getY()
{
	return y;
}

float Bullet::getVX()
{
	return vx;
}

float Bullet::getVY()
{
	return vy;
}

float Bullet::getWidth()
{
	return body[kind].w;
}

float Bullet::getHeight()
{
	return body[kind].h;
}

double Bullet::getAngle()
{
	return angle;
}


SDL_Rect Bullet::getBox()
{
	SDL_Rect box = { x - body[kind].w/2, y - body[kind].h/2, body[kind].w, body[kind].h};
	return box;
}

void Bullet::update()
{
	if (y > WINDOW_HEIGHT + getWidth() || y < -getWidth()){
		Destroy();
	}

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


void Bullet::draw()
{
	renderTexture(res->sprites_txt, res->renderer, x - body[kind].w/2, y - body[kind].h/2, angle, &body[kind]);
}