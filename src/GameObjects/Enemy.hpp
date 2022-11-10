//
// Created by technicjelle on 10/11/22.
//

#ifndef CHTHONIC_METAL_ENEMY_HPP
#define CHTHONIC_METAL_ENEMY_HPP


#include "Character.hpp"

class Enemy : public Character
{
public:
	std::string str_enemyAttacked = "Enemy attacked!";
	std::string str_enemyGambled = "Enemy gambled and did %d damage!";
	std::string str_enemyHealed = "Enemy healed!";
	std::string str_enemyRested = "Enemy rested!";
	std::string str_enemyDidNothing = "Enemy did nothing..?";

public:
	Enemy(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size,
		  std::string name, sf::Texture* texture,
		  int startHealth, int startStamina, int attack);

	/// Returns string of what the enemy did
	std::string doARandomMove(Character* player);

	// Moves
	void doNothing();

	void reincarnate();
};


#endif //CHTHONIC_METAL_ENEMY_HPP
