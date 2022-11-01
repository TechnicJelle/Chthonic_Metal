//
// Created by technicjelle on 30/10/22.
//

#include <SFML/Graphics/Font.hpp>

#include "MainMenu.hpp"

void MainMenu::setup()
{
	Scene::setup();
	circle = sf::CircleShape(100);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(sf::Color::Green);
	circle.setOutlineThickness(10);

	if (!titleFont.loadFromFile("assets/fonts/Another Danger - Demo.otf"))
	{
		throw std::runtime_error("Could not load titleFont");
	}

	titleText = sf::Text("Chthonic Metal", titleFont, window->getSize().y / 10);
	titleText.setOrigin(titleText.getLocalBounds().width / 2, titleText.getLocalBounds().height / 2);
	titleText.setPosition((float)window->getSize().x / 2.0f, (float)window->getSize().y * 0.2f);
}

void MainMenu::update(float deltaTime)
{
	Scene::update(deltaTime);

	float x = circle.getPosition().x;
	float y = circle.getPosition().y;
	circle.setPosition(x + 100 * deltaTime, y + 100 * deltaTime);

	window->draw(circle);

	window->draw(titleText);
}
