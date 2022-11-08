//
// Created by technicjelle on 08/11/22.
//

#ifndef CHTHONIC_METAL_CHARACTERSELECTION_HPP
#define CHTHONIC_METAL_CHARACTERSELECTION_HPP


#include <SFML/Graphics/Text.hpp>
#include "../Engine/Scene.hpp"
#include "../Engine/Button.hpp"

class CharacterSelection : public Engine::Scene
{
private:
	sf::Font bigFont;
	sf::Font smallFont;
	sf::Text text;

	Engine::Button* btnBack;

public:
	explicit CharacterSelection(Engine::Game* game, sf::RenderWindow* window);

	void onActivate() override;

	void update(float deltaTime) override;
};


#endif //CHTHONIC_METAL_CHARACTERSELECTION_HPP
