#include "SevenBagShuffler.h"
#include <chrono>

SevenBagShuffler::SevenBagShuffler() : blockIndex(0)
{
	// Seed the random engine
	randomEngine.seed(std::chrono::system_clock::now().time_since_epoch().count());

	// Shuffle the seven bag array
	std::shuffle(std::begin(sevenBag), std::end(sevenBag), randomEngine);
}

char SevenBagShuffler::getNextPiece()
{
	// Shuffle blocks and set index to zero once all blocks have been used
	if (blockIndex >= 7)
	{
		blockIndex = 0;
		std::shuffle(std::begin(sevenBag), std::end(sevenBag), randomEngine);
	}

	// Increment block index for next time but return original index
	blockIndex += 1;
	return sevenBag[blockIndex - 1];
}

void SevenBagShuffler::reset()
{
	blockIndex = 0;
}