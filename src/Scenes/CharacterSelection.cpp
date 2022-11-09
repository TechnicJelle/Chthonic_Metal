//
// Created by technicjelle on 08/11/22.
//

#include "CharacterSelection.hpp"
#include "../Engine/Utils.hpp"
#include "../Engine/Game.hpp"
#include "../AssetManager.hpp"
#include "Fight.hpp"

CharacterSelection::CharacterSelection(Engine::Game* game, sf::RenderWindow* window) : Scene(game, window)
{
	// === Title ===
	text = sf::Text("Character Selection", Asset.fontAnotherDanger, window->getSize().y / 15);
	Utils::centerOrigin(text);
	text.setPosition((float)window->getSize().x / 2.0f, (float)window->getSize().y * 0.1f);

	// === Back Button ===
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

	// === Background ===
	sprBackground.setTexture(Asset.txBackground);

	sprBackground.setScale(
			(float)window->getSize().x / sprBackground.getLocalBounds().width,
			(float)window->getSize().y / sprBackground.getLocalBounds().height);

	sprBackground.setPosition(0, 0);

	// === Character Selection Sprites ===
	float sprHeight = (float)window->getSize().y * 0.5f;
	// >Chorizo
	sprPookman_Chorizo.setTexture(Asset.txPookman_Chorizo);
	Utils::centerOrigin(sprPookman_Chorizo);
	sprPookman_Chorizo.setScale(getSpriteScale(sprPookman_Chorizo));
	sprPookman_Chorizo.setPosition((float)window->getSize().x / 4.0f * 1.0f, sprHeight);

	// >Pukechoo
	sprPookman_Pukechoo.setTexture(Asset.txPookman_Pukechoo);
	Utils::centerOrigin(sprPookman_Pukechoo);
	sprPookman_Pukechoo.setScale(getSpriteScale(sprPookman_Pukechoo));
	sprPookman_Pukechoo.setPosition((float)window->getSize().x / 4.0f * 2.0f, sprHeight);

	// >Scoot
	sprPookman_Scoot.setTexture(Asset.txPookman_Scoot);
	Utils::centerOrigin(sprPookman_Scoot);
	sprPookman_Scoot.setScale(getSpriteScale(sprPookman_Scoot));
	sprPookman_Scoot.setPosition((float)window->getSize().x / 4.0f * 3.0f, sprHeight);

	// === Character Selection Buttons ===
	float btnHeight = (float)window->getSize().y * 0.7f;
	// >Chorizo
	Engine::Button* btnPookman_Chorizo = new Engine::Button(
			window,
			sf::Vector2f(sprPookman_Chorizo.getGlobalBounds().left, btnHeight),
			sf::Vector2f(sprPookman_Chorizo.getGlobalBounds().width, (float)window->getSize().y * 0.1f),
			sf::Color::Blue,
			"Chorizo",
			Asset.fontTeko,
			sf::Color::White);

	btnPookman_Chorizo->setOnClick([game]()
	{
		Scene* scene = game->setActiveScene(Utils::SceneName::FIGHT);
		Fight* fightScene = dynamic_cast<Fight*>(scene);
		fightScene->receiveCharacterSelection(Asset.txPookman_Chorizo, "Chorizo");
	});

	gameObjects.push_back(btnPookman_Chorizo);

	// >Pukechoo
	Engine::Button* btnPookman_Pukechoo = new Engine::Button(
			window,
			sf::Vector2f(sprPookman_Pukechoo.getGlobalBounds().left, btnHeight),
			sf::Vector2f(sprPookman_Pukechoo.getGlobalBounds().width, (float)window->getSize().y * 0.1f),
			sf::Color::Blue,
			"Pukechoo",
			Asset.fontTeko,
			sf::Color::White);

	btnPookman_Pukechoo->setOnClick([game]()
	{
		Engine::Scene* scene = game->setActiveScene(Utils::SceneName::FIGHT);
		Fight* fightScene = dynamic_cast<Fight*>(scene);
		fightScene->receiveCharacterSelection(Asset.txPookman_Pukechoo, "Pukechoo");
	});

	gameObjects.push_back(btnPookman_Pukechoo);

	// >Scoot
	Engine::Button* btnPookman_Scoot = new Engine::Button(
			window,
			sf::Vector2f(sprPookman_Scoot.getGlobalBounds().left, btnHeight),
			sf::Vector2f(sprPookman_Scoot.getGlobalBounds().width, (float)window->getSize().y * 0.1f),
			sf::Color::Blue,
			"Scoot",
			Asset.fontTeko,
			sf::Color::White);

	btnPookman_Scoot->setOnClick([game]()
	{
		Engine::Scene* scene = game->setActiveScene(Utils::SceneName::FIGHT);
		Fight* fightScene = dynamic_cast<Fight*>(scene);
		fightScene->receiveCharacterSelection(Asset.txPookman_Scoot, "Scoot");
	});

	gameObjects.push_back(btnPookman_Scoot);
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
