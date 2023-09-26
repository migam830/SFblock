#include "PlayField.h"

PlayField::PlayField()
{
	// Initialise every square in playfield to blank character

	for (auto& row : state)
	{
		for (auto& value : row)
		{
			value = 'b';
		}
	}
}

void PlayField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int row = 0; row < 19; row++)
	{
		for (int column = 0; column < 9; column++)
		{
			sf::RectangleShape square(sf::Vector2f(50, 50));
			square.setPosition(SCALE * column, SCALE * row);
			//square.setOutlineColor(sf::Color::Black);

			switch (state[row][column])
			{
			case 'r':
				square.setFillColor(sf::Color::Red);
			case 'b':
				square.setFillColor(sf::Color::Blue);
			default:
				square.setFillColor(sf::Color::Black);
			}
			// Draw onto target window
			target.draw(square, states);
		}
	}
}