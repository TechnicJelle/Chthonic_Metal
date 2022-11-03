//
// Created by technicjelle on 03/11/22.
//

#ifndef CHTHONIC_METAL_BUTTON_HPP
#define CHTHONIC_METAL_BUTTON_HPP

#include <SFML/Graphics/Text.hpp>

#include "GameObject.hpp"

namespace Engine
{
class Button : public Engine::GameObject
	{
	private:
		sf::Text text;

	public:
		Button(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color btnColour, const std::string &btnText, const sf::Font &font, sf::Color textColour);

		void draw() override;

		bool isHovered();

		bool isClicked();
	};
}

#endif //CHTHONIC_METAL_BUTTON_HPP
