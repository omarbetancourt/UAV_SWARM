#pragma once
#include "Vec2.h"

class Swarm; // Use of foward declaration here 
class Target
{
public:
	Target(const Vec2& in_pos);
	~Target();

	bool TestCollision(const Swarm& swarm) const;
	bool IsMapped();
	Vec2 GetPos() const;

private:
	Vec2 pos;
	bool isMapped = false;
};
