#include "GameScreen.h"
#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
	// A dynamic array containing pointers to all the screens in the game
	std::vector<Screen*> screens;
	// The ID of the current screen
	int currentScreen = 0;

	sf::RenderWindow window(sf::VideoMode(800, 850), "SFblock");
	window.setVerticalSyncEnabled(true);

	// Instantiate screens here
	GameScreen screen1;
	screens.push_back(&screen1);

	// Run current screen
	while (currentScreen >= 0)
	{
		currentScreen = screens[currentScreen]->run(window);
	}

	// Return 0 if successful
	return 0;
}