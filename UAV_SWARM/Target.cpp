#include "Target.h"

void Target::Init(float in_x, float in_y)
{
    x = in_x;
    y = in_y;
}

bool Target::IsMapped()
{
    return isMapped;
}

float Target::GetX() const
{
    return x;
}

float Target::GetY() const
{
    return y;
}
