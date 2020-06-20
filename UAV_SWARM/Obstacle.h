#pragma once
#include "Vec3.h"

class Swarm; // Use of foward declaration here 
class Obstacle
{
public:
	Obstacle(const Vec3& in_pos);
	~Obstacle();

	bool TestCollision(const Swarm& swarm) const;

	Vec3 GetPos() const;
private:
	Vec3 pos;
};
