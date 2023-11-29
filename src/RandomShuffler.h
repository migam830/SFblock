#pragma once
#include <array>
#include <random>

class RandomShuffler
{
public:
	RandomShuffler();
	char getNextPiece();

private:
	// Array to be selected from
	const std::array<char, 7> blockSelection = { 'i', 'j', 'l', 'o', 's', 't', 'z' };
	std::default_random_engine randomEngine;
	std::uniform_int_distribution<> randomDistribution;
};