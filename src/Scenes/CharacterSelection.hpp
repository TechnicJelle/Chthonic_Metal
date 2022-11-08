//
// Created by technicjelle on 08/11/22.
//

#ifndef CHTHONIC_METAL_CHARACTERSELECTION_HPP
#define CHTHONIC_METAL_CHARACTERSELECTION_HPP


#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../Engine/Scene.hpp"
#include "../Engine/Button.hpp"

class CharacterSelection : public Engine::Scene
{
private:
	sf::Text text;

	sf::Sprite sprBackground;

	sf::Sprite sprPookman_Chorizo;
	sf::Sprite sprPookman_Pukechoo;
	sf::Sprite sprPookman_Scoot;

private:
	sf::Vector2f getSpriteScale(sf::Sprite &sprite);

public:
	explicit CharacterSelection(Engine::Game* game, sf::RenderWindow* window);

	void onActivate() override;

	void update(float deltaTime) override;
};


#endif //CHTHONIC_METAL_CHARACTERSELECTION_HPP
