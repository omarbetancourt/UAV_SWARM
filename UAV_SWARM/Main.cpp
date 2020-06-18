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

	//std::vector<Vec2> NmtVec;

	std::ofstream prntpos;
	prntpos.open ("swarmPositions.txt");

	for (int sim_time = 0; sim_time < 1000; ++sim_time) //time step. each iter is 0.001 sec
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

				// Printing out results for debugging purposes:
				prntpos << "Time Step : " << sim_time << std::endl;
				prntpos << "Target " << tar << ": " << targets[tar].GetPos().x << " , " << targets[tar].GetPos().y << std::endl;
				prntpos << "Member " << mem << ": " <<  swarms[mem].GetPos().x << " , " << swarms[mem].GetPos().y << std::endl;
				prntpos << "Wgt Dir : " << swarms[mem].GetWgtDirTar().x << " , " << swarms[mem].GetWgtDirTar().y << std::endl;
				prntpos << "Sum Nmt_i : " << Nmt.x << " , " << Nmt.y << std::endl;
				
				Nmt += swarms[mem].GetWgtDirTar(); // result for Nmt for one member
				prntpos << "Sum Nmt_i : " << Nmt.x << " , " << Nmt.y << std::endl;
				prntpos << "  " << std::endl;
			}


			// add other for loops here for obstacles

			Vec2 WNmt = Nmt*Swarm::Wmt;
			Vec2 WNmo = Nmo*Swarm::Wmt;
			Vec2 WNmm = Nmm*Swarm::Wmt;

			Vec2 Ntot = WNmt + WNmo + WNmo;
			Vec2 n_norm = Ntot / sqrt(pow(Ntot.x, 2.0f) + pow(Ntot.y, 2.0f));

			swarms[mem].Step(n_norm);
		}

		// if sime_time % 100 == true then print pos

	}

	prntpos.close();
}

