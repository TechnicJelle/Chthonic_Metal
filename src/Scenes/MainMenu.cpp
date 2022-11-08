//
// Created by technicjelle on 30/10/22.
//

#include <SFML/Window/Keyboard.hpp>
#include <filesystem>

#include "MainMenu.hpp"
#include "../GameObjects/Fire.hpp"
#include "../Engine/Utils.hpp"
#include "../Engine/Game.hpp"
#include "../AssetManager.hpp"

MainMenu::MainMenu(Engine::Game* game, sf::RenderWindow* window) : Scene(window)
{
	// === Text ===
	titleText = sf::Text("Chthonic Metal", Asset.fontAnotherDanger, window->getSize().y / 5);
	CENTER_ORIGIN(titleText);
	titleText.setPosition((float)window->getSize().x / 2.0f, (float)window->getSize().y * 0.2f);


	// === Highscore Panel ===
	highscoresPanel = new Engine::GameObject(
			window,
			sf::Vector2f((float)window->getSize().x * 0.5f, (float)window->getSize().y * 0.4f),
			sf::Vector2f((float)window->getSize().x * 0.4f, (float)window->getSize().y * 0.5f),
			sf::Color::White);

	highscoresHeaderText = sf::Text("Highscores", Asset.fontAnotherDanger, window->getSize().y / 20);
	highscoresHeaderText.setPosition(
			highscoresPanel->getPosition().x + highscoresPanel->getSize().x * 0.04f,
			highscoresPanel->getPosition().y + highscoresPanel->getSize().y * 0.01f);
	highscoresHeaderText.setFillColor(sf::Color::Black);

	highscoresText = sf::Text("Loading highscores...", Asset.fontTeko, window->getSize().y / 20);
	highscoresText.setPosition(
			highscoresPanel->getPosition().x + highscoresPanel->getSize().x * 0.05f,
			highscoresPanel->getPosition().y + highscoresPanel->getSize().y * 0.2f);
	highscoresText.setFillColor(sf::Color::Black);

	float btnClearHighscoresSize = (float)window->getSize().y / 12.0f;
	Engine::Button* btnClearHighscores = new Engine::Button(
			window,
			sf::Vector2f(
					highscoresPanel->getPosition().x + highscoresPanel->getSize().x * 0.876f,
					highscoresPanel->getPosition().y + highscoresPanel->getSize().y * 0.01f),
			sf::Vector2f(btnClearHighscoresSize, btnClearHighscoresSize),
			sf::Color::Red,
			"",
			Asset.fontAnotherDanger,
			sf::Color::White);

	btnClearHighscores->setOnClick([this]() {
		std::filesystem::remove(highscoresFile);
		loadHighscores();
	});

	sprClearHighscoresIcon = sf::Sprite(Asset.txMaterialIcon_DeleteSweep);
	CENTER_ORIGIN(sprClearHighscoresIcon);
	sprClearHighscoresIcon.setPosition(
			btnClearHighscores->getPosition().x + btnClearHighscores->getSize().x * 0.5f,
			btnClearHighscores->getPosition().y + btnClearHighscores->getSize().y * 0.5f);
	sprClearHighscoresIcon.setScale(
			btnClearHighscores->getSize().x / sprClearHighscoresIcon.getGlobalBounds().width,
			btnClearHighscores->getSize().y / sprClearHighscoresIcon.getGlobalBounds().height);

	// === GameObjects ===
	Fire* fire = new Fire(window);

	Engine::Button* playButton = new Engine::Button(
			window,
			sf::Vector2f((float)window->getSize().x * 0.2f, (float)window->getSize().y * 0.4f),
			sf::Vector2f((float)window->getSize().x * 0.26f, (float)window->getSize().y * 0.18f),
			sf::Color::Blue,
			"Start",
			Asset.fontAnotherDanger,
			sf::Color::White);

	playButton->setOnClick([game]()	{
		game->setActiveScene(Utils::SceneName::CHARACTER_SELECTION);
	});

	Engine::Button* quitButton = new Engine::Button(
			window,
			sf::Vector2f((float)window->getSize().x * 0.3f, (float)window->getSize().y * 0.6f),
			sf::Vector2f((float)window->getSize().x * 0.16f, (float)window->getSize().y * 0.12f),
			sf::Color::Red,
			"Quit",
			Asset.fontAnotherDanger,
			sf::Color::White);

	quitButton->setOnClick([window]() {
	   window->close();
	});

	gameObjects.push_back(fire);
	gameObjects.push_back(playButton);
	gameObjects.push_back(quitButton);
	gameObjects.push_back(highscoresPanel);
	gameObjects.push_back(btnClearHighscores);
}

void MainMenu::onActivate()
{
	Scene::onActivate();

	loadHighscores();
}

void MainMenu::update(float deltaTime)
{
	Scene::update(deltaTime);

	window->draw(highscoresHeaderText);
	window->draw(highscoresText);

	window->draw(sprClearHighscoresIcon);

	window->draw(titleText);

	// If Escape Key is pressed, exit the game. Only for the Main Menu!
	if (window->hasFocus() && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		printf("Escape key pressed\n");
		window->close();
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
	CENTER_ORIGIN(highscoresText);
	highscoresText.setPosition(
			highscoresPanel->getPosition().x + highscoresPanel->getSize().x * 0.48f,
			highscoresPanel->getPosition().y + (highscoresPanel->getSize().y - highscoresHeaderText.getLocalBounds().height / 2) / 2);
}
