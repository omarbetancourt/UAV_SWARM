#pragma once

std::random_device rd; // seed generator used to pass into rng to create different random numbers every time.
std::mt19937 rng(rd()); //outputs a random number (-2b, +2b), but outputs same sequence of random numbers every time
std::uniform_real_distribution<float> xDist(0.0f, 5.0f); // uniform_int_distribution remaps rng to the specified range. ( -5,5 )
std::uniform_real_distribution<float> yDist(0.0f, 5.0f); //<float> specifies the output should be type float
std::uniform_real_distribution<float> vDist(0.0f, 1.0f); 

std::uniform_real_distribution<float> xtDist(0.0f, 100.0f);
std::uniform_real_distribution<float> ytDist(0.0f, 100.0f); 

std::uniform_real_distribution<float> xoDist(0.0f, 100.0f);
std::uniform_real_distribution<float> yoDist(0.0f, 100.0f);

void FillSwarmVector(std::vector<Swarm>&); // Declaration //

void FillSwarmVector(std::vector<Swarm>& swarms) // Definition
{
	for (unsigned int mem = 0; mem < nSwarmMembers; mem++) // Initializing pos and vel for swarms.
	{
		Vec2 in_pos(xDist(rng), yDist(rng));
		Vec2 in_vel(vDist(rng), vDist(rng));
		Swarm swarm(in_pos, in_vel);
		swarms.push_back(swarm);
	}
}

void FillTargetVector(std::vector<Target>&); // Declaration // 

void FillTargetVector(std::vector<Target>& targets) // Definition
{
	for (unsigned int tar = 0; tar < nTargets; tar++) // Initializing pos for targets.
	{
		Vec2 in_pos(xtDist(rng), ytDist(rng));
		Target target(in_pos);
		targets.push_back(target);
	}
}

void FillObstacleVector(std::vector<Obstacle>&); // Declaration // 

void FillTargetVector(std::vector<Obstacle>& obstacles) // Definition
{
	for (unsigned int obs = 0; obs < nObstacles; obs++) // Initializing pos for Obstacles.
	{
		Vec2 in_pos(xoDist(rng), yoDist(rng));
		Obstacle obstacle(in_pos);
		obstacles.push_back(obstacle);
	}
}