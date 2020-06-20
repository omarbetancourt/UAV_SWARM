#include "Swarm.h"
#include "Obstacle.h"
#include <cmath>

Swarm::Swarm( const Vec3& in_pos, const Vec3& in_vel) // the constructor. Parameters in () will be values passed in when constructing
{
	pos = in_pos; // LHS variable is the private data members below
	vel = in_vel;// RHS values passed in through Main.ccp
}

Swarm::~Swarm()
{
}

void Swarm::DistTar(const Target& tar)// good
{
	const Vec3 delXYZ = tar.GetPos() - pos;
	dmt = sqrt((pow(delXYZ.x, 2.0f) + pow(delXYZ.y, 2.0f) + pow(delXYZ.z, 2.0f)));
}

void Swarm::DistObs(const Obstacle& obs)
{
	const Vec3 delXYZ = obs.GetPos() - pos;
	dmo = sqrt((pow(delXYZ.x, 2.0f) + pow(delXYZ.y, 2.0f) + pow(delXYZ.z, 2.0f)));

	if (dmo <= interaction_radius) // make this function TestCollision
	{
		isImmobile = true;
	}
}

void Swarm::DistMem(const Swarm& mem2)
{
	const Vec3 delXYZ = mem2.GetPos() - pos;
	dmm = sqrt((pow(delXYZ.x, 2.0f) + pow(delXYZ.y, 2.0f) + pow(delXYZ.z, 2.0f)));

	// Could have immobile = true if swarms are too close to each other.
}

Vec3 Swarm::DirTar(const Target& tar)
{
	const Vec3 delXYZ = tar.GetPos() - pos;
	return nt_ij = delXYZ / dmt;
}

Vec3 Swarm::DirObs(const Obstacle& obs)
{
	const Vec3 delXYZ = obs.GetPos() - pos;
	return no_ij = delXYZ / dmo;
}

Vec3 Swarm::DirMem(const Swarm& mem2)
{
	const Vec3 delXYZ = mem2.GetPos() - pos;
	return nm_ij = delXYZ / dmm;
}

Vec3 Swarm::WgtDirTar()
{
	return nhat_t = nt_ij * (wt1 * exp(-a1 * dmt) - wt2 * exp(-a2 * dmt));
}

Vec3 Swarm::WgtDirObs() // make this void private function?
{
	return nhat_o = no_ij * (wo1 * exp(-b1 * dmo) - wo2 * exp(-b2 * dmo));
}

Vec3 Swarm::WgtDirMem()
{
	return nhat_m = nm_ij * (wm1 * exp(-c1 * dmm) - wm2 * exp(-c2 * dmm));
}

Vec3 Swarm::GetPos() const //getter function
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

float Swarm::GetDmm() const
{
	return dmm;
}


Vec3 Swarm::GetWgtDirTar() const
{
	return nhat_t;
}

Vec3 Swarm::GetWgtDirObs() const
{
	return nhat_o;
}

Vec3 Swarm::GetWgtDirMem() const
{
	return nhat_m;
}

float Swarm::GetWmt() const
{
	return Wmt;
}

float Swarm::GetWmo() const
{
	return Wmo;
}

float Swarm::GetWmm() const
{
	return Wmm;
}

void Swarm::Step(const Vec3& n_star)
{
	const Vec3 psiTot = n_star * thrustForce;
	vel += psiTot * dt / mass;
	const float mag_vel = sqrt(pow(vel.x, 2.0f) + pow(vel.y, 2.0f) + pow(vel.z, 2.0f));
	const Vec3 dir_vel = vel / mag_vel;

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

