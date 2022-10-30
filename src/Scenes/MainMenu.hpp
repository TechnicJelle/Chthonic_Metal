//
// Created by technicjelle on 30/10/22.
//

#ifndef CHTHONIC_METAL_MAINMENU_HPP
#define CHTHONIC_METAL_MAINMENU_HPP

#include <SFML/Graphics/CircleShape.hpp>

#include "../Engine/Scene.hpp"

class MainMenu : public Engine::Scene
{
private:
	sf::CircleShape circle;

public:
	void setup() override;

	void update(sf::RenderWindow* window, float deltaTime) override;

};


#endif //CHTHONIC_METAL_MAINMENU_HPP
