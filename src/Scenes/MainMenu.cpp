//
// Created by technicjelle on 30/10/22.
//

#include <memory>
#include "MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow* window) : Scene(window)
{
	if (!titleFont.loadFromFile("assets/fonts/Another Danger - Demo.otf"))
	{
		throw std::runtime_error("Could not load titleFont");
	}

	titleText = sf::Text("Chthonic Metal", titleFont, window->getSize().y / 5);
	titleText.setOrigin(titleText.getLocalBounds().width / 2, titleText.getLocalBounds().height / 2);
	titleText.setPosition((float)window->getSize().x / 2.0f, (float)window->getSize().y * 0.2f);

	playButton = new Engine::Button(
			window,
			sf::Vector2f((float)window->getSize().x * 0.2f, (float)window->getSize().y * 0.4f),
			sf::Vector2f(400, 200),
			sf::Color::Blue,
			"Start",
			titleFont,
			sf::Color::White);

	gameObjects.push_back(playButton);

	quitButton = new Engine::Button(
			window,
			sf::Vector2f((float)window->getSize().x * 0.3f, (float)window->getSize().y * 0.6f),
			sf::Vector2f(300, 150),
			sf::Color::Red,
			"Quit",
			titleFont,
			sf::Color::White);

	gameObjects.push_back(quitButton);


	highscoresPanel = sf::RectangleShape(sf::Vector2f((float)window->getSize().x * 0.4f, (float)window->getSize().y * 0.5f));
	highscoresPanel.setFillColor(sf::Color::White);
	highscoresPanel.setPosition((float)window->getSize().x * 0.5f, (float)window->getSize().y * 0.4f);

	highscoresText = sf::Text("Highscores\nTechnicJelle\t\t\tinf", titleFont, window->getSize().y / 20);
	highscoresText.setPosition(highscoresPanel.getPosition().x + highscoresPanel.getSize().x * 0.04f, highscoresPanel.getPosition().y);
	highscoresText.setFillColor(sf::Color::Black);
}

void MainMenu::setup()
{
	Scene::setup();
}

void MainMenu::update(float deltaTime)
{
	Scene::update(deltaTime);

	window->draw(highscoresPanel);
	window->draw(highscoresText);

	window->draw(titleText);

	if (playButton->isClicked())
	{
		printf("Play button clicked\n");
	}

	if (quitButton->isClicked())
	{
		printf("Quit button clicked\n");
		exit(0);
	}
}
