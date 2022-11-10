//
// Created by technicjelle on 10/11/22.
//

#ifndef CHTHONIC_METAL_PLAYER_HPP
#define CHTHONIC_METAL_PLAYER_HPP


#include "Character.hpp"

class Player : public Character
{
public:
	Player(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size,
		   std::string name, sf::Texture* texture,
		   int startHealth, int startStamina, int attack);

	std::string& getName();
};


#endif //CHTHONIC_METAL_PLAYER_HPP
