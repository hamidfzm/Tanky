#include "Enemy.h"

Enemy::Enemy()
{}

Enemy::Enemy(Resources *res, const int type): res(res)
{
	tank = Tank(res, type);
	tank.setAngle(180);
	tank.setY(0);
}

float Enemy::getX()
{
	return tank.getX();
}

float Enemy::getY()
{
	return tank.getY();
}

float Enemy::getWidth()
{
	return tank.getWidth();
}

float Enemy::getHeight()
{
	return tank.getHeight();
}

void Enemy::setX(const float x)
{
	tank.setX(x);
}

void Enemy::setY(const float y)
{
	tank.setY(y);
}


void Enemy::update()
{
	tank.move(MOVE_DOWN);
}

void Enemy::draw()
{
	tank.draw();
}
