#pragma once
#include <array>

class Block
{
public:
	Block(char type);
	char getBlock(int column, int row);
private:
	// Like PlayField, declared <<char, rows>,columns>
	std::array<std::array<char, 4>, 4> blocks;
};