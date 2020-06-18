#pragma once

std::random_device rd; // seed generator used to pass into rng to create different random numbers every time.
std::mt19937 rng(rd()); //outputs a random number (-2b, +2b), but outputs same sequence of random numbers every time
std::uniform_real_distribution<float> xDist(0.0f, 5.0f); // uniform_int_distribution remaps rng to the specified range. ( -5,5 )
std::uniform_real_distribution<float> yDist(0.0f, 5.0f); //<int> specifies the output should be type int
std::uniform_real_distribution<float> vDist(0.0f, 1.0f); //<int> specifies the output should be type int

std::uniform_real_distribution<float> xtDist(0.0f, 100.0f);
std::uniform_real_distribution<float> ytDist(0.0f, 100.0f); // add this block to header

std::uniform_real_distribution<float> xoDist(0.0f, 100.0f);
std::uniform_real_distribution<float> yoDist(0.0f, 100.0f);

void FillSwarmVector(std::vector<Swarm>&); // Declaration // could add this to StartPositions or make new InitializeAgents.h

void FillSwarmVector(std::vector<Swarm>& swarms) // Definition
{
	Vec2 in_pos(xDist(rng), yDist(rng));
	Vec2 in_vel(vDist(rng), vDist(rng));

	for (unsigned int mem = 0; mem < nSwarmMembers; mem++) // Initializing pos and v for swarms. Later needs to be initialized with constructor instead of this Init function
	{
		Swarm swarm(in_pos, in_vel);
		swarms.push_back(swarm);
	}
}

void FillTargetVector(std::vector<Target>&); // Declaration // could add this to StartPositions or make new InitializeAgents.h

void FillTargetVector(std::vector<Target>& targets) // Definition
{
	Vec2 in_pos(xtDist(rng), ytDist(rng));

	for (unsigned int tar = 0; tar < nTargets; tar++) // Initializing pos and v for swarms. Later needs to be initialized with constructor instead of this Init function
	{
		Target target(in_pos);
		targets.push_back(target);
	}
}