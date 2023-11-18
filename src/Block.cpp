#include "Block.h"

Block::Block(char inputType) : xPos(0), yPos(0)
{
	type = inputType;
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
		blocks[0][1] = 'b';
		blocks[0][2] = 'b';
		blocks[1][2] = 'b';
		blocks[2][2] = 'b';
		break;
	case 'l':
		blocks[2][1] = 'o';
		blocks[0][2] = 'o';
		blocks[1][2] = 'o';
		blocks[2][2] = 'o';
		break;
	case 'o':
		blocks[1][1] = 'y';
		blocks[2][1] = 'y';
		blocks[1][2] = 'y';
		blocks[2][2] = 'y';
		break;
	case 's':
		blocks[1][1] = 'g';
		blocks[2][1] = 'g';
		blocks[0][2] = 'g';
		blocks[1][2] = 'g';
		break;
	case 't':
		blocks[0][2] = 'm';
		blocks[1][1] = 'm';
		blocks[1][2] = 'm';
		blocks[2][2] = 'm';
		break;
	case 'z':
		blocks[0][1] = 'r';
		blocks[1][1] = 'r';
		blocks[1][2] = 'r';
		blocks[2][2] = 'r';
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

void Block::rotateClockwise()
{
	// 'o' block doesn't rotate
	if (type == 'o')
	{
		return;
	}

	// 'i' block needs to be handled differently due to horizontal length
	if (type == 'i')
	{
		// Replace 'return' with something useful
		return;
	}

	// Backup contents of blocks array
	std::array<std::array<char, 4>, 4> tempBlocks = blocks;

	// Clear blocks array
	for (auto& column : blocks)
	{
		column.fill(' ');
	}

	// Put each square of the block in its new position
	blocks[1][2] = tempBlocks[1][2];
	blocks[0][1] = tempBlocks[0][3];
	blocks[1][1] = tempBlocks[0][2];
	blocks[2][1] = tempBlocks[0][1];
	blocks[2][2] = tempBlocks[1][1];
	blocks[2][3] = tempBlocks[2][1];
	blocks[1][3] = tempBlocks[2][2];
	blocks[0][3] = tempBlocks[2][3];
	blocks[0][2] = tempBlocks[1][3];
}