#pragma once
#include "PlayField.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();

private:
	PlayField p1;
	sf::RenderWindow window;
};