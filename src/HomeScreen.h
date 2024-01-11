#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>

class HomeScreen : public Screen
{
public:
	HomeScreen();

private:
	sf::Font font;
	virtual int run(sf::RenderWindow& window);
};