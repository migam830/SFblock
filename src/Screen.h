#pragma once
#include <SFML/Graphics.hpp>

class Screen
{
public:
	// Function designed to be overridden so assigned to zero
	virtual int run(sf::RenderWindow& window) = 0;
};