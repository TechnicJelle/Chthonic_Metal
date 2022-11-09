//
// Created by technicjelle on 08/11/22.
//

#include "CharacterSelection.hpp"
#include "../Engine/Utils.hpp"
#include "../Engine/Game.hpp"
#include "../AssetManager.hpp"

CharacterSelection::CharacterSelection(Engine::Game* game, sf::RenderWindow* window) : Scene(window)
{
	text = sf::Text("Character Selection", Asset.fontAnotherDanger, window->getSize().y / 15);
	Utils::centerOrigin(text);
	text.setPosition((float)window->getSize().x / 2.0f, (float)window->getSize().y * 0.1f);

	Engine::Button* btnBack = new Engine::Button(
			window,
			sf::Vector2f((float)window->getSize().x * 0.005f, (float)window->getSize().y * 0.01f),
			sf::Vector2f((float)window->getSize().x * 0.1f, (float)window->getSize().y * 0.1f),
			sf::Color::Magenta,
			"Back",
			Asset.fontTeko,
			sf::Color::White);

	btnBack->setOnClick([game]()
	{
		game->setActiveScene(Utils::SceneName::MAIN_MENU);
	});

	gameObjects.push_back(btnBack);

	sprBackground.setTexture(Asset.txBackground);

	sprBackground.setScale(
			(float)window->getSize().x / sprBackground.getLocalBounds().width,
			(float)window->getSize().y / sprBackground.getLocalBounds().height);

	sprBackground.setPosition(0, 0);

	float height = (float)window->getSize().y * 0.4f;
	sprPookman_Chorizo.setTexture(Asset.txPookman_Chorizo);
	Utils::centerOrigin(sprPookman_Chorizo);
	sprPookman_Chorizo.setScale(getSpriteScale(sprPookman_Chorizo));
	sprPookman_Chorizo.setPosition((float)window->getSize().x / 4.0f * 1.0f, height);

	sprPookman_Pukechoo.setTexture(Asset.txPookman_Pukechoo);
	Utils::centerOrigin(sprPookman_Pukechoo);
	sprPookman_Pukechoo.setScale(getSpriteScale(sprPookman_Pukechoo));
	sprPookman_Pukechoo.setPosition((float)window->getSize().x / 4.0f * 2.0f, height);

	sprPookman_Scoot.setTexture(Asset.txPookman_Scoot);
	Utils::centerOrigin(sprPookman_Scoot);
	sprPookman_Scoot.setScale(getSpriteScale(sprPookman_Scoot));
	sprPookman_Scoot.setPosition((float)window->getSize().x / 4.0f * 3.0f, height);
}

sf::Vector2f CharacterSelection::getSpriteScale(sf::Sprite& sprite)
{
	float scale = (float)window->getSize().x / sprite.getLocalBounds().width * 0.25f;
	return { scale, scale };
}

void CharacterSelection::onActivate()
{
	Scene::onActivate();
}

void CharacterSelection::update(float deltaTime)
{
	window->draw(sprBackground);

	Scene::update(deltaTime);

	window->draw(text);

	window->draw(sprPookman_Chorizo);
	window->draw(sprPookman_Pukechoo);
	window->draw(sprPookman_Scoot);
}
