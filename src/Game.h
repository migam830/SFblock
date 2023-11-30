#pragma once
#include "PlayField.h"
#include "RandomShuffler.h"
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
	const int DAS = 50;

	// Value of auto repeat rate (milliseconds)
	const int ARR = 50;

	// Value of ARR for downward movement (milliseconds)
	const int SOFTDROPSPEED = 20;

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

	// Shuffler to return next block to be spawned
	RandomShuffler shuffler1;
};