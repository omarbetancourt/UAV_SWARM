#pragma once
#include "Vec2.h"
#include "Target.h"
#include "Obstacle.h"

class Swarm
{
public:
	Swarm(const Vec2& in_pos, const Vec2& in_vel);
	~Swarm();
	void DistTar(const Target& tar);
	void DistObs(const Obstacle& obs);		//4.5
	void DistMem(const Swarm& mem2);

	Vec2 DirTar(const Target& tar);
	Vec2 DirObs(const Obstacle& obs);
	Vec2 DirMem(const Swarm& mem2);

	Vec2 WgtDirTar();
	Vec2 WgtDirObs();
	Vec2 WgtDirMem();

	Vec2 GetPos() const; //To output to a file.

	float GetDmt() const;
	float GetDmo() const;
	float GetDmm() const;

	Vec2 GetWgtDirTar() const; // to set up Nmt
	Vec2 GetWgtDirObs() const;
	Vec2 GetWgtDirMem() const;

	float GetWmt() const; // to multiply to Nmt
	float GetWmo() const;
	float GetWmm() const;

	void Step(const Vec2& n_star);

	bool IsImmobile();

private:
	bool isImmobile = false;

	Vec2 pos;
	Vec2 vel;

	float dmt = 0.0f;
	float dmo = 0.0f;
	float dmm = 0.0f;

	Vec2 nt_ij;
	Vec2 no_ij;
	Vec2 nm_ij;

	Vec2 nhat_t;
	Vec2 nhat_o;
	Vec2 nhat_m;

	static constexpr float dt = 0.001f; 
	static constexpr float mass = 10.0f;
	static constexpr float thrustForce = 10000000.0f;
	static constexpr float vel_max = 100.0f;

	static constexpr float 
		a1 = 0.014f,
		a2 = 0.220f,
		b1 = 1.00f,
		b2 = 0.866f,
		c1 = 0.423f,
		c2 = 0.074f;

public:
	static constexpr float
		interaction_radius = 6.0f,

		wt1 = 0.355f,
		wt2 = 0.848f,
		Wmt = 2.10f,

		wo1 = 0.343f,
		wo2 = 1.07f,
		Wmo = 2.01f,

		wm1 = 0.521f,
		wm2 = 0.94f,
		Wmm = 4.51f;
};