#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Block.h"

class PlayField : public sf::Drawable
{
public:
	PlayField();
	void spawn(char type);

private:
	// Constant controlling size of all blocks making up PlayField
	static const int SCALE = 40;

	// Size of the PlayField (can be modified to get a different size), declared [columns][rows]
	char state[10][20];
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// A smart pointer to the current block
	std::unique_ptr<Block> currentBlock;
};