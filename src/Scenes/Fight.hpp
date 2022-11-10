//
// Created by technicjelle on 10/11/22.
//

#ifndef CHTHONIC_METAL_FIGHT_HPP
#define CHTHONIC_METAL_FIGHT_HPP


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "../Engine/Scene.hpp"
#include "../GameObjects/Player.hpp"
#include "../GameObjects/Enemy.hpp"
#include "../Engine/Button.hpp"

class Fight : public Engine::Scene
{
private:
	Player player = Player(nullptr, sf::Vector2f(), sf::Vector2f(), std::string(), nullptr, 0, 0, 0); // Initialize with nothingness. It'll get
	Enemy enemy = Enemy(nullptr, sf::Vector2f(), sf::Vector2f(), std::string(), nullptr, 0, 0, 0); // overwritten when the scene comes into view anyway.
	sf::Vector2f characterSize;

	const std::string str_waitingForPlayerMove = "Choose an action...";
	const std::string str_enemyDied = "Enemy died!";
	const std::string str_noStamina = "Not enough stamina to attack!\nChoose another action";

	sf::Text textArea;

	sf::Text headerScore;
	sf::Text textScore;

	Engine::Button* btnAttack;
	Engine::Button* btnGambleAttack;
	Engine::Button* btnHeal;
	Engine::Button* btnRest;

	Engine::Button* btnBackToMenu;

	int score = 0;

	bool gameOver = false;

	void saveHighscores();

public:
	void receiveCharacterSelection(sf::Texture& txPlayer, const std::string& name);

public:
	Fight(Engine::Game* game, sf::RenderWindow* window);

	void update(float deltaTime) override;
};


#endif //CHTHONIC_METAL_FIGHT_HPP
