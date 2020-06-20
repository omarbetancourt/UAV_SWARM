#include "Obstacle.h"
#include "Swarm.h"

Obstacle::Obstacle(const Vec3& in_pos)
{
	pos = in_pos;
}

Obstacle::~Obstacle()
{
}

bool Obstacle::TestCollision(const Swarm& swarm) const
{
	return  (swarm.GetDmo() <= Swarm::interaction_radius);;
}

Vec3 Obstacle::GetPos() const
{
	return pos;
}
