#include "PlayField.h"

PlayField::PlayField()
{
	// Clear the contents of the playing field
	init();
}

void PlayField::init()
{
	// Set currentBlock to null pointer
	currentBlock.reset();

	// Set every block in the playfield to a space character
	for (auto& column : state)
	{
		column.fill(' ');
	}
}

bool PlayField::spawn(char type)
{
	// Re-assign smart pointer to new instance of Block class
	currentBlock.reset(new Block(type));

	// Game over if block can't be spawned
	if (!checkState(3, 0))
	{
		return false;
	}

	// Set x and y positions of current block to spawn area
	currentBlock->shiftPosition(3, 0);

	updateState();
	return true;
}

void PlayField::moveLeft()
{
	// Prevent anything from happening if current block doesn't exist
	if (currentBlock == nullptr)
	{
		return;
	}

	// Clear original position and check if block can be drawn in new position
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

bool PlayField::moveDown()
{
	if (currentBlock == nullptr)
	{
		return false;
	}

	bool isSuccessful = true;

	updateState(true);
	if (checkState(currentBlock->getX(), currentBlock->getY() + 1))
	{
		currentBlock->shiftPosition(0, 1);
	}
	else
	{
		isSuccessful = false;
	}
	updateState();
	return isSuccessful;
}

void PlayField::rotateClockwise()
{
	if (currentBlock == nullptr)
	{
		return;
	}
	updateState(true);
	currentBlock->rotate(true);
	if (!checkState(currentBlock->getX(), currentBlock->getY()))
	{
		currentBlock->rotate();
	}
	updateState();
}

void PlayField::rotateAntiClockwise()
{
	if (currentBlock == nullptr)
	{
		return;
	}
	updateState(true);
	currentBlock->rotate();
	if (!checkState(currentBlock->getX(), currentBlock->getY()))
	{
		currentBlock->rotate(true);
	}
	updateState();
}

void PlayField::hardDrop()
{
	if (currentBlock == nullptr)
	{
		return;
	}
	updateState(true);
	while (checkState(currentBlock->getX(), currentBlock->getY() + 1))
	{
		currentBlock->shiftPosition(0, 1);
	}
	updateState();
}

bool PlayField::checkState(int x, int y) const
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

int PlayField::clearLines()
{
	// Number of full lines
	int numClearLines = 0;

	// Clear any filled lines (loops over rows then columns)
	for (int row = 0; row < state[0].size(); row++)
	{
		bool isFull = true;
		for (int column = 0; column < state.size(); column++)
		{
			if (state[column][row] == ' ')
			{
				isFull = false;
			}
		}
		if (isFull)
		{
			numClearLines += 1;
			for (int column = 0; column < state.size(); column++)
			{
				state[column][row] = ' ';
			}
		}
	}

	// Make any rows above blank rows fall down
	for (int row = state[0].size() - 1; row > 1; row--)
	{
		bool isBlank = true;
		int blankRows = 0;
		while (isBlank && blankRows < state[0].size())
		{
			for (int column = 0; column < state.size(); column++)
			{
				if (state[column][row] != ' ')
				{
					isBlank = false;
				}
			}
			if (isBlank)
			{
				blankRows++;
				// Iterator variables named differently to avoid name collisions
				for (int newRow = row; newRow > 0; newRow--)
				{
					for (int newColumn = 0; newColumn < state.size(); newColumn++)
					{
						state[newColumn][newRow] = state[newColumn][newRow - 1];
					}
				}
			}
		}
	}
	return numClearLines;
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
			square.setOutlineColor(sf::Color(27, 27, 27));
			square.setOutlineThickness(-1);

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
			case 'o':
			// RGB code for orange since SFML doesn't have orange
				square.setFillColor(sf::Color(255, 165, 0));
				break;
			case 'g':
				square.setFillColor(sf::Color::Green);
				break;
			case 'm':
				square.setFillColor(sf::Color::Magenta);
				break;
			default:
				square.setFillColor(sf::Color::Black);
			}

			// Draw onto target window
			target.draw(square, states);
		}
	}
}