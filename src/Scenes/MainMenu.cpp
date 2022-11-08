//
// Created by technicjelle on 30/10/22.
//

#include <SFML/Window/Keyboard.hpp>
#include <filesystem>

#include "MainMenu.hpp"
#include "../GameObjects/Fire.hpp"
#include "../Engine/Utils.hpp"

MainMenu::MainMenu(sf::RenderWindow* window) : Scene(window)
{
	// === Text ===
	if (!titleFont.loadFromFile("assets/fonts/Another Danger/Another Danger - Demo.otf"))
	{
		throw std::runtime_error("Could not load titleFont");
	}

	titleText = sf::Text("Chthonic Metal", titleFont, window->getSize().y / 5);
	titleText.setOrigin(titleText.getLocalBounds().width / 2, titleText.getLocalBounds().height / 2);
	titleText.setPosition((float)window->getSize().x / 2.0f, (float)window->getSize().y * 0.2f);

	highscoresPanel = sf::RectangleShape(sf::Vector2f((float)window->getSize().x * 0.4f, (float)window->getSize().y * 0.5f));
	highscoresPanel.setFillColor(sf::Color::White);
	highscoresPanel.setPosition((float)window->getSize().x * 0.5f, (float)window->getSize().y * 0.4f);

	highscoresHeaderText = sf::Text("Highscores", titleFont, window->getSize().y / 20);
	highscoresHeaderText.setPosition(
			highscoresPanel.getPosition().x + highscoresPanel.getSize().x * 0.04f,
			highscoresPanel.getPosition().y + highscoresPanel.getSize().y * 0.01f);
	highscoresHeaderText.setFillColor(sf::Color::Black);

	if (!highscoresFont.loadFromFile("assets/fonts/Teko/Teko-Medium.ttf"))
	{
		throw std::runtime_error("Could not load highscoresFont");
	}

	highscoresText = sf::Text("Loading highscores...", highscoresFont, window->getSize().y / 20);
	highscoresText.setPosition(
			highscoresPanel.getPosition().x + highscoresPanel.getSize().x * 0.05f,
			highscoresPanel.getPosition().y + highscoresPanel.getSize().y * 0.2f);
	highscoresText.setFillColor(sf::Color::Black);

	// === GameObjects ===
	Fire* fire = new Fire(window);
	gameObjects.push_back(fire);

	playButton = new Engine::Button(
			window,
			sf::Vector2f((float)window->getSize().x * 0.2f, (float)window->getSize().y * 0.4f),
			sf::Vector2f((float)window->getSize().x * 0.26f, (float)window->getSize().y * 0.18f),
			sf::Color::Blue,
			"Start",
			titleFont,
			sf::Color::White);

	playButton->setOnClick([this]()
	{
		printf("//TODO: Start game\n");
	});

	gameObjects.push_back(playButton);

	quitButton = new Engine::Button(
			window,
			sf::Vector2f((float)window->getSize().x * 0.3f, (float)window->getSize().y * 0.6f),
			sf::Vector2f((float)window->getSize().x * 0.16f, (float)window->getSize().y * 0.12f),
			sf::Color::Red,
			"Quit",
			titleFont,
			sf::Color::White);

	quitButton->setOnClick([window]() {
	   window->close();
	});

	gameObjects.push_back(quitButton);
}

void MainMenu::onActivate()
{
	Scene::onActivate();

	loadHighscores();
}

void MainMenu::update(float deltaTime)
{
	Scene::update(deltaTime);

	window->draw(highscoresPanel);
	window->draw(highscoresHeaderText);
	window->draw(highscoresText);

	window->draw(titleText);

	// If Escape Key is pressed, exit the game. Only for the Main Menu!
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		printf("Escape key pressed\n");
		exit(0);
	}
}

void MainMenu::loadHighscores()
{
	Csv_t csv;

	if (std::filesystem::exists(highscoresFile))
	{
		if (!csv.mmap(highscoresFile))
		{
			highscoresText.setString("Error loading in the highscores");
		}
		else
		{
			std::string highscoresString;
			/*const Row_t header = csv.header();

			for (const Cell_t cell : header)
			{
				std::string value;
				cell.read_value(value);
				highscoresString += value + " ";
			}
			highscoresString += "\n";*/

			for (const Row_t row : csv)
			{
				for (const Cell_t cell : row)
				{
					std::string value;
					cell.read_value(value);
					highscoresString += value + " ";
				}
				highscoresString += "\n";
			}
			highscoresText.setString(highscoresString);
			return; //do not center the text
		}
	}
	else
	{
		highscoresText.setString("No highscores yet");
	}

	//position in middle of panel:
	highscoresText.setOrigin(
			highscoresText.getLocalBounds().width / 2,
			highscoresText.getLocalBounds().height / 2);
	highscoresText.setPosition(
			highscoresPanel.getPosition().x + highscoresPanel.getSize().x * 0.48f,
			highscoresPanel.getPosition().y + (highscoresPanel.getSize().y - highscoresHeaderText.getLocalBounds().height / 2) / 2);
}
