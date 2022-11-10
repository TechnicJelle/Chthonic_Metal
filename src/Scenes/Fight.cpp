//
// Created by technicjelle on 10/11/22.
//

#include "Fight.hpp"
#include "../AssetManager.hpp"

Fight::Fight(Engine::Game* game, sf::RenderWindow* window) : Scene(game, window)
{
	player = nullptr;
	enemy = nullptr;

	// === Buttons ===

	// > Attack
	btnAttack = new Engine::Button(window,
								   sf::Vector2f((float)window->getSize().x * 0.5f, (float)window->getSize().y * 0.8f),
								   sf::Vector2f((float)window->getSize().x * 0.25f, (float)window->getSize().y * 0.1f),
								   sf::Color::Red,
								   "Attack",
								   Asset.fontTeko,
								   sf::Color::White);

	btnAttack->setOnClick([this]()
	{
		if (player->checkStamina())
		{
			if (player->attackCharacter(enemy))
			{
				textArea.setString(str_enemyDied);
				enemy = nullptr;
			}
			else
				textArea.setString(enemy->doARandomMove(player));
		}
		else
		{
			textArea.setString(str_noStamina);
		}
	});

	gameObjects.push_back(btnAttack);

	// > Speed Up
	btnGambleAttack = new Engine::Button(window,
										 sf::Vector2f((float)window->getSize().x * 0.75f, (float)window->getSize().y * 0.8f),
										 sf::Vector2f((float)window->getSize().x * 0.25f, (float)window->getSize().y * 0.1f),
										 sf::Color::Blue,
										 "Gamble Attack (5-15)",
										 Asset.fontTeko,
										 sf::Color::White);

	btnGambleAttack->setOnClick([this]()
	{
		if (player->checkStamina())
		{
			if (player->gambleAttack(enemy).first) {
				textArea.setString(str_enemyDied);
				enemy = nullptr;
			}
			else
				textArea.setString(enemy->doARandomMove(player));
		}
		else
		{
			textArea.setString(str_noStamina);
		}
	});

	gameObjects.push_back(btnGambleAttack);

	// > Heal
	btnHeal = new Engine::Button(window,
								 sf::Vector2f((float)window->getSize().x * 0.5f, (float)window->getSize().y * 0.9f),
								 sf::Vector2f((float)window->getSize().x * 0.25f, (float)window->getSize().y * 0.1f),
								 sf::Color::Green,
								 "Heal",
								 Asset.fontTeko,
								 sf::Color::White);

	btnHeal->setOnClick([this]()
	{
		player->heal();
		textArea.setString(enemy->doARandomMove(player));
	});

	gameObjects.push_back(btnHeal);

	// > Rest
	btnRest = new Engine::Button(window,
								 sf::Vector2f((float)window->getSize().x * 0.75f, (float)window->getSize().y * 0.9f),
								 sf::Vector2f((float)window->getSize().x * 0.25f, (float)window->getSize().y * 0.1f),
								 sf::Color::Magenta,
								 "Rest",
								 Asset.fontTeko,
								 sf::Color::White);

	btnRest->setOnClick([this]()
	{
		player->rest();
		textArea.setString(enemy->doARandomMove(player));
	});

	gameObjects.push_back(btnRest);

	// === Text ===
	textArea = sf::Text("Loading battle scene...", Asset.fontTeko, window->getSize().y / 15);
	textArea.setPosition((float)window->getSize().x * 0.05f, (float)window->getSize().y * 0.8f);

	// === Character Size ===
	float sprHeight = (float)window->getSize().y * 0.4f;
	characterSize = sf::Vector2f(sprHeight, sprHeight);
}

void Fight::receiveCharacterSelection(sf::Texture& txPlayer, const std::string& name)
{
	printf("Received character selection: %s\n", name.c_str());

	player = new Player(window,
						sf::Vector2f((float)window->getSize().x * 0.05f, (float)window->getSize().y * 0.1f),
						characterSize, name, txPlayer,
						100, 10, 10);

	gameObjects.push_back(player);

	createRandomEnemy();

	textArea.setString(str_waitingForPlayerMove);
}

void Fight::onActivate()
{
	Scene::onActivate();
}

void Fight::update(float deltaTime)
{
	Scene::update(deltaTime);
	if(player == nullptr) return; // Wait for character selection to be received
	if(enemy == nullptr) {
		printf("Enemy died\n");
		gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), enemy), gameObjects.end());
		createRandomEnemy();
		return; // Wait for enemy to be created
	}

	window->draw(textArea);
}

void Fight::createRandomEnemy()
{
	enemy = Enemy::createRandomEnemy(window,
									 sf::Vector2f((float)window->getSize().x * 0.95f - characterSize.x, (float)window->getSize().y * 0.1f),
									 characterSize);

	gameObjects.push_back(enemy);

}
