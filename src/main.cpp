#include <SFML/Graphics.hpp>

int main()
{
	// Create SFML window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFblock");

	// Enable vertical sync to reduce CPU usage
	window.setVerticalSyncEnabled(true);

	// Run while SFML window is open
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

		// End current frame
		window.display();
	}

	// Return 0 if successful
	return 0;
}