#pragma once
#include <SFML/Graphics.hpp>

class PlayField : public sf::Drawable
{
public:
	PlayField();

private:
	// Constant controlling size of all blocks making up PlayField
	static const int SCALE = 40;
	// Size of the PlayField (can be modified to get a different size)
	char state[20][10];
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};