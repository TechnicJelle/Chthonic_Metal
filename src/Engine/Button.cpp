//
// Created by technicjelle on 03/11/22.
//

#include <SFML/Window/Mouse.hpp>

#include "Button.hpp"
namespace Engine
{
	Button::Button(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color btnColour, const std::string &btnText, const sf::Font &font, sf::Color textColour) : GameObject(window, position, size, btnColour)
	{
		defaultColour = btnColour;
		const int min = 100;
		hoverColour = sf::Color(
			std::min(defaultColour.r + min, 255),
			std::min(defaultColour.g + min, 255),
			std::min(defaultColour.b + min, 255),
			defaultColour.a);
		text.setString(btnText);
		text.setFont(font);
		text.setFillColor(textColour);
		text.setCharacterSize((int)(size.y * 0.5f));
		text.setOrigin(text.getLocalBounds().width * 0.46f, text.getLocalBounds().height * 0.6f);
		text.setPosition(position.x + size.x / 2.0f, position.y + size.y / 2.0f);
	}

	void Button::setOnClick(Button::Callback onClickFunction)
	{
		callback = std::move(onClickFunction);
	}

	void Button::update(float deltaTime)
	{
		GameObject::update(deltaTime);
		isClicked();
	}

	void Button::draw()
	{
		if (isHovered())
			rect.setFillColor(hoverColour);
		else
			rect.setFillColor(defaultColour);

		GameObject::draw();
		window->draw(text);
	}

	bool Button::isHovered()
	{
		return rect.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*window));
	}

	bool Button::isClicked()
	{
		if (isHovered() && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			printf("%s button clicked\n", text.getString().toAnsiString().c_str());
			if (callback)
				callback();
			return true;
		}
		return false;
	}
}