#pragma once
#include "object2D.h"
#include "transform2D.h"
#include <string>
#include <vector>


class Romb {
public:
	Romb();
	float scale;
	float row;
	float shootTime;
	float radius;
	bool destroyed;
	float squareCost;
	float getpositionX();
	float getpositionY();
	float getScale();
	bool getvis();
	bool getWasvis();
	void setpositionX(float x);
	void setpositionY(float y);
	void setScale(float x);
	void setvis(bool vis);
	void setWasvis(bool Wasvis);
	~Romb();
private:
	bool visible;
	float positionX;
	float positionY;
	bool WasVisible;
	
};