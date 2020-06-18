#pragma once
//#include "Swarm.h"
#include "Vec2.h"

class Target
{
public:
	Target();
	Target(const Vec2& in_pos);
	~Target();

	//bool TestCollision(const Swarm& swarm)
	bool IsMapped();
	Vec2 GetPos() const;

private:
	Vec2 pos;
	bool isMapped = false;
};
