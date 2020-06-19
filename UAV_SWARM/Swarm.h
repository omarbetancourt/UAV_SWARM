#pragma once
#include "Vec2.h"
#include "Target.h"


class Swarm
{
public:
	Swarm(const Vec2& in_pos, const Vec2& in_vel);
	~Swarm();
	void DistTar(const Target& tar);
	Vec2 DirTar(const Target& tar);
	Vec2 WgtDirTar();
	Vec2 GetPos() const; //To output to a file.
	float GetDmt() const;
	Vec2 GetWgtDirTar() const; // to set up Nmt
	float GetWmt() const; // to multiply to Nmt

	void Step(const Vec2& n_star);
private:

	//void DistObs();		//4.5
	//void DirObs();		//4.6
	//void WgtDirObs();		//4.7
	//void SumWgtDirObs();	//4.8
	//asdfs 
	//void DistMem();		//4.9
	//void DirMem();		//4.10
	//void WgtDirMem();		//4.11
	//void SumWgtDirMem();	//4.12


private:
	Vec2 pos;
	Vec2 vel;

	float dmt = 0.0f;

	Vec2 nt_ij;
	Vec2 nhat_t;

	static constexpr float dt = 0.001f; 
	static constexpr float mass = 10.0f;
	static constexpr float thrustForce = 10000000.0f;
	static constexpr float vel_max = 100.0f;

	// Overall Weights:
	//static constexpr float Wmo = 
	//static constexpr float Wmm = 


	// Obstacle Weights:
	//static constexpr float wo1 = 
	//static constexpr float wo2 = 

	// Member Weights:
	//static constexpr float wm1 = 
	//static constexpr float wm2 = 

	// Decay Coefficients:
	static constexpr float a1 = 0.014f;
	static constexpr float a2 = 0.220f;
	//static constexpr float b1 = 
	//static constexpr float b2 = 
	//static constexpr float c1 = 
	//static constexpr float c2 =

public:
	static constexpr float
		wt1 = 0.355f,
		wt2 = 0.848f,
		Wmt = 2.10f;
};