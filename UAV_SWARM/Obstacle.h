#pragma once
#include "Vec2.h"

class Obstacle
{
public:
	Obstacle();
	Obstacle(const Vec2& in_pos);
	~Obstacle();

	Vec2 GetPos() const;
private:
	Vec2 pos;
};
