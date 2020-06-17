#include <iostream>
#include "Swarm.h"
#include "Target.h"
#include "Obstacle.h"
#include <fstream>
#include "StartPositions.h"




int main()
{
	static constexpr int nSwarmMembers = 3u; //variable available at compile time to initialize size of array
	static constexpr int nTargets = 1u;
	static constexpr int nObstacles = 10u;

	//Swarm swarms[nSwarmMembers];

	std::vector<Swarm> swarms; // vector of objects. Initialized with size nSwarmMembers and entries ar all 0;
	//Target targets[nTargets];
	//Obstacle obstacles[nObstacles];

	for (unsigned int mem = 0; mem < nSwarmMembers; mem++) // Initializing pos and v for swarms. Later needs to be initialized with constructor instead of this Init function
	{
		Swarm swarm(xDist(rng), yDist(rng), vDist(rng), vDist(rng));
		swarms.push_back(swarm);
	}


	//for (int i = 0; i < nTargets; ++i) // Initializing pos and v for swarms. Later needs to be initialized with constructor instead of this Init function
	//{
	//	targets[i].Init(xtDist(rng), ytDist(rng)); 
	//}

	//for (int i = 0; i < nObstacles; ++i) // Initializing pos and v for swarms. Later needs to be initialized with constructor instead of this Init function
	//{
	//	obstacles[i].Init(xoDist(rng), yoDist(rng));
	//}

	std::ofstream prntpos;
	prntpos.open ("swarmPositions.txt");








	for (int sim_time = 1; sim_time < 10; ++sim_time) //time step. each iter is 0.001 sec
	{
		//for (int swarmId = 0; swarmId < nSwarmMembers; ++swarmId)
		//{
		//	for (int tarId = 0; tarId < nTargets; ++tarId)
		//	{
		//		//swarms[swarmId].WgtDirTar();
		//		//prntpos << swarmId << " , " << sim_time << " , " << swarms[swarmId].WgtDirTar() << " , " << swarms[swarmId].GetY() << std::endl;
		//	}
		//}




		for (unsigned int member = 0; member < swarms.size(); member++)
		{
			swarms[member].Step();
			prntpos << member << " , " << sim_time << " , " << swarms[member].GetX() << " , " << swarms[member].GetY() << std::endl;
		}





	}
	prntpos.close();

}