#include "Game.h"

Game::Game(): window(sf::VideoMode(800, 600), "SFblock")
{
	window.setVerticalSyncEnabled(true);
}

void Game::run()
{
	while (window.isOpen())
	{
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

		// End current frame
		window.display();
	}
}