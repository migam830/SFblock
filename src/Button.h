#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button : public sf::Drawable
{
public:
	Button(int width, int height, int xPos, int yPos, std::string buttonText, int fontSize = 50);
	bool checkPressed(sf::Event event);
	void setText(std::string text);

private:
	sf::RectangleShape buttonOutline;
	sf::Font font;
	sf::Text buttonText;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};