#include "Block.h"

Block::Block(char type) : xPos(0), yPos(0)
{
	// Initialise the array containing the position of the blocks
	for (auto& column : blocks)
	{
		column.fill(' ');
	}

	// Initialise block depending on what type it is, array accessed with [column][row]
	switch (type)
	{
	case 'i':
		blocks[0][1] = 'c';
		blocks[1][1] = 'c';
		blocks[2][1] = 'c';
		blocks[3][1] = 'c';
		break;
	case 'j':
		blocks[0][0] = 'b';
		blocks[0][1] = 'b';
		blocks[1][1] = 'b';
		blocks[2][1] = 'b';
		break;
	case 'l':
		blocks[2][0] = 'o';
		blocks[0][1] = 'o';
		blocks[1][1] = 'o';
		blocks[2][1] = 'o';
		break;
	case 'o':
		blocks[1][0] = 'y';
		blocks[2][0] = 'y';
		blocks[1][1] = 'y';
		blocks[2][1] = 'y';
		break;
	case 's':
		blocks[1][0] = 'g';
		blocks[2][0] = 'g';
		blocks[0][1] = 'g';
		blocks[1][1] = 'g';
		break;
	case 't':
		blocks[0][1] = 'm';
		blocks[1][0] = 'm';
		blocks[1][1] = 'm';
		blocks[2][1] = 'm';
		break;
	case 'z':
		blocks[0][0] = 'r';
		blocks[1][0] = 'r';
		blocks[1][1] = 'r';
		blocks[2][1] = 'r';
		break;
	default:
		throw "Invalid block type";
	}
}

char Block::getBlock(int column, int row)
{
	return blocks[column][row];
}

void Block::shiftPosition(int x, int y)
{
	xPos += x;
	yPos += y;
}

int Block::getX()
{
	return xPos;
}

int Block::getY()
{
	return yPos;
}