#include "HomeScreen.h"

HomeScreen::HomeScreen()
{
	// Load font from file
	if (!font.loadFromFile("res/SourceSans3-Regular.ttf"))
	{
		throw "Font not found";
	}
}

int HomeScreen::run(sf::RenderWindow& window)
{
	// Event loop for home screen
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				// Close the window
				return -1;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::G)
			{
				// Open the game screen
				return 1;
			}
		}

		// Clear window
		window.clear(sf::Color::White);

		// Draw everything here

		// End current frame
		window.display();
	}
	return -1;
}