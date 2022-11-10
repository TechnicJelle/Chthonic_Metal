//
// Created by technicjelle on 10/11/22.
//

#include "Enemy.hpp"
#include "../AssetManager.hpp"
#include "../Engine/Random.hpp"

#include <utility>
#include <regex>


Enemy::Enemy(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size,
			   std::string name, sf::Texture &texture,
			   int startHealth, int startStamina, int attack) :
		Character(window, position, size,
				  std::move(name), texture, startHealth, startStamina, attack)
{

}

Enemy* Enemy::createRandomEnemy(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size)
{
	return new Enemy(window, position, size, "Enemy", Asset.getRandomPookmanTexture(),
					 100, 10, 10);
}

void Enemy::doNothing()
{
	//This actually just does absolutely nothing, not even stamina up... (requirement as per the assignment)

}

std::string Enemy::doARandomMove(Character* player)
{
	//TODO: Weighted random
	switch(Random::randi(5))
	{
		case 0:
			return std::regex_replace(str_enemyGambled, std::regex("%d"),
									  std::to_string(gambleAttack(player).second));
		case 1:
			attackCharacter(player);
			return str_enemyAttacked;
		case 2:
			heal();
			return str_enemyHealed;
		case 3:
			rest();
			return str_enemyRested;
		case 4:
			doNothing();
			return str_enemyDidNothing;
	}
	throw std::runtime_error("Random number generator returned a number that is not in the range of 0-4");
}