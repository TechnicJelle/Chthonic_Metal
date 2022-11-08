//
// Created by technicjelle on 03/11/22.
//

#include "GameObject.hpp"

namespace Engine
{
	GameObject::GameObject(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color colour)
	{
		this->window = window;
		rect.setPosition(position);
		rect.setSize(size);
		rect.setFillColor(colour);
	}

	void GameObject::update(float deltaTime)
	{
		
	}

	void GameObject::draw()
	{
		window->draw(rect);
	}

	sf::Vector2f GameObject::getPosition()
	{
		return rect.getPosition();
	}

	sf::Vector2f GameObject::getSize()
	{
		return rect.getSize();
	}
}
