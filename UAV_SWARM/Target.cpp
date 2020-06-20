#include "Target.h"
#include "Swarm.h"


Target::Target(const Vec3& in_pos)
{
    pos = in_pos;
}

Target::~Target()
{
}

void Target::TestCollision(const Swarm& swarm)
{
    isMapped = (swarm.GetDmt() <= Swarm::interaction_radius);
}

bool Target::IsMapped()
{
    return isMapped;
}

Vec3 Target::GetPos() const
{
    return pos;
}
