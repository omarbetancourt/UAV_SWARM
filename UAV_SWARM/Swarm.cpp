#include "Swarm.h"
#include "Obstacle.h"
#include <cmath>

Swarm::Swarm()
{
}

Swarm::Swarm( const Vec2& in_pos, const Vec2& in_vel) // the constructor. Parameters in () will be values passed in when constructing
{
	pos = in_pos; // LHS variable is the private data members below
	vel = in_vel;// RHS values passed in through Main.ccp
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

void Swarm::Step()
{
	pos += vel*dt;
}

float Swarm::GetDmt()
{
	return dmt;
}

void Swarm::DistTar(const Target& tar)
{
	const Vec2 delXY = tar.GetPos() - pos;
	dmt = sqrt((pow(delXY.x, 2.0f) + pow(delXY.y, 2.0f)));
}

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

