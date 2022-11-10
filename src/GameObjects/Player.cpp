//
// Created by technicjelle on 10/11/22.
//

#include "Player.hpp"

#include <utility>


Player::Player(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size,
			   std::string name, sf::Texture &texture,
			   int startHealth, int startStamina, int attack) :
	Character(window, position, size,
			  std::move(name), texture, startHealth, startStamina, attack)
{

}
