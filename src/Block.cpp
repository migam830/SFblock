#include "Block.h"

Block::Block(char type)
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