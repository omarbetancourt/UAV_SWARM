#pragma once
#include "Vec3.h"

class Swarm; // Use of foward declaration here 
class Target
{
public:
	Target(const Vec3& in_pos);
	~Target();
	void TestCollision(const Swarm& swarm);

	bool IsMapped();
	Vec3 GetPos() const;

private:
	Vec3 pos;
	bool isMapped = false;
};
