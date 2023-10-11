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

	updateState();
}

void PlayField::moveLeft()
{
	// Prevent anything from happening if current block doesn't exist
	if (currentBlock == nullptr)
	{
		return;
	}

	updateState(true);
	if (checkState(currentBlock->getX() - 1, currentBlock->getY()))
	{
		currentBlock->shiftPosition(-1, 0);
	}
	updateState();

}

void PlayField::moveRight()
{
	if (currentBlock == nullptr)
	{
		return;
	}

	updateState(true);
	if (checkState(currentBlock->getX() + 1, currentBlock->getY()))
	{
		currentBlock->shiftPosition(1, 0);
	}
	updateState();
}

void PlayField::moveDown()
{
	if (currentBlock == nullptr)
	{
		return;
	}

	updateState(true);
	if (checkState(currentBlock->getX(), currentBlock->getY() + 1))
	{
		currentBlock->shiftPosition(0, 1);
	}
	updateState();
}

bool PlayField::checkState(int x, int y)
{
	// Loop over columns and rows
	for (int column = x; column < x + 4; column++)
	{
		for (int row = y; row < y + 4; row++)
		{
			if (currentBlock->getBlock((column - x), (row - y)) != ' ')
			{
				if (column >= state.size())
					return false;

				if (row >= state[0].size())
					return false;

				if (column < 0)
					return false;

				// Check that the space isn't already occupied
				if (state[column][row] != ' ')
					return false;
			}
		}
	}
	return true;
}

void PlayField::updateState(bool clear)
{
	// Loop over columns and rows in current block and apply them to the PlayField
	for (int column = currentBlock->getX(); column < currentBlock->getX() + 4; column++)
	{
		for (int row = currentBlock->getY(); row < currentBlock->getY() + 4; row++)
		{
			if (currentBlock->getBlock((column - currentBlock->getX()), row - currentBlock->getY()) != ' ')
			{
				// Clear or fill square depending on parameter
				if (clear)
				{
					state[column][row] = ' ';
				}
				else
				{
					state[column][row] = currentBlock->getBlock((column - currentBlock->getX()), row - currentBlock->getY());
				}
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