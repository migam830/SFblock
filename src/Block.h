#pragma once
#include <array>

class Block
{
public:
	Block(char type);
	char getBlock(int column, int row);
	void shiftPosition(int x, int y);
	int getX();
	int getY();
private:
	// Like PlayField, declared <<char, rows>,columns>
	std::array<std::array<char, 4>, 4> blocks;

	int xPos;
	int yPos;
};