#pragma once
#include "Vec2.h"

class Swarm; // Use of foward declaration here 
class Obstacle
{
public:
	Obstacle(const Vec2& in_pos);
	~Obstacle();

	bool TestCollision(const Swarm& swarm) const;

	Vec2 GetPos() const;
private:
	Vec2 pos;
};
