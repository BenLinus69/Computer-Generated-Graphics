#pragma once
#include "object2D.h"
#include "transform2D.h"
#include <string>
#include <vector>

class Enemy {
public:
	float positionX;
	float positionY;
	float translateX;
	bool deleted;
	float rowNumber;
	float movingPositionX;
	float radius;
	float lives;
	bool hasLived;
	float scale;
	Enemy();
	bool getvis();
	bool getWasvis();
	void setvis(bool vis);
	void setWasvis(bool Wasvis);
	~Enemy();
private:
	bool visible;
	bool WasVisible;
};