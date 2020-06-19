#include "Target.h"
#include "Swarm.h"


Target::Target(const Vec2& in_pos)
{
    pos = in_pos;
}

Target::~Target()
{
}

bool Target::TestCollision(const Swarm& swarm) const
{
    return
        (swarm.GetDmt() <= 6);
}

bool Target::IsMapped()
{
    return isMapped;
}

Vec2 Target::GetPos() const
{
    return pos;
}
