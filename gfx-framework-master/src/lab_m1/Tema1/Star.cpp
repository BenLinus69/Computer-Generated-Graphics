#include"Star.h"

Star::Star()
{
	this->visible = false;
	this->WasVisible = false;
	this->deleted = false;
	this->positionX = 0;
	this->positionY = 0;
	this->radius = 16;
	this->hit = false;
}
bool Star::getvis()
{
	return visible;
}
bool Star::getWasvis()
{
	return WasVisible;
}
void Star::setvis(bool vis)
{
	this->visible = vis;
}
void Star::setWasvis(bool Wasvis)
{
	this->WasVisible = Wasvis;
}

Star::~Star()
{
}