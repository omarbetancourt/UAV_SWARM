/* This code is an implementation of The Game of Drones: rapid agent-based machine-learning models for multi-UAV path planning
by T. I. Zohdi. 2019 ( https://doi.org/10.1007/s00466-019-01761-9 )*/
#include "Vec3.h"
#include <random>
#include "Swarm.h"
#include "Target.h"
#include "Obstacle.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "StartPositions.h"

int main()
{
	// Create vectors of agents. Initialized in StartPositions.h;
	std::vector<Swarm> swarm; 
	FillSwarmVector(swarm); 
	std::vector<Target> targets;
	FillTargetVector(targets);
	std::vector<Obstacle> obstacles;
	FillTargetVector(obstacles);  

	unsigned int maxSimTime = 30000; // ms
	unsigned int outputFile = 0;

	for (int sim_time = 0; sim_time <= maxSimTime; ++sim_time)		// Each iteration is 0.001 sec
	{
		for (unsigned int mem = 0; mem < swarm.size(); mem++)		// Iterating through each swarm-member
		{
			// Initializing interaction parameters: Nmt, Nmo, Nmm
			Vec3 Nmt(0, 0, 0);
			Vec3 Nmo(0, 0, 0);
			Vec3 Nmm(0, 0, 0);

			// Member-target interaction	( Section 4.1 )
			for (unsigned int tar = 0; tar < targets.size(); tar++)	// Iterating through each target
			{
				swarm[mem].DistTar(targets[tar]);					// Distance to target						( Eq. 4.1 )
				targets[tar].TestCollision(swarm[mem]);				// Checking if target is mapped				( Eq. 5.1 ) 
				swarm[mem].DirTar(targets[tar]);					// Directed normal to target				( Eq. 4.2 )
				swarm[mem].WgtDirTar();								// Weighted directed normal to target		( Eq. 4.3 )
				Nmt += swarm[mem].GetWgtDirTar();					// Member-target interaction parameter		( Eq. 4.4 )
			}

			// Member-obstacle interaction	( Section 4.2 )
			for (unsigned int obs=0; obs < obstacles.size(); obs++)	// Iterating through each obstacle
			{
				swarm[mem].DistObs(obstacles[obs]);					// Distance to obstacle						( Eq. 4.5 )
				swarm[mem].TestCollision(obstacles[obs]);			// Checking if swarm is immobilized			(	 -    )
				swarm[mem].DirObs(obstacles[obs]);					// Directed normal to obstacle				( Eq. 4.6 )
				swarm[mem].WgtDirObs();								// Weighted directed normal to obstacle		( Eq. 4.7 )
				Nmo += swarm[mem].GetWgtDirObs();					// Member-obstacle interaction parameter	( Eq. 4.8 )
			}

			// Member-member interaction	( Section 4.3 )
			for (unsigned int mem2 = 0; mem2 < swarm.size(); mem2++)// Iterating through each member
				// if comparing to istelf, Directed normal = Vec2(-nan(ind), -nan(ind))
			{
				swarm[mem].DistMem(swarm[mem2]);					// Distance to other member					( Eq. 4.9 )
				swarm[mem].DirMem(swarm[mem2]);						// Directed normal to other member			( Eq. 4.10 )
				swarm[mem].WgtDirMem();								// Weighted directed normal to other member	( Eq. 4.11 )
				Nmm += swarm[mem].GetWgtDirMem();					// Member-member interaction parameter		( Eq. 4.12 )
			}														

			// Weighting each interaction parameter:
			Vec3 WNmt = Nmt*Swarm::Wmt;
			Vec3 WNmo = Nmo*Swarm::Wmo;
			Vec3 WNmm = Nmm*Swarm::Wmm;
			Vec3 Ntot = WNmt + WNmo + WNmo;
			// Normalizing result:
			Vec3 n_norm = Ntot / sqrt(pow(Ntot.x, 2.0f) + pow(Ntot.y, 2.0f) + pow(Ntot.z, 2.0f));

			// Swarm-member moves:
			swarm[mem].Step(n_norm);

			// Removing targets if they're mapped:
			for (unsigned int tars = 0; tars < targets.size(); tars++)
			{
				if (targets[tars].IsMapped())
				{
					std::cout << sim_time << ": " << targets.size() << std::endl;
					targets.erase(targets.begin() + tars);
				}
			}
			// Removing swarm-members if they're immobilzed:
			for (unsigned int mem = 0; mem < swarm.size(); mem++)
			{
				if (swarm[mem].IsImmobile())
				{
					swarm.erase(swarm.begin() + mem);
				}
			}
		}

		// Stop simulation if all targets are mapped:
		if (targets.size() == 0 || swarm.size() == 0)
		{
			break;
		}

		// Output Data:
		if (sim_time % 100 == 0)// print every 500 timesteps.
		{
			std::stringstream memOutputfile;
			memOutputfile << "results//memPos-" << outputFile << ".csv"; //outputs to results folder
			std::ofstream prntMem;
			prntMem.open(memOutputfile.str().c_str());

			for (unsigned int mem = 0; mem < swarm.size(); mem++)
			{
				prntMem << swarm[mem].GetPos().x << "," << swarm[mem].GetPos().y << "," << swarm[mem].GetPos().z << std::endl;
			}
			prntMem.close();

			std::stringstream tarOutputfile;
			tarOutputfile << "results//tarPos-" << outputFile << ".csv"; //outputs to results folder
			std::ofstream prntTar;
			prntTar.open(tarOutputfile.str().c_str());
			for (unsigned int tar = 0; tar < targets.size(); tar++)
			{
				prntTar << targets[tar].GetPos().x << "," << targets[tar].GetPos().y << "," << targets[tar].GetPos().z << std::endl;
			}
			prntTar.close();

			outputFile += 1;
		}
	}

	std::stringstream obsOutputfile;
	obsOutputfile << "results//obsPos.csv"; //outputs to results folder
	std::ofstream prntObs;
	prntObs.open("results//obsPos.csv");
	for (unsigned int obs = 0; obs < obstacles.size(); obs++)
	{
		prntObs << obstacles[obs].GetPos().x << "," << obstacles[obs].GetPos().y << "," << obstacles[obs].GetPos().z << std::endl;
	}
	prntObs.close();
}

