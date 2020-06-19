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

void Swarm::DistTar(const Target& tar)// good
{
	const Vec2 delXY = tar.GetPos() - pos;
	dmt = sqrt((pow(delXY.x, 2.0f) + pow(delXY.y, 2.0f)));
}

Vec2 Swarm::DirTar(const Target& tar)
{
	const Vec2 delXY = tar.GetPos() - pos;
	return nt_ij = delXY / dmt;
}

Vec2 Swarm::WgtDirTar()
{
	return nhat_t = nt_ij * (wt1 * exp(-a1 * dmt) - wt2 * exp(-a2 * dmt));
}

Vec2 Swarm::GetPos() const //getter function
{
    return pos;
}

float Swarm::GetDmt() const
{
	return dmt;
}


Vec2 Swarm::GetWgtDirTar() const
{
	return nhat_t;
}

float Swarm::GetWmt() const
{
	return Wmt;
}

void Swarm::Step(const Vec2& n_star) //good
{
	const Vec2 psiTot = n_star * thrustForce;
	vel += psiTot * dt / mass;
	const float mag_vel = sqrt(pow(vel.x, 2.0f) + pow(vel.y, 2.0f));
	const Vec2 dir_vel = vel / mag_vel;

	if (mag_vel >= vel_max)
	{
		vel = dir_vel*vel_max;
	}
	pos += vel * dt;
}

