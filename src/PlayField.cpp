#include "PlayField.h"

PlayField::PlayField()
{
	// Set every block in the PlayField to a certain value
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
	int row = 0;
	for (auto& rowValue : state)
	{
		int column = 0;
		for (auto& columnValue : rowValue)
		{
			sf::RectangleShape square(sf::Vector2f(50, 50));
			square.setPosition((SCALE * column), (SCALE * row));
			square.setSize(sf::Vector2f(SCALE, SCALE));
			square.setOutlineColor(sf::Color::Black);
			square.setOutlineThickness(-2);

			switch (columnValue)
			{
			case 'r':
				square.setFillColor(sf::Color::Red);
				break;
			case 'b':
				square.setFillColor(sf::Color::Blue);
				break;
			default:
				square.setFillColor(sf::Color::Black);
			}

			// Draw onto target window
			target.draw(square, states);

			column++;
		}
		row++;
	}
}