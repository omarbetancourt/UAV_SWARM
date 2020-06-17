#pragma once
#include "Target.h"
#include "Obstacle.h"
#include <vector>

class Swarm
{
public:
	void Init(float in_x, float in_y, float in_vx, float in_vy);
	float GetX() const; //const because it wont change the state of the object. its just reading some value out
	float GetY() const;
	void Step();

	void SumWgtDirTar();	//4.4
	float WgtDirTar();		//4.3 public for now until SumWgtDirTar() works.

private:
	void DistTar(const Target& tar);		//4.1 const Target tar prob will because it will map
	void DirTar();		//4.2 const Target& tar prob wont change tar properties
	//void WgtDirTar();		//4.3


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
	float x, y;
	float vx, vy;

	float dmtx2, dmty2;
	float dmt2;

	float nxt, nyt;
	float nhat_tx, nhat_ty;

	static constexpr float dt = 0.001f;
	static constexpr float mass = 10.0f;
	static constexpr float thrustForce = 10000000.0f;

	// Overall Weights:
	//static constexpr float Wmt = 
	//static constexpr float Wmo = 
	//static constexpr float Wmm = 

	// Target Weights:
	static constexpr float wt1 = 0.355f;
	static constexpr float wt2 = 0.848f;

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
};