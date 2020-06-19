#pragma once
#include "Vec2.h"

class Swarm; // Use of foward declaration here 
class Target
{
public:
	Target(const Vec2& in_pos);
	~Target();
	void TestCollision(const Swarm& swarm);
	bool IsMapped();
	Vec2 GetPos() const;

private:
	Vec2 pos;
	bool isMapped = false;
};
