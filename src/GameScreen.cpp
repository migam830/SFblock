#include "GameScreen.h"
#include "RandomShuffler.h"
#include "SevenBagShuffler.h"

GameScreen::GameScreen() : newGameButton(300, 100, 50, 300, "New Game"), shufflerButton(300, 100, 50, 450, "7 bag"), backButton(300, 100, 450, 700, "Home Screen")
{
	// Initialise attributes
	fallRate = INITIALFALLRATE;
	shufflerType = 0;
	score = 0;
	leftPressed = false;
	rightPressed = false;
	downPressed = false;
	hardDrop = false;
	gameOver = true;

	// Load font from file
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

	// Set properties of game instructions
	gameInstructions.setPosition(425, 125);
	gameInstructions.setFont(font);
	gameInstructions.setCharacterSize(40);
	gameInstructions.setFillColor(sf::Color::Blue);
	gameInstructions.setString("Controls:\nMove block: left, right\nRotate block: up, Z\nSoft drop: down\nHard drop: space");

	// Set properties of shuffler explanation
	shufflerExplanation.setPosition(425, 400);
	shufflerExplanation.setFont(font);
	shufflerExplanation.setCharacterSize(30);
	shufflerExplanation.setFillColor(sf::Color::Red);
	shufflerExplanation.setString("7 bag:\nAll seven blocks selected\nbefore any can repeat\nRandom:\nNext block randomly selected");

	// Initialise shuffler pointer
	currentShuffler.reset(new SevenBagShuffler);
}

int GameScreen::run(sf::RenderWindow& window)
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
					if (score >= 40)
						fallRate = 300;

					else if (score >= 30)
						fallRate = 350;

					else if (score >= 20)
						fallRate = 400;

					else if (score >= 10)
						fallRate = 600;

					else if (score >= 5)
						fallRate = 800;

					// Spawn next piece as determined by shuffler
					if (!p1.spawn(currentShuffler->getNextPiece()))
					{
						gameOver = true;
						scoreDisplay.setString("Score: " + std::to_string(score) + "\nGame over");
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
				return -1;
			}

			// Start new game if button is pressed
			if (newGameButton.checkPressed(event) && gameOver)
			{
				gameOver = false;
				score = 0;
				fallRate = INITIALFALLRATE;
				p1.init();
				fallClock.restart();

				// Initialise shuffler if applicable
				currentShuffler->init();
			}

			// Toggle shuffler type if button is pressed
			if (shufflerButton.checkPressed(event) && gameOver)
			{
				if (shufflerType == 0)
				{
					shufflerType = 1;
					currentShuffler.reset(new RandomShuffler);
					shufflerButton.setText("Random");
				}
				else
				{
					shufflerType = 0;
					currentShuffler.reset(new SevenBagShuffler);
					shufflerButton.setText("7 bag");
				}
			}

			// Return back to the home screen if button is pressed
			if (backButton.checkPressed(event) && gameOver)
			{
				return 0;
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
		window.draw(gameInstructions);
		window.draw(shufflerExplanation);

		// Only draw buttons if game is over
		if (gameOver)
		{
			window.draw(newGameButton);
			window.draw(shufflerButton);
			window.draw(backButton);
		}

		// End current frame
		window.display();
	}
	// Exit window if this code is reached
	return -1;
}