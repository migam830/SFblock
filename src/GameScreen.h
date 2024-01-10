#pragma once
#include "Screen.h"
#include "PlayField.h"
#include "RandomShuffler.h"
#include <SFML/Graphics.hpp>

class GameScreen : public Screen
{
public:
	GameScreen();

private:
	int score;

	// Value of delayed auto shift (milliseconds)
	const int DAS = 40;

	// Value of auto repeat rate (milliseconds)
	const int ARR = 45;

	// Value of ARR for downward movement (milliseconds)
	const int SOFTDROPSPEED = 20;

	// How fast blocks fall naturally (non-constant, milliseconds, lower is faster)
	int fallRate;

	// Fall rate at the start of the game
	const int INITIALFALLRATE = 1000;

	// State of left, right and down arrow keys
	bool leftPressed;
	bool rightPressed;
	bool downPressed;

	// Boolean indicating hard drop
	bool hardDrop;

	// Boolean indicating when the game is over
	bool gameOver;

	// All the main UI components of the game
	sf::Text scoreDisplay;
	sf::Text newGameMessage;
	sf::Font font;
	PlayField p1;

	// Clocks to time block movement and falling
	sf::Clock DASclock;
	sf::Clock ARRclock;
	sf::Clock softDropClock;
	sf::Clock fallClock;

	// Shuffler to return next block to be spawned
	RandomShuffler shuffler1;

	virtual int run(sf::RenderWindow& window);
};