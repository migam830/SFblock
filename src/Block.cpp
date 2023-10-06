#include "Block.h"

Block::Block(char type) : xPos(0), yPos(0), canMoveLeft(true), canMoveRight(true), canMoveDown(true)
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
	case 'o':
		blocks[1][1] = 'y';
		blocks[2][1] = 'y';
		blocks[1][2] = 'y';
		blocks[2][2] = 'y';
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

bool Block::getMove(char direction)
{
	switch (direction)
	{
	case 'l':
		return canMoveLeft;
		break;
	case 'r':
		return canMoveRight;
		break;
	case 'd':
		return canMoveDown;
		break;
	default:
		throw "Invalid direction specified";
	}
}

void Block::setMove(char direction, bool state)
{
	switch (direction)
	{
	case 'l':
		canMoveLeft = state;
		break;
	case 'r':
		canMoveRight = state;
		break;
	case 'd':
		canMoveDown = state;
		break;
	default:
		throw "Invalid direction specified";
	}
}