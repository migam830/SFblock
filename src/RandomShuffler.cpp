#include "RandomShuffler.h"
#include <chrono>

RandomShuffler::RandomShuffler() : randomDistribution(0, blockSelection.size() - 1)
{
	// Set seed to current system time
	randomEngine.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

char RandomShuffler::getNextPiece()
{
	// Generate random number of piece to spawn
	int randomBlock = randomDistribution(randomEngine);
	return blockSelection[randomBlock];
}