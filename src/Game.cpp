#include "Game.h"
#include <string>

Game::Game() : window(sf::VideoMode(800, 850), "SFblock"), score(0)
{
	window.setVerticalSyncEnabled(true);
	if (!font.loadFromFile("res/SourceSans3-Regular.ttf"))
	{
		throw "Font not found";
	}
	scoreDisplay.setPosition(500, 0);
	scoreDisplay.setFont(font);
	scoreDisplay.setCharacterSize(50);
	scoreDisplay.setFillColor(sf::Color::Black);
}

void Game::run()
{
	while (window.isOpen())
	{
		scoreDisplay.setString("Score: " + std::to_string(score));

		// Check all the window's events since last loop iteration
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// Clear window
		window.clear(sf::Color::White);

		// Draw everything here
		window.draw(p1);
		window.draw(scoreDisplay);

		// End current frame
		window.display();
	}
}