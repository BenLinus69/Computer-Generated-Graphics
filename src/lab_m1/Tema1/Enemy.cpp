#include"Enemy.h"

Enemy::Enemy()
{
	this->visible = false;
	this->WasVisible = false;
	this->positionX = 0;
	this->positionY = 0;
	this->translateX = 0;
	this->deleted = false;
	this->radius = 30;
	this->lives = 3;
	this->hasLived = true;
	this->scale = 1;
}

bool Enemy::getvis()
{
	return visible;
}
bool Enemy::getWasvis()
{
	return WasVisible;
}

void Enemy::setvis(bool vis)
{
	this->visible = vis;
}
void Enemy::setWasvis(bool Wasvis)
{
	this->WasVisible = Wasvis;
}

Enemy::~Enemy()
{
}