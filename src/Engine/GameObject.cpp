//
// Created by technicjelle on 03/11/22.
//

#include "GameObject.hpp"

namespace Engine
{
	GameObject::GameObject(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color colour = sf::Color::Transparent)
	{
		this->window = window;
		rect.setPosition(position);
		rect.setSize(size);
		rect.setFillColor(colour);
	}

	void GameObject::draw()
	{
		window->draw(rect);
	}
}
