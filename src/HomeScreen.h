#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>

class HomeScreen : public Screen
{
public:
	HomeScreen();

private:
	// All the UI elements of this screen
	sf::Font font;
	sf::RectangleShape gameButton;
	sf::Text gameButtonText;

	virtual int run(sf::RenderWindow& window);
};