//
// Created by technicjelle on 30/10/22.
//

#ifndef CHTHONIC_METAL_MAINMENU_HPP
#define CHTHONIC_METAL_MAINMENU_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "../Engine/Scene.hpp"

class MainMenu : public Engine::Scene
{
private:
	sf::CircleShape circle;
	sf::Font titleFont;
	sf::Text titleText;

public:
	void setup() override;

	void update(float deltaTime) override;
};


#endif //CHTHONIC_METAL_MAINMENU_HPP
