#include "GameScreen.h"
#include "HomeScreen.h"
#include <SFML/Graphics.hpp>
#include <array>

int main()
{
	// Initialise SFML window
	sf::RenderWindow window(sf::VideoMode(800, 850), "SFblock");
	window.setVerticalSyncEnabled(true);

	// Instantiate screens here
	HomeScreen screen1;
	GameScreen screen2;

	// An array containing pointers to all the screens in the game
	std::array<Screen*, 2> screens = { &screen1, &screen2 };

	// The ID of the current screen
	int currentScreen = 0;

	// Run current screen
	while (currentScreen >= 0)
	{
		currentScreen = screens[currentScreen]->run(window);
	}

	// Return 0 if successful
	return 0;
}