#pragma once
#include "PlayField.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();

private:
	int score;
	sf::Text scoreDisplay;
	sf::Font font;
	PlayField p1;
	sf::RenderWindow window;
};