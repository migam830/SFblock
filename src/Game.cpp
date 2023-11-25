#include "Game.h"
#include <string>

Game::Game() : window(sf::VideoMode(800, 850), "SFblock"), score(0), leftPressed(false), rightPressed(false), downPressed(false)
{
	// Load font from font file
	window.setVerticalSyncEnabled(true);
	if (!font.loadFromFile("res/SourceSans3-Regular.ttf"))
	{
		throw "Font not found";
	}
	// Set properties of score counter text
	scoreDisplay.setPosition(500, 0);
	scoreDisplay.setFont(font);
	scoreDisplay.setCharacterSize(50);
	scoreDisplay.setFillColor(sf::Color::Black);
}

void Game::run()
{
	while (window.isOpen())
	{
		// Any actions not based on events here
		scoreDisplay.setString("Score: " + std::to_string(score));

		if (leftPressed && ARRclock.getElapsedTime().asMilliseconds() >= ARR && DASclock.getElapsedTime().asMilliseconds() >= DAS)
		{
			ARRclock.restart();
			p1.moveLeft();
		}
		if (rightPressed && ARRclock.getElapsedTime().asMilliseconds() >= ARR && DASclock.getElapsedTime().asMilliseconds() >= DAS)
		{
			ARRclock.restart();
			p1.moveRight();
		}
		if (downPressed && softDropClock.getElapsedTime().asMilliseconds() >= softDropSpeed)
		{
			softDropClock.restart();
			p1.moveDown();
		}

		// Check all the window's events since last loop iteration
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				// Increment score when spacebar is pressed (will be removed later)
				if (event.key.code == sf::Keyboard::Space)
				{
					addScore(1);
				}

				// Block spawning (temporary)
				if (event.key.code == sf::Keyboard::O)
				{
					p1.spawn('o');
				}
				if (event.key.code == sf::Keyboard::I)
				{
					p1.spawn('i');
				}
				if (event.key.code == sf::Keyboard::J)
				{
					p1.spawn('j');
				}
				if (event.key.code == sf::Keyboard::L)
				{
					p1.spawn('l');
				}
				if (event.key.code == sf::Keyboard::S)
				{
					p1.spawn('s');
				}
				if (event.key.code == sf::Keyboard::T)
				{
					p1.spawn('t');
				}
				if (event.key.code == sf::Keyboard::Z)
				{
					p1.spawn('z');
				}

				// Block movement
				if (event.key.code == sf::Keyboard::Left && !leftPressed)
				{
					DASclock.restart();
					ARRclock.restart();
					leftPressed = true;
					rightPressed = false;
				}
				if (event.key.code == sf::Keyboard::Right && !rightPressed)
				{
					DASclock.restart();
					ARRclock.restart();
					rightPressed = true;
					leftPressed = false;
				}
				if (event.key.code == sf::Keyboard::Down && !downPressed)
				{
					// DAS not applicable to downward movement
					softDropClock.restart();
					downPressed = true;
				}

				// Block rotation
				if (event.key.code == sf::Keyboard::Up)
				{
					p1.rotateClockwise();
				}
				if (event.key.code == sf::Keyboard::Enter)
				{
					p1.rotateAntiClockwise();
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					leftPressed = false;
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					rightPressed = false;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					downPressed = false;
				}
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

int Game::getScore()
{
	return score;
}

void Game::addScore(int amount)
{
	score += amount;
}