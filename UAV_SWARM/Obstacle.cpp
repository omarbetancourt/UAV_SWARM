#include "Obstacle.h"
#include "Swarm.h"

Obstacle::Obstacle(const Vec2& in_pos)
{
	pos = in_pos;
}

Obstacle::~Obstacle()
{
}

bool Obstacle::TestCollision(const Swarm& swarm) const
{
	return  (swarm.GetDmo() <= 6);;
}

Vec2 Obstacle::GetPos() const
{
	return pos;
}
