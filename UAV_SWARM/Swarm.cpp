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

void Swarm::DistObs(const Obstacle& obs)
{
	const Vec2 delXY = obs.GetPos() - pos;
	dmo = sqrt((pow(delXY.x, 2.0f) + pow(delXY.y, 2.0f)));

	if (dmo < interaction_radius)
	{
		isImmobile = true;
	}
}

Vec2 Swarm::DirTar(const Target& tar)
{
	const Vec2 delXY = tar.GetPos() - pos;
	return nt_ij = delXY / dmt;
}

Vec2 Swarm::DirObs(const Obstacle& obs)
{
	const Vec2 delXY = obs.GetPos() - pos;
	return no_ij = delXY / dmo;
}

Vec2 Swarm::WgtDirTar()
{
	return nhat_t = nt_ij * (wt1 * exp(-a1 * dmt) - wt2 * exp(-a2 * dmt));
}

Vec2 Swarm::WgtDirObs() // make this void private function?
{
	return nhat_o = no_ij * (wo1 * exp(-b1 * dmo) - wo2 * exp(-b2 * dmo));
}

Vec2 Swarm::GetPos() const //getter function
{
    return pos;
}

float Swarm::GetDmt() const
{
	return dmt;
}

float Swarm::GetDmo() const
{
	return dmo;
}


Vec2 Swarm::GetWgtDirTar() const
{
	return nhat_t;
}

Vec2 Swarm::GetWgtDirObs() const
{
	return nhat_o;
}

float Swarm::GetWmt() const
{
	return Wmt;
}

float Swarm::GetWmo() const
{
	return Wmo;
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

bool Swarm::IsImmobile()
{
	return isImmobile;
}

