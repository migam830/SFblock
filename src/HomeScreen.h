#pragma once
#include "Screen.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

class HomeScreen : public Screen
{
public:
	HomeScreen();

private:
	// All the UI elements of this screen
	sf::Font font;
	Button gameButton;
	sf::Text titleText;

	virtual int run(sf::RenderWindow& window);
};