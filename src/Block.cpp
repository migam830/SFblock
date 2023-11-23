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

void Block::rotate(bool clockwise)
{
	// 'o' block doesn't rotate
	if (type == 'o')
	{
		return;
	}

	// Copy contents of blocks array
	auto tempBlocks = blocks;

	// 'i' block needs to be handled differently due to horizontal length
	if (type == 'i')
	{
		for (int column = 0; column < tempBlocks.size(); column++)
		{
			for (int row = 0; row < tempBlocks[0].size(); row++)
			{
				if (clockwise)
				{
					blocks[column][row] = tempBlocks[row][tempBlocks.size() - column - 1];
				}
				else
				{
					blocks[column][row] = tempBlocks[tempBlocks[0].size() - row - 1][column];
				}
			}
		}
	}

	else
	{
		// Put each square of the block in its new position
		for (int column = 0; column < blocks.size() - 1; column++)
		{
			for (int row = 1; row < blocks[0].size(); row++)
			{
				if (clockwise)
				{
					blocks[column][row] = tempBlocks[row - 1][tempBlocks.size() - column - 1];
				}
				else
				{
					blocks[column][row] = tempBlocks[tempBlocks[0].size() - row - 1][column + 1];
				}
			}
		}
	}
}