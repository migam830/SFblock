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
	Button gameButton;

	virtual int run(sf::RenderWindow& window);
};