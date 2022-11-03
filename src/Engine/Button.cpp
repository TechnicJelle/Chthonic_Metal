//
// Created by technicjelle on 03/11/22.
//

#include <SFML/Window/Mouse.hpp>

#include "Button.hpp"
namespace Engine
{
	Button::Button(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color btnColour, const std::string &btnText, const sf::Font &font, sf::Color textColour) : GameObject(window, position, size, btnColour)
	{
		text.setString(btnText);
		text.setFont(font);
		text.setFillColor(textColour);
		text.setCharacterSize((int)(size.y * 0.5f));
		text.setOrigin(text.getLocalBounds().width * 0.46f, text.getLocalBounds().height * 0.6f);
		text.setPosition(position.x + size.x / 2.0f, position.y + size.y / 2.0f);
	}

	void Button::draw()
	{
		GameObject::draw();
		window->draw(text);
	}

	bool Button::isHovered()
	{
		return rect.getGlobalBounds().contains(
				(float)sf::Mouse::getPosition(*window).x,
				(float)sf::Mouse::getPosition(*window).y);
	}

	bool Button::isClicked()
	{
		return isHovered() && sf::Mouse::isButtonPressed(sf::Mouse::Left);
	}
}