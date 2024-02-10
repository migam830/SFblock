#pragma once
#include "Shuffler.h"
#include <array>
#include <random>

class SevenBagShuffler : public Shuffler
{
public:
	SevenBagShuffler();

private:
	// Selection of blocks to shuffle
	std::array<char, 7> sevenBag = { 'i', 'j', 'l', 'o', 's', 't', 'z' };

	// Index of next block
	int blockIndex;

	std::default_random_engine randomEngine;

	virtual char getNextPiece();
};