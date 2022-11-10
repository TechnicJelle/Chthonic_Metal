//
// Created by technicjelle on 10/11/22.
//

#ifndef CHTHONIC_METAL_CHARACTER_HPP
#define CHTHONIC_METAL_CHARACTER_HPP


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "../Engine/GameObject.hpp"

class Character : public Engine::GameObject
{
private:
	std::string name;
	sf::Texture& texture;
	sf::Sprite sprite;

	sf::Text textName;
	sf::Text textHealth;
	sf::Text textStamina;

	int startHealth;
	int currentHealth;

	int startStamina;
	int currentStamina;

	int attack;

	bool isDead = false;

private:
	void increaseStamina();

	void decreaseStamina();

	void updateText();

public:
	Character(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size,
			  std::string name, sf::Texture& texture,
			  int startHealth, int startStamina, int attack);

	void draw() override;

	void takeDamage(int amount);

	bool checkStamina() const;

	// Moves
	/// Returns true if the target is dead
	bool attackCharacter(Character* target, int amount = -1);
	std::pair<bool, int> gambleAttack(Character* target);

	void heal();

	void rest();

	// AfterMove
	void afterMove();
};


#endif //CHTHONIC_METAL_CHARACTER_HPP
