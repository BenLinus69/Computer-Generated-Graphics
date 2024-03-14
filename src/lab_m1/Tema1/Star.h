#pragma once
#include "object2D.h"
#include "transform2D.h"
#include <string>
#include <vector>


class Star {
public:
	Star();
	float positionX;
	float positionY;
	bool deleted;
	float starmove;
	float rotate;
	float movingPositionX;
	float radius;
	float rowNumber;
	bool hit;
	bool getvis();
	bool getWasvis();
	void setvis(bool vis);
	void setWasvis(bool Wasvis);
	~Star();
private:
	bool visible;
	
	bool WasVisible;
};