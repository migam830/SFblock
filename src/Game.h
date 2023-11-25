#pragma once
#include "PlayField.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();
	int getScore();
	void addScore(int amount);

private:
	int score;

	// Value of delayed auto shift (milliseconds)
	static const int DAS = 50;

	// Value of auto repeat rate (milliseconds)
	static const int ARR = 20;

	// Value of ARR for downward movement (milliseconds)
	static const int SOFTDROPSPEED = 20;

	// How fast blocks fall naturally (non-constant, milliseconds)
	int fallRate;

	// State of left, right and down arrow keys
	bool leftPressed;
	bool rightPressed;
	bool downPressed;

	// All the main UI components of the game
	sf::Text scoreDisplay;
	sf::Font font;
	PlayField p1;
	sf::RenderWindow window;

	// Clocks to time block movement and falling
	sf::Clock DASclock;
	sf::Clock ARRclock;
	sf::Clock softDropClock;
	sf::Clock fallClock;
};