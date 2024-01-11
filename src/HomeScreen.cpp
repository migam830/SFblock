#include "HomeScreen.h"

HomeScreen::HomeScreen()
{
	// Load font from file
	if (!font.loadFromFile("res/SourceSans3-Regular.ttf"))
	{
		throw "Font not found";
	}

	// Set properties of text elements
	gameButtonText.setFont(font);
	gameButtonText.setPosition(290, 440);
	gameButtonText.setOrigin(gameButtonText.getGlobalBounds().getSize() / 2.f + gameButtonText.getLocalBounds().getPosition());
	gameButtonText.setCharacterSize(50);
	gameButtonText.setFillColor(sf::Color::Black);
	gameButtonText.setString("Start Game");

	// Set properties of game button
	gameButton.setPosition(225, 400);
	gameButton.setSize(sf::Vector2f(350, 150));
	gameButton.setFillColor(sf::Color(93, 173, 226));
	gameButton.setOutlineColor(sf::Color::Black);
	gameButton.setOutlineThickness(-10);
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
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left && gameButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					return 1;
				}
			}
		}

		// Clear window
		window.clear(sf::Color::White);

		// Draw everything here
		window.draw(gameButton);
		window.draw(gameButtonText);

		// End current frame
		window.display();
	}
	return -1;
}