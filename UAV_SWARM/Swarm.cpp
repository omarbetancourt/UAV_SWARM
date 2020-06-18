#include "Swarm.h"
#include "Target.h"
#include "Obstacle.h"
#include <cmath>

Swarm::Swarm()
{
}

Swarm::Swarm( const Vec2& in_pos, const Vec2& in_vel) // the constructor. Parameters in () will be values passed in when constructing
{
	pos = in_pos; // RHS variable are the private data members below
	vel = in_vel;
}

Swarm::~Swarm()
{
}


Vec2 Swarm::GetPos() const //getter function
{
    return pos;
}
Vec2 Swarm::GetVel() const
{
	return vel;
}
//
//float Swarm::GetY() const
//{
//    return y;
//}

void Swarm::Step()
{
	pos += vel*dt;
}

//void Swarm::DistTar(const Target& tar)
//{
//	dmtx2 = pow(tar.GetX() - x, 2.0f);
//	dmty2 = pow(tar.GetY() - y, 2.0f);
//	dmt2 = dmtx2 + dmty2;
//}

//void Swarm::DirTar()
//{
//	nxt = sqrt(dmtx2 / dmt2);
//	nyt = sqrt(dmty2 / dmt2);
//}
//
//float Swarm::WgtDirTar()
//{
//	const float dmt = sqrt(dmt2);
//
//	nhat_tx = (wt1 * exp(-a1 * dmt) - wt2 * exp(-a2 * dmt)) * nxt;
//	nhat_ty = (wt1 * exp(-a1 * dmt) - wt2 * exp(-a2 * dmt)) * nyt;
//	return 0.0;
//	// needs to return two numbers
//}
//
//void Swarm::SumWgtDirTar()
//{
//}

