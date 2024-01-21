#include "HomeScreen.h"

HomeScreen::HomeScreen() : gameButton(300, 125, 250, 425, "Start Game")
{
	// Load font from file
	if (!font.loadFromFile("res/SourceSans3-Regular.ttf"))
	{
		throw "Font not found";
	}

	titleText.setFont(font);
	titleText.setPosition(150, 50);
	titleText.setCharacterSize(150);
	titleText.setFillColor(sf::Color::Black);
	titleText.setString("SFblock");
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

			if (gameButton.checkPressed(event))
			{
				// Open the game screen
				return 1;
			}
		}

		// Clear window
		window.clear(sf::Color::White);

		// Draw everything here
		window.draw(gameButton);
		window.draw(titleText);

		// End current frame
		window.display();
	}
	return -1;
}