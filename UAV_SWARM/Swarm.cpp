#include "Swarm.h"
#include "Obstacle.h"
#include <cmath>

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


Vec2 Swarm::GetWgtDirTar() const
{
	return nhat_t;
}

void Swarm::Step() //good
{
	//pos += vel*dt;
	pos += nt_ij;


	//for later: if (vel >= max){ velnew = velold }
}

float Swarm::GetWmt()
{
	return Wmt;
}

void Swarm::DistTar(const Target& tar)// good
{
	const Vec2 delXY = tar.GetPos() - pos;
	dmt = sqrt((pow(delXY.x, 2.0f) + pow(delXY.y, 2.0f)));
}

Vec2 Swarm::DirTar(const Target& tar)
{
	const Vec2 delXY = tar.GetPos() - pos;
	return nt_ij = delXY/dmt;
}

Vec2 Swarm::WgtDirTar()
{
	return nhat_t = nt_ij * (wt1 * exp(-a1 * dmt) - wt2 * exp(-a2 * dmt));
}

