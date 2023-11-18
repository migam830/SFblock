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
	void rotateClockwise();
private:
	// Like PlayField, declared <<char, rows>,columns>
	std::array<std::array<char, 4>, 4> blocks;

	// Block's x and y position in the playing field
	int xPos;
	int yPos;

	char type;
};