#include"Romb.h"

Romb::Romb()
{
	this->visible = false;
	this->WasVisible = false;
	this->positionX = 0;
	this->positionY = 0;
	this->scale = 1;
	this->shootTime = 0;
	this->radius = 100;
	this->destroyed=false;
}
float Romb::getpositionX()
{
	return positionX;
}
float Romb::getpositionY()
{
	return positionY;
}
float Romb::getScale()
{
	return scale;
}
bool Romb::getvis()
{
	return visible;
}
bool Romb::getWasvis()
{
	return WasVisible;
}
void Romb::setpositionX(float x)
{
	this->positionX = x;
}
void Romb::setScale(float x)
{
	this->scale = x;
}
void Romb::setpositionY(float y)
{
	this->positionY = y;
}
void Romb::setvis(bool vis)
{
	this->visible = vis;
}
void Romb::setWasvis(bool Wasvis)
{
	this->WasVisible = Wasvis;
}

Romb::~Romb()
{
}