#include "PlayField.h"

PlayField::PlayField(): currentBlock(nullptr)
{
	// Set every block in the PlayField to a certain value
	for (auto& column : state)
	{
		for (auto& value : column)
		{
			value = ' ';
		}
	}
}

PlayField::~PlayField()
{
	delete currentBlock;
}

void PlayField::spawn(char type)
{
	delete currentBlock;
	currentBlock = new Block(type);

	// Loop over columns and rows in spawning area (might add as static variables later)
	for (int column = 3; column < 7; column++)
	{
		for (int row = 0; row < 4; row++)
		{
			state[column][row] = currentBlock->getBlock((column - 3), row);
		}
	}
}

void PlayField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	int column = 0;
	for (auto& columnValue : state)
	{
		int row = 0;
		for (auto& rowValue : columnValue)
		{
			sf::RectangleShape square(sf::Vector2f(50, 50));
			square.setPosition((SCALE * column), (SCALE * row));
			square.setSize(sf::Vector2f(SCALE, SCALE));
			square.setOutlineColor(sf::Color::Black);
			square.setOutlineThickness(-2);

			// Determine colour of square depending on contents of state array
			switch (rowValue)
			{
			case 'r':
				square.setFillColor(sf::Color::Red);
				break;
			case 'b':
				square.setFillColor(sf::Color::Blue);
				break;
			case 'c':
				square.setFillColor(sf::Color::Cyan);
				break;
			case 'y':
				square.setFillColor(sf::Color::Yellow);
				break;
			default:
				square.setFillColor(sf::Color::Black);
			}

			// Draw onto target window
			target.draw(square, states);

			row++;
		}
		column++;
	}
}