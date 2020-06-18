#include "Target.h"

Target::Target()
{
}

Target::Target(const Vec2& in_pos)
{
    pos = in_pos;
}

Target::~Target()
{
}

bool Target::IsMapped()
{
    return isMapped;
}

Vec2 Target::GetPos() const
{
    return pos;
}
