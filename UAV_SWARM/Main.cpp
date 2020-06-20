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

	for (int sim_time = 0; sim_time <= 30000; ++sim_time) //time step. each iter is 0.001 sec
	{
		for (unsigned int mem = 0; mem < swarms.size(); mem++) // change to range for loop?
		{
			Vec2 Nmt(0, 0);
			Vec2 Nmo(0, 0);
			Vec2 Nmm(0, 0);

			for (unsigned int tar = 0; tar < targets.size(); tar++)
			{
				swarms[mem].DistTar(targets[tar]);
				targets[tar].TestCollision(swarms[mem]);
				swarms[mem].DirTar(targets[tar]);
				swarms[mem].WgtDirTar();

				Nmt += swarms[mem].GetWgtDirTar(); // result for Nmt for one member
			}

			for (unsigned int obs = 0; obs < obstacles.size(); obs++)
			{
				swarms[mem].DistObs(obstacles[obs]); // may make TestCollision() for Swarm
				swarms[mem].DirObs(obstacles[obs]);
				swarms[mem].WgtDirObs();

				Nmo += swarms[mem].GetWgtDirObs(); // result for Nmt for one member
			}

			for (unsigned int mem2 = 0; mem2 < swarms.size(); mem2++) // add swarm id later?
				// if comparing to istelf, n_hat = Vec2(-nan(ind), -nan(ind))
			{
				swarms[mem].DistMem(swarms[mem2]);
				swarms[mem].DirMem(swarms[mem2]);
				swarms[mem].WgtDirMem();

				Nmm += swarms[mem].GetWgtDirMem(); // result for Nmt for one member
			}

			Vec2 WNmt = Nmt*Swarm::Wmt;
			Vec2 WNmo = Nmo*Swarm::Wmo;
			Vec2 WNmm = Nmm*Swarm::Wmm; // change to Swarm::Wmo later

			Vec2 Ntot = WNmt + WNmo + WNmo;
			Vec2 n_norm = Ntot / sqrt(pow(Ntot.x, 2.0f) + pow(Ntot.y, 2.0f));

			swarms[mem].Step(n_norm);

			// Removing swarm-members and Targets:
			for (unsigned int tars = 0; tars < targets.size(); tars++)
			{
				if (targets[tars].IsMapped())
				{
					std::cout << sim_time << ": " << targets.size() << std::endl;
					targets.erase(targets.begin() + tars);
				}
			}

			for (unsigned int mem = 0; mem < swarms.size(); mem++)
			{
				if (swarms[mem].IsImmobile())
				{
					//std::cout << swarms.size() << std::endl;
					swarms.erase(swarms.begin() + mem);
				}
			}

		}



		
		if (sim_time % 500 == 0)// print every n steps = 2
		{
			std::stringstream ss;
			ss << "results//sim-" << timestep << ".csv"; //outputs to results folder
			std::ofstream prntpos;
			prntpos.open(ss.str().c_str());


			for (unsigned int mem = 0; mem < swarms.size(); mem++)
			{
				prntpos << swarms[mem].GetPos().x << "," << swarms[mem].GetPos().y << std::endl;
			}

			prntpos << " " << std::endl;

			for (unsigned int tar = 0; tar < targets.size(); tar++)
			{
				prntpos << targets[tar].GetPos().x << "," << targets[tar].GetPos().y << std::endl;
			}
			prntpos.close();

			timestep += 1;
		}
	}
}

