//
// Created by technicjelle on 03/11/22.
//

#ifndef CHTHONIC_METAL_BUTTON_HPP
#define CHTHONIC_METAL_BUTTON_HPP

#include <SFML/Graphics/Text.hpp>
#include <functional>

#include "GameObject.hpp"

namespace Engine
{
	class Button : public Engine::GameObject
		{
		private:
			sf::Text text;
			sf::Color defaultColour;
			sf::Color hoverColour;

			bool isBeingClicked = false;

			using Callback = std::function<void()>;
			Callback callback;

		public:
			Button(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color btnColour,
				   const std::string &btnText, const sf::Font &font, sf::Color textColour);

			void setOnClick(Callback onClickFunction);

	private:
			void update(float deltaTime) override;

			void draw() override;

			bool isHovered();

			bool isClicked();
	};
}

#endif //CHTHONIC_METAL_BUTTON_HPP
