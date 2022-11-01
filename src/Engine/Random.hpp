//
// Created by technicjelle on 01/11/22.
//

#ifndef CHTHONIC_METAL_RANDOM_HPP
#define CHTHONIC_METAL_RANDOM_HPP

#include <ctime>
#include <cstdlib>

namespace Random
{
	///Call this once, before ever calling one of the other functions
	[[maybe_unused]] inline void randInit()
	{
		srandom(time(nullptr));
	}

	///Returns a random float in range 0..1
	[[maybe_unused]] inline float randf()
	{
		return float(random()) / float(RAND_MAX);
	}

	///Returns a random float in range 0..Max
	[[maybe_unused]] inline float randf(float Max)
	{
		return (float(random()) / float(RAND_MAX)) * Max;
	}

	///Returns a random float in range Min..Max
	[[maybe_unused]] inline float randf(float Min, float Max)
	{
		return ((float(random()) / float(RAND_MAX)) * (Max - Min)) + Min;
	}

	///Returns a random int in range 0..Max
	[[maybe_unused]] inline int randi(int Max)
	{
		return (int)random() % Max;
	}

	///Returns a random int in range Min..Max
	[[maybe_unused]] inline int randi(int Min, int Max)
	{
		return ((int)random() % (Max - Min)) + Min;
	}

	///Returns a random bool
	[[maybe_unused]] inline bool randb()
	{
		return random() % 2 == 0;
	}

	///Chance is in range 0..1
	[[maybe_unused]] inline bool randb(float Chance)
	{
		return randf() < Chance;
	}
}

#endif //CHTHONIC_METAL_RANDOM_HPP
