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
	FillSwarmVector(swarms); // fills Vector with swarms. Definition in StartPositions.h
	std::vector<Target> targets;
	FillTargetVector(targets);
	std::vector<Obstacle> obstacles;
	FillTargetVector(obstacles);

	std::ofstream prntpos;
	prntpos.open ("swarmPositions.txt");


	for (int sim_time = 0; sim_time < 1; ++sim_time) //time step. each iter is 0.001 sec
	{

		for (unsigned int mem = 0; mem < swarms.size(); mem++)
		{
			for (unsigned int tar = 0; tar < targets.size(); tar++)
			{
				swarms[mem].DistTar(targets[tar]);
				swarms[mem].DirTar(targets[tar]);
				prntpos << targets[tar].GetPos().x << " , " << targets[tar].GetPos().y << std::endl;
				prntpos << swarms[mem].GetPos().x << " , " << swarms[mem].GetPos().y << std::endl;
				prntpos << swarms[mem].GetDmt() << std::endl;
				prntpos << swarms[mem].GetDirTar().x << " , " << swarms[mem].GetDirTar().y << std::endl;
				prntpos <<  "  " << std::endl;
				swarms[mem].Step();
			}
		}

	}

	prntpos.close();
}

