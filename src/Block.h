#pragma once

class Block
{
public:
	Block(char type);
	char getBlock(int column, int row);
private:
	// Like PlayField, declared [columns][rows]
	char blocks[4][4];
};