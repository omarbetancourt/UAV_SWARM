#include <iostream>
#include "Swarm.h"
#include "Target.h"
#include "Obstacle.h"
#include <fstream>
#include "StartPositions.h"

int main()
{
	static constexpr int nSwarmMembers = 1u; //variable available at compile time to initialize size of array
	static constexpr int nTargets = 1u;
	static constexpr int nObstacles = 10u;

	Swarm swarms[nSwarmMembers];
	Target targets[nTargets];
	Obstacle obstacles[nObstacles];

	for (int i = 0; i < nSwarmMembers; ++i) // Initializing pos and v for swarms. Later needs to be initialized with constructor instead of this Init function
	{
		swarms[i].Init(xDist(rng), yDist(rng), vDist(rng), vDist(rng));
	}


	for (int i = 0; i < nTargets; ++i) // Initializing pos and v for swarms. Later needs to be initialized with constructor instead of this Init function
	{
		targets[i].Init(xtDist(rng), ytDist(rng)); 
	}

	for (int i = 0; i < nObstacles; ++i) // Initializing pos and v for swarms. Later needs to be initialized with constructor instead of this Init function
	{
		obstacles[i].Init(xoDist(rng), yoDist(rng));
	}

	std::ofstream prntpos;
	prntpos.open ("swarmPositions.txt");








	for (int sim_time = 1; sim_time < 10; ++sim_time) //time step. each iter is 0.001 sec
	{
		for (int swarmId = 0; swarmId < nSwarmMembers; ++swarmId)
		{
			for (int tarId = 0; tarId < nTargets; ++tarId)
			{
				swarms[swarmId].WgtDirTar();
				prntpos << swarmId << " , " << sim_time << " , " << swarms[swarmId].WgtDirTar() << " , " << swarms[swarmId].GetY() << std::endl;
			}
		}




		for (int swarmId = 0; swarmId < nSwarmMembers; ++swarmId)
		{
			swarms[swarmId].Step();
			//prntpos << swarmId << " , " << sim_time << " , " << swarms[swarmId].GetX() << " , " << swarms[swarmId].GetY() << std::endl;
		}





	}
	prntpos.close();

}