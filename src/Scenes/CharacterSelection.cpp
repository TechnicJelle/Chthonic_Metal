//
// Created by technicjelle on 08/11/22.
//

#include "CharacterSelection.hpp"
#include "../Engine/Utils.hpp"
#include "../Engine/Game.hpp"

CharacterSelection::CharacterSelection(Engine::Game* game, sf::RenderWindow* window) : Scene(window)
{
	if (!bigFont.loadFromFile("assets/fonts/Another Danger/Another Danger - Demo.otf"))
	{
		throw std::runtime_error("Could not load bigFont");
	}

	if (!smallFont.loadFromFile("assets/fonts/Teko/Teko-Medium.ttf"))
	{
		throw std::runtime_error("Could not load smallFont");
	}

	text = sf::Text("Character Selection", bigFont, window->getSize().y / 15);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	text.setPosition((float)window->getSize().x / 2.0f, (float)window->getSize().y * 0.2f);

	btnBack = new Engine::Button(
			window,
			sf::Vector2f((float)window->getSize().x * 0.005f, (float)window->getSize().y * 0.01f),
			sf::Vector2f((float)window->getSize().x * 0.1f, (float)window->getSize().y * 0.1f),
			sf::Color::Magenta,
			"Back",
			smallFont,
			sf::Color::White);

	btnBack->setOnClick([game]()
	{
		game->setActiveScene(Utils::SceneName::MAIN_MENU);
	});

	gameObjects.push_back(btnBack);
}

void CharacterSelection::onActivate()
{
	Scene::onActivate();
}

void CharacterSelection::update(float deltaTime)
{
	Scene::update(deltaTime);
	window->draw(text);
}
