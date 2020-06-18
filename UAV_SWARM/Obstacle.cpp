#include "Obstacle.h"

Obstacle::Obstacle()
{
}

Obstacle::Obstacle(const Vec2& in_pos)
{
	pos = in_pos;
}

Obstacle::~Obstacle()
{
}

Vec2 Obstacle::GetPos() const
{
	return pos;
}
