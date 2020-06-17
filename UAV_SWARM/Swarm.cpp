#include "Swarm.h"
#include <cmath>

Swarm::Swarm()
{
}

Swarm::Swarm(float in_x, float in_y, float in_vx, float in_vy) // the constructor. Parameters in () will be values passed in when constructing
{
	x = in_x; // RHS variable are the private data members below
	y = in_y; // 'in'_y means initial
	vx = in_vx;
	vy = in_vy;
}

Swarm::~Swarm()
{
}


float Swarm::GetX() const //getter function
{
    return x;
}

float Swarm::GetY() const
{
    return y;
}

void Swarm::Step()
{
    x += vx * dt;
    y += vy * dt;
}

void Swarm::DistTar(const Target& tar)
{
	dmtx2 = pow(tar.GetX() - x, 2.0f);
	dmty2 = pow(tar.GetY() - y, 2.0f);
	dmt2 = dmtx2 + dmty2;
}

void Swarm::DirTar()
{
	nxt = sqrt(dmtx2 / dmt2);
	nyt = sqrt(dmty2 / dmt2);
}

float Swarm::WgtDirTar()
{
	const float dmt = sqrt(dmt2);

	nhat_tx = (wt1 * exp(-a1 * dmt) - wt2 * exp(-a2 * dmt)) * nxt;
	nhat_ty = (wt1 * exp(-a1 * dmt) - wt2 * exp(-a2 * dmt)) * nyt;
	return 0.0;
	// needs to return two numbers
}

void Swarm::SumWgtDirTar()
{
}

