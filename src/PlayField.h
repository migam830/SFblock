#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Block.h"

class PlayField : public sf::Drawable
{
public:
	PlayField();
	~PlayField();
	void spawn(char type);

private:
	// Constant controlling size of all blocks making up PlayField
	static const int SCALE = 40;

	// Size of the PlayField (can be modified to get a different size), declared [columns][rows]
	char state[10][20];
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// A pointer to the current block
	Block* currentBlock;
};