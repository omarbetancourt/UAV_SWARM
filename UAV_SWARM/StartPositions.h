#pragma once

static constexpr unsigned int nSwarmMembers = 100u; //variable available at compile time
static constexpr unsigned int nTargets = 100u;
static constexpr unsigned int nObstacles = 0u;

std::random_device rd; // seed generator used to pass into rng to create different random numbers every time.
std::mt19937 rng(rd()); //outputs a random number (-2b, +2b), but outputs same sequence of random numbers every time
std::uniform_real_distribution<float> xDist(0.0f, 10.0f); // uniform_int_distribution remaps rng to the specified range. ( -5,5 )
std::uniform_real_distribution<float> yDist(0.0f, 10.0f); //<float> specifies the output should be type float
std::uniform_real_distribution<float> zDist(0.0f, 10.0f);

std::uniform_real_distribution<float> xtDist(0.0f, 500.0f);
std::uniform_real_distribution<float> ytDist(0.0f, 500.0f); 
std::uniform_real_distribution<float> ztDist(0.0f, 10.0f);

std::uniform_real_distribution<float> xoDist(0.0f, 500.0f);
std::uniform_real_distribution<float> yoDist(0.0f, 500.0f);
std::uniform_real_distribution<float> zoDist(0.0f, 10.0f);

void FillSwarmVector(std::vector<Swarm>& swarm) // Definition
{
	for (unsigned int mem = 0; mem < nSwarmMembers; mem++) // Initializing pos and vel for swarms.
	{
		Vec3 in_pos(xDist(rng), yDist(rng), zDist(rng));
		Vec3 in_vel(0.0f, 0.0f, 0.0f);

		Swarm member(in_pos, in_vel);
		swarm.push_back(member);
	}
}

void FillTargetVector(std::vector<Target>& targets) // Definition
{
	for (unsigned int tar = 0; tar < nTargets; tar++) // Initializing pos for targets.
	{
		Vec3 in_pos(xtDist(rng), ytDist(rng), ztDist(rng));
		Target target(in_pos);
		targets.push_back(target);
	}
}

void FillTargetVector(std::vector<Obstacle>& obstacles) // Definition
{
	for (unsigned int obs = 0; obs < nObstacles; obs++) // Initializing pos for Obstacles.
	{
		Vec3 in_pos(xoDist(rng), yoDist(rng), zoDist(rng));
		Obstacle obstacle(in_pos);
		obstacles.push_back(obstacle);
	}
}