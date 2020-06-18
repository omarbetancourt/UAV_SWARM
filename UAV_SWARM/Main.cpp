//#include <iostream>
#include "Vec2.h"
#include <random>
#include "Swarm.h"
#include "Target.h"
#include "Obstacle.h"
#include <fstream>

static constexpr unsigned int nSwarmMembers = 1u; //variable available at compile time
static constexpr unsigned int nTargets = 1u;
static constexpr unsigned int nObstacles = 10u;

#include "StartPositions.h"


int main()
{
	std::vector<Swarm> swarms; // vector of objects. Initialized with size nSwarmMembers and entries ar all 0;
	FillSwarmVector(swarms); //calling
	//Swarm swarms[nSwarmMembers];
	//Target targets[nTargets];
	//Obstacle obstacles[nObstacles];

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
			prntpos << " , " << swarms[member].GetVel().x << " , " << swarms[member].GetVel().y << " , " << swarms[member].GetPos().x << " , " << swarms[member].GetPos().y << std::endl;
		}





	}
	prntpos.close();

}

