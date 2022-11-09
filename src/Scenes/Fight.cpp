//
// Created by technicjelle on 10/11/22.
//

#include "Fight.hpp"

Fight::Fight(Engine::Game* game, sf::RenderWindow* window) : Scene(game, window)
{

}

void Fight::receiveCharacterSelection(sf::Texture& texture, const std::string& name)
{
	printf("Received character selection: %s\n", name.c_str());
	txPlayer = texture;

	sprPlayer.setTexture(txPlayer);
}

void Fight::onActivate()
{
	Scene::onActivate();
}

void Fight::update(float deltaTime)
{
	Scene::update(deltaTime);

	window->draw(sprPlayer);
}
