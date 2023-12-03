#include "Game.h"
#include <string>

Game::Game() : window(sf::VideoMode(800, 850), "SFblock"), score(0), leftPressed(false), rightPressed(false), downPressed(false), hardDrop(false), gameOver(true)
{
	// Initialise fall rate
	fallRate = INITIALFALLRATE;

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
	scoreDisplay.setString("Score: " + std::to_string(score));

	// Properties of new game message
	newGameMessage.setPosition(425, 150);
	newGameMessage.setFont(font);
	newGameMessage.setCharacterSize(30);
	newGameMessage.setFillColor(sf::Color::Blue);
	newGameMessage.setString("Press N to start a new game");
}

void Game::run()
{
	while (window.isOpen())
	{
		// Any actions not based on events here

		if (!gameOver)
		{
			// Update score display with latest score
			scoreDisplay.setString("Score: " + std::to_string(score));

			// Block falls naturally even if no keys are pressed
			if ((fallClock.getElapsedTime().asMilliseconds() >= fallRate) || hardDrop)
			{
				hardDrop = false;
				fallClock.restart();
				// If block is null pointer or can't move down, spawn a new one
				if (!p1.moveDown())
				{
					// Clear lines and increment score by number of lines cleared
					score += p1.clearLines();

					// Increase speed of blocks as score increases
					if (score >= 25)
						fallRate = 100;
					
					else if (score >= 20)
						fallRate = 200;
					
					else if (score >= 15)
						fallRate = 400;

					else if (score >= 10)
						fallRate = 600;

					else if (score >= 5)
						fallRate = 800;

					// Spawn next piece as determined by shuffler
					if (!p1.spawn(shuffler1.getNextPiece()))
					{
						gameOver = true;
						scoreDisplay.setString("Score: " + std::to_string(score) + "\nGame over");
						newGameMessage.setString("Press N to start a new game");
					}
				}
			}

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
			if (downPressed && softDropClock.getElapsedTime().asMilliseconds() >= SOFTDROPSPEED)
			{
				softDropClock.restart();
				p1.moveDown();
			}
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
				// Block movement
				if (event.key.code == sf::Keyboard::Left && !leftPressed && !gameOver)
				{
					DASclock.restart();
					ARRclock.restart();
					leftPressed = true;
					rightPressed = false;
				}
				if (event.key.code == sf::Keyboard::Right && !rightPressed && !gameOver)
				{
					DASclock.restart();
					ARRclock.restart();
					rightPressed = true;
					leftPressed = false;
				}
				if (event.key.code == sf::Keyboard::Down && !downPressed && !gameOver)
				{
					// DAS not applicable to downward movement
					softDropClock.restart();
					downPressed = true;
				}
				// Hard drop
				if (event.key.code == sf::Keyboard::Space && !gameOver)
				{
					p1.hardDrop();
					hardDrop = true;
				}

				// Block rotation
				if (event.key.code == sf::Keyboard::Up && !gameOver)
				{
					p1.rotateClockwise();
				}
				if (event.key.code == sf::Keyboard::Z && !gameOver)
				{
					p1.rotateAntiClockwise();
				}

				// Starting a new game
				if (event.key.code == sf::Keyboard::N && gameOver)
				{
					gameOver = false;
					score = 0;
					fallRate = INITIALFALLRATE;
					p1.init();
					newGameMessage.setString("");
					fallClock.restart();
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
		window.draw(newGameMessage);

		// End current frame
		window.display();
	}
}