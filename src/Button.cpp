#include "Button.h"

Button::Button(int width, int height, int xPos, int yPos, std::string inputButtonText)
{
	// Load font from file
	if (!font.loadFromFile("res/SourceSans3-Regular.ttf"))
	{
		throw "Font not found";
	}

	// Set properties of game button
	buttonOutline.setPosition(xPos, yPos);
	buttonOutline.setSize(sf::Vector2f(width, height));
	buttonOutline.setFillColor(sf::Color(93, 173, 226));
	buttonOutline.setOutlineColor(sf::Color::Black);
	buttonOutline.setOutlineThickness(10);

	// Set properties of text elements
	buttonText.setFont(font);
	buttonText.setCharacterSize(50);
	buttonText.setFillColor(sf::Color::Black);
	buttonText.setString(inputButtonText);

	buttonText.setOrigin(buttonText.getGlobalBounds().getSize() / 2.f + buttonText.getLocalBounds().getPosition());
	buttonText.setPosition(buttonOutline.getPosition() + (buttonOutline.getSize() / 2.f));
}

bool Button::checkPressed(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left && buttonOutline.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		{
			return true;
		}
	}
	return false;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(buttonOutline, states);
	target.draw(buttonText, states);
}