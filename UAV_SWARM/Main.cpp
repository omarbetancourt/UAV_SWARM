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
static constexpr unsigned int nObstacles = 100u;

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
			}

			for (unsigned int obs = 0; obs < obstacles.size(); obs++)
			{
				swarms[mem].DistObs(obstacles[obs]);
				swarms[mem].DirObs(obstacles[obs]);
				swarms[mem].WgtDirObs();

				//if (obstacles[obs].TestCollision(swarms[mem]))
				//{
				//	std::cout << sim_time << ": ";
				//	std::cout << obstacles[obs].GetPos().x << " , " << obstacles[obs].GetPos().y << std::endl;
				//	std::cout << swarms[mem].GetPos().x << " , " << swarms[mem].GetPos().y << std::endl;
				//	swarms.erase(swarms.begin() + mem);
				//	std::cout << swarms.size() << std::endl;
				//}

				Nmo += swarms[mem].GetWgtDirObs(); // result for Nmt for one member
			}

			// add other for loops here for obstacles

			Vec2 WNmt = Nmt*Swarm::Wmt;
			Vec2 WNmo = Nmo*Swarm::Wmo;
			Vec2 WNmm = Nmm*Swarm::Wmt; // change to Swarm::Wmo later

			Vec2 Ntot = WNmt + WNmo + WNmo;
			Vec2 n_norm = Ntot / sqrt(pow(Ntot.x, 2.0f) + pow(Ntot.y, 2.0f));

			swarms[mem].Step(n_norm);

			for (unsigned int tar = 0; tar < targets.size(); tar++)
			{
				if (targets[tar].IsMapped())
				{
					targets.erase(targets.begin() + tar);
				}
			}

			for (unsigned int tar = 0; tar < targets.size(); tar++)
			{
				if (targets[tar].IsMapped())
				{
					targets.erase(targets.begin() + tar);
				}
			}

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

