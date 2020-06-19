#include "Target.h"
#include "Swarm.h"


Target::Target(const Vec2& in_pos)
{
    pos = in_pos;
}

Target::~Target()
{
}

void Target::TestCollision(const Swarm& swarm)
{
    isMapped = (swarm.GetDmt() <= 6);
}

bool Target::IsMapped()
{
    return isMapped;
}

Vec2 Target::GetPos() const
{
    return pos;
}
