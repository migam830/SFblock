#pragma once
#include <SFML/Graphics.hpp>

class PlayField : public sf::Drawable
{
public:
	PlayField();

private:
	// Constant controlling size of all blocks making up PlayField
	const int SCALE = 50;
	char state[10][20];
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};