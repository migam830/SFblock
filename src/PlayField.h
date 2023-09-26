#pragma once
#include <SFML/Graphics.hpp>

class PlayField : public sf::Drawable
{
public:
	PlayField();

private:
	// Constant controlling size of all blocks making up PlayField
	static const int SCALE = 40;

	// Constants controlling width and height of PlayField (might be variables later)
	static const int HEIGHT = 20;
	static const int WIDTH = 10;

	char state[HEIGHT][WIDTH];
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};