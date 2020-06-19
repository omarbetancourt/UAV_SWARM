#include "Vec2.h"
#include <random>
#include "Swarm.h"
#include "Target.h"
#include "Obstacle.h"
#include <fstream>
#include <iostream>
#include <sstream>

static constexpr unsigned int nSwarmMembers = 100u; //variable available at compile time
static constexpr unsigned int nTargets = 100u;
static constexpr unsigned int nObstacles = 1u;

#include "StartPositions.h"

int main()
{
	std::vector<Swarm> swarms; // vector of objects. Initialized with size nSwarmMembers and entries ar all 0;
	FillSwarmVector(swarms); // fills Vector with swarms. Definition in StartPositions.h
	std::vector<Target> targets;
	FillTargetVector(targets);
	std::vector<Obstacle> obstacles;
	FillTargetVector(obstacles);  
	int timestep = 0; //might change to file name later.

	for (int sim_time = 0; sim_time <= 100; ++sim_time) //time step. each iter is 0.001 sec
	{

		for (unsigned int mem = 0; mem < swarms.size(); mem++)
		{
			Vec2 Nmt(0, 0);
			Vec2 Nmo(0, 0);
			Vec2 Nmm(0, 0);

			for (unsigned int tar = 0; tar < targets.size(); tar++)
			{
				swarms[mem].DistTar(targets[tar]);
				swarms[mem].DirTar(targets[tar]);
				swarms[mem].WgtDirTar();
				
				Nmt += swarms[mem].GetWgtDirTar(); // result for Nmt for one member

				if (targets[tar].TestCollision(swarms[mem]))
					{
						std::cout << sim_time << ": ";
						std::cout << targets[tar].GetPos().x << " , " << targets[tar].GetPos().y << std::endl;
						std::cout << swarms[mem].GetPos().x << " , " << swarms[mem].GetPos().y << std::endl;
						targets.erase(targets.begin() + tar);
						std::cout << targets.size() << std::endl;
					}
			}

			// add other for loops here for obstacles

			Vec2 WNmt = Nmt*Swarm::Wmt;
			Vec2 WNmo = Nmo*Swarm::Wmt;
			Vec2 WNmm = Nmm*Swarm::Wmt; // change Swarm::Wmt later

			Vec2 Ntot = WNmt + WNmo + WNmo;
			Vec2 n_norm = Ntot / sqrt(pow(Ntot.x, 2.0f) + pow(Ntot.y, 2.0f));

			swarms[mem].Step(n_norm);


		}

		
		//if (sim_time % 1 == 0)// print every n steps = 2
		//{
		//	std::stringstream ss;
		//	ss << "results//sim-" << timestep << ".csv"; //outputs to results folder
		//	std::ofstream prntpos;
		//	prntpos.open(ss.str().c_str());
		//	timestep += 1;

		//	//for (unsigned int mem = 0; mem < swarms.size(); mem++)
		//	//{
		//	//	prntpos << sim_time << swarms[mem].GetPos().x << "," << swarms[mem].GetPos().y << std::endl;
		//	//}

		//	for (unsigned int tar = 0; tar < targets.size(); tar++)
		//	{
		//		prntpos << sim_time << targets[tar].GetPos().x << "," << targets[tar].GetPos().y << std::endl;
		//	}
		//	prntpos.close();
		//}
	}
}

