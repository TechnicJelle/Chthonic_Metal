//
// Created by technicjelle on 10/11/22.
//

#include "Character.hpp"
#include "../AssetManager.hpp"
#include "../Engine/Random.hpp"

#include <utility>

Character::Character(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size,
					 std::string name, sf::Texture* texture,
					 int startHealth, int startStamina, int attack) :
	GameObject(window, position, size, sf::Color(255, 255, 255, 10)),
	name(std::move(name)), texture(texture),
		startHealth(startHealth), currentHealth(startHealth),
		startStamina(startStamina), currentStamina(startStamina),
		attack(attack)
{
	if(window == nullptr) return;
	sprite.setTexture(*this->texture);
	sprite.setPosition(position);
	sprite.setScale(size.x / sprite.getGlobalBounds().width, size.y / sprite.getGlobalBounds().height);

	textName = sf::Text(this->name, Asset.fontAnotherDanger, window->getSize().y / 20);
	textName.setFillColor(sf::Color::White);
	textName.setPosition(position.x, position.y - textName.getGlobalBounds().height);

	textHealth = sf::Text("Health 1/1", Asset.fontTeko, window->getSize().y / 25);
	textHealth.setFillColor(sf::Color::White);
	textHealth.setPosition(position.x, position.y + size.y);

	textStamina = sf::Text("Stamina 1/1", Asset.fontTeko, window->getSize().y / 25);
	textStamina.setFillColor(sf::Color::White);
	textStamina.setPosition(position.x, textHealth.getPosition().y + textHealth.getGlobalBounds().height);

	updateText();
}

void Character::draw()
{
	Engine::GameObject::draw();
	window->draw(sprite);
	window->draw(textName);
	window->draw(textHealth);
	window->draw(textStamina);
}

void Character::increaseStamina()
{
	currentStamina = std::min(currentStamina + 1, startStamina);
}

void Character::decreaseStamina()
{
	currentStamina = std::max(currentStamina - 2, 0);
}

void Character::updateText()
{
	textHealth.setString("Health " + std::to_string(currentHealth) + "/" + std::to_string(startHealth));
	textStamina.setString("Stamina " + std::to_string(currentStamina) + "/" + std::to_string(startStamina));
}

void Character::takeDamage(int amount)
{
	currentHealth -= amount;
	updateText();

	if(currentHealth <= 0)
	{
		isDead = true;
	}
}

bool Character::checkStamina() const
{
	return currentStamina >= 2;
}

bool Character::checkDead() const
{
	return isDead;
}

// Moves
bool Character::attackCharacter(Character* target, int amount)
{
	if (amount == -1)
		amount = attack;

	if(checkStamina())
	{
		target->takeDamage(amount);
		decreaseStamina();
	}
	afterMove();

	return target->isDead;
}

std::pair<bool, int> Character::gambleAttack(Character* target)
{
	int amount = Random::randi(5, 15);
	return std::pair<bool, int>{attackCharacter(target, amount), amount};
}

void Character::heal()
{
	currentHealth = std::min(currentHealth + 5, startHealth);
	afterMove();
}

void Character::rest()
{
	increaseStamina();
	afterMove();
}

// AfterMove
void Character::afterMove()
{
	increaseStamina();
	updateText();
}
