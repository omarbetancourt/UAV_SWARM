#pragma once
//#include "Swarm.h"

class Target
{
public:
	void Init(float in_x, float in_y);
	//bool TestCollision(const Swarm& swarm)
	bool IsMapped();
	float GetX() const;
	float GetY() const;

private:
	float x;
	float y;
	bool isMapped = false;
};
