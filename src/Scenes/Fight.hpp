//
// Created by technicjelle on 10/11/22.
//

#ifndef CHTHONIC_METAL_FIGHT_HPP
#define CHTHONIC_METAL_FIGHT_HPP


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../Engine/Scene.hpp"

class Fight : public Engine::Scene
{
private:
	sf::Texture txPlayer;
	sf::Sprite sprPlayer;

public:
	void receiveCharacterSelection(sf::Texture& texture, const std::string& name);

public:
	Fight(Engine::Game* game, sf::RenderWindow* window);

	void onActivate() override;

	void update(float deltaTime) override;

};


#endif //CHTHONIC_METAL_FIGHT_HPP
