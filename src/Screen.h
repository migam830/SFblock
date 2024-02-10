#pragma once
#include <SFML/Graphics.hpp>

class Screen
{
public:
	// Function designed to be overridden so has 'equals zero' at the end
	virtual int run(sf::RenderWindow& window) = 0;
};