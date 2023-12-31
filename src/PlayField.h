#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <array>
#include "Block.h"

class PlayField : public sf::Drawable
{
public:
	PlayField();
	void init();
	bool spawn(char type);
	void moveLeft();
	void moveRight();
	bool moveDown();
	void rotateClockwise();
	void rotateAntiClockwise();
	void hardDrop();
	int clearLines();

private:
	// Constant controlling size of all blocks making up PlayField
	static const int SCALE = 40;

	// Array containing state of the PlayField (can be modified to get a different size), declared <<char, rows>,columns>
	std::array<std::array<char, 20>, 10> state;

	// A smart pointer to the current block
	std::unique_ptr<Block> currentBlock;

	bool checkState(int x, int y) const;
	void updateState(bool clear = false);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};