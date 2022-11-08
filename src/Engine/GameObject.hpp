//
// Created by technicjelle on 03/11/22.
//

#ifndef CHTHONIC_METAL_GAMEOBJECT_HPP
#define CHTHONIC_METAL_GAMEOBJECT_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace Engine
{
	class GameObject
	{
	protected:
		sf::RenderWindow* window;

		sf::RectangleShape rect;
	public:
		GameObject(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color colour = sf::Color::Transparent);

		virtual void update(float deltaTime);

		virtual void draw();

		sf::Vector2f getPosition();

		sf::Vector2f getSize();
	};
}

#endif //CHTHONIC_METAL_GAMEOBJECT_HPP
