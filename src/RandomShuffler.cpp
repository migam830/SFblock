#include "RandomShuffler.h"
#include <chrono>

RandomShuffler::RandomShuffler() : randomDistribution(0, blockSelection.size() - 1)
{
	randomEngine.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

char RandomShuffler::getNextPiece()
{
	int randomBlock = randomDistribution(randomEngine);
	return blockSelection[randomBlock];
}