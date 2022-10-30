//
// Created by technicjelle on 30/10/22.
//

#include "MainMenu.hpp"

void MainMenu::setup()
{
	Scene::setup();
	circle = sf::CircleShape(100);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(sf::Color::Green);
	circle.setOutlineThickness(10);
}

void MainMenu::update(sf::RenderWindow* window, float deltaTime)
{
	Scene::update(window, deltaTime);

	float x = circle.getPosition().x;
	float y = circle.getPosition().y;
	circle.setPosition(x + 100 * deltaTime, y + 100 * deltaTime);

	window->draw(circle);
}