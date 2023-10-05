#include "PlayField.h"

PlayField::PlayField()
{
	// Set every block in the PlayField to a certain value
	for (auto& column : state)
	{
		column.fill(' ');
	}
}

void PlayField::spawn(char type)
{
	// Re-assign smart pointer to new instance of Block class
	currentBlock.reset(new Block(type));

	// Set x and y positions of current block to spawn area
	currentBlock->shiftPosition(3, 0);

	// Loop over columns and rows in spawning area (might add as static variables later)
	for (int column = currentBlock->getX(); column < currentBlock->getX() + 4; column++)
	{
		for (int row = currentBlock->getY(); row < currentBlock->getY() + 4; row++)
		{
			if (currentBlock->getBlock((column - currentBlock->getX()), row) != ' ')
			{
				state[column][row] = currentBlock->getBlock((column - 3), row);
			}
		}
	}
}

void PlayField::moveLeft()
{

}

void PlayField::moveRight()
{
	// Prevent anything from happening if current block doesn't exist
	if (currentBlock == nullptr)
	{
		return;
	}

	// Delete initial position
	for (int column = currentBlock->getX(); column < currentBlock->getX() + 4; column++)
	{
		for (int row = currentBlock->getY(); row < currentBlock->getY() + 4; row++)
		{
			if (currentBlock->getBlock((column - currentBlock->getX()), row) != ' ')
			{
				state[column][row] = ' ';
			}
		}
	}
	currentBlock->shiftPosition(1, 0);

	// Draw in new position
	for (int column = currentBlock->getX(); column < currentBlock->getX() + 4; column++)
	{
		for (int row = currentBlock->getY(); row < currentBlock->getY() + 4; row++)
		{
			if (currentBlock->getBlock((column - currentBlock->getX()), row) != ' ')
			{
				state[column][row] = currentBlock->getBlock((column - currentBlock->getX()), row);
			}
		}
	}
}

void PlayField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int column = 0; column < state.size(); column++)
	{
		for (int row = 0; row < state[0].size(); row++)
		{
			sf::RectangleShape square(sf::Vector2f(50, 50));
			square.setPosition((SCALE * column), (SCALE * row));
			square.setSize(sf::Vector2f(SCALE, SCALE));
			square.setOutlineColor(sf::Color::Black);
			square.setOutlineThickness(-2);

			// Determine colour of square depending on contents of state array
			switch (state[column][row])
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
		}
	}
}