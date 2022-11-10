//
// Created by technicjelle on 10/11/22.
//

#include <filesystem>
#include "Fight.hpp"
#include "../AssetManager.hpp"
#include "../Engine/Utils.hpp"
#include "../Engine/Random.hpp"
#include "../Engine/Game.hpp"

Fight::Fight(Engine::Game* game, sf::RenderWindow* window) : Scene(game, window)
{
	// === Buttons ===

	// > Attack
	btnAttack = new Engine::Button(window,
								   sf::Vector2f((float)window->getSize().x * 0.5f, (float)window->getSize().y * 0.8f),
								   sf::Vector2f((float)window->getSize().x * 0.25f, (float)window->getSize().y * 0.1f),
								   sf::Color::Red,
								   "Attack",
								   Asset.fontTeko,
								   sf::Color::White);

	btnAttack->setOnClick([this]()
	{
		if (player.checkStamina())
		{
			if (player.attackCharacter(&enemy))
			{
				textArea.setString(str_enemyDied);
			}
			else
				textArea.setString(enemy.doARandomMove(&player));
		}
		else
		{
			textArea.setString(str_noStamina);
		}
	});

	// > Speed Up
	btnGambleAttack = new Engine::Button(window,
										 sf::Vector2f((float)window->getSize().x * 0.75f, (float)window->getSize().y * 0.8f),
										 sf::Vector2f((float)window->getSize().x * 0.25f, (float)window->getSize().y * 0.1f),
										 sf::Color::Blue,
										 "Gamble Attack (5-15)",
										 Asset.fontTeko,
										 sf::Color::White);

	btnGambleAttack->setOnClick([this]()
	{
		if (player.checkStamina())
		{
			if (player.gambleAttack(&enemy).first) {
				textArea.setString(str_enemyDied);
			}
			else
				textArea.setString(enemy.doARandomMove(&player));
		}
		else
		{
			textArea.setString(str_noStamina);
		}
	});


	// > Heal
	btnHeal = new Engine::Button(window,
								 sf::Vector2f((float)window->getSize().x * 0.5f, (float)window->getSize().y * 0.9f),
								 sf::Vector2f((float)window->getSize().x * 0.25f, (float)window->getSize().y * 0.1f),
								 sf::Color::Green,
								 "Heal",
								 Asset.fontTeko,
								 sf::Color::White);

	btnHeal->setOnClick([this]()
	{
		player.heal();
		textArea.setString(enemy.doARandomMove(&player));
	});


	// > Rest
	btnRest = new Engine::Button(window,
								 sf::Vector2f((float)window->getSize().x * 0.75f, (float)window->getSize().y * 0.9f),
								 sf::Vector2f((float)window->getSize().x * 0.25f, (float)window->getSize().y * 0.1f),
								 sf::Color::Magenta,
								 "Rest",
								 Asset.fontTeko,
								 sf::Color::White);

	btnRest->setOnClick([this]()
	{
		player.rest();
		textArea.setString(enemy.doARandomMove(&player));
	});

	// === Text ===
	textArea = sf::Text("Loading battle scene...", Asset.fontTeko, window->getSize().y / 15);
	textArea.setPosition((float)window->getSize().x * 0.05f, (float)window->getSize().y * 0.8f);

	headerScore = sf::Text("Score", Asset.fontTeko, window->getSize().y / 15);
	Utils::centerOrigin(headerScore);
	headerScore.setPosition((float)window->getSize().x * 0.5f, (float)window->getSize().y * 0.06f);

	textScore = sf::Text("-1", Asset.fontReggaeOne, window->getSize().y / 15);
	Utils::centerOrigin(textScore);
	textScore.setPosition((float)window->getSize().x * 0.5f, (float)window->getSize().y * 0.13f);

	// === Character Size ===
	float sprHeight = (float)window->getSize().y * 0.4f;
	characterSize = sf::Vector2f(sprHeight, sprHeight);

	// === Back To Menu Button ===
	btnBackToMenu = new Engine::Button(window,
									   sf::Vector2f((float)window->getSize().x * 0.005f, (float)window->getSize().y * 0.01f),
									   sf::Vector2f((float)window->getSize().x * 0.1f, (float)window->getSize().y * 0.1f),
									   sf::Color::Magenta,
									   "Quit",
									   Asset.fontTeko,
									   sf::Color::White);

	btnBackToMenu->setOnClick([game]()
	{
	  	game->setActiveScene(Utils::SceneName::MAIN_MENU);
	});

	gameObjects.push_back(btnBackToMenu);
}

void Fight::receiveCharacterSelection(sf::Texture& txPlayer, const std::string& name)
{
	printf("Received character selection: %s\n", name.c_str());

	float height = (float)window->getSize().y * 0.2f;
	player = Player(window,
						sf::Vector2f((float)window->getSize().x * 0.05f, height),
						characterSize, name, &txPlayer,
						100, 10, 10);

	gameObjects.push_back(&player);

	enemy = Enemy(window,
					  sf::Vector2f((float)window->getSize().x * 0.95f - characterSize.x, height),
					  characterSize, "Enemy", &Asset.getRandomPookmanTexture(),
					  100, 10, 10);

	gameObjects.push_back(&enemy);

	textArea.setString(str_waitingForPlayerMove);

	// === Turn on the Buttons ===
	gameObjects.push_back(btnRest);
	gameObjects.push_back(btnHeal);
	gameObjects.push_back(btnGambleAttack);
	gameObjects.push_back(btnAttack);

	score = 0;
	textScore.setString(std::to_string(score));

	gameOver = false;
}

void Fight::update(float deltaTime)
{
	if(enemy.checkDead()) {
		printf("Enemy died\n");
		enemy.reincarnate();
		score++;
		textScore.setString(std::to_string(score));
	}
	Scene::update(deltaTime);

	if(player.checkDead() && !gameOver) {
		printf("Player died\n");
		gameOver = true;
		//remove buttons from gameObjects
		gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), btnAttack), gameObjects.end());
		gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), btnGambleAttack), gameObjects.end());
		gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), btnHeal), gameObjects.end());
		gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), btnRest), gameObjects.end());

		textArea.setString("You died! Your score was " + std::to_string(score));
		saveHighscores();
	}

	window->draw(textArea);
	window->draw(headerScore);
	window->draw(textScore);
}


void Fight::saveHighscores()
{
	Csv_t csv;

	std::vector<std::vector<std::string>> outRows;

	if (std::filesystem::exists(Utils::highscoresFile))
	{
		if (!csv.mmap(Utils::highscoresFile))
		{
			printf("Error loading in the highscores file to save a new highscore\n");
		}
		else
		{
			//load csv into outRows vector
			for (const Row_t row : csv)
			{
				std::vector<std::string> rowVec;
				for (const Cell_t cell : row)
				{
					std::string value;
					cell.read_value(value);
					rowVec.push_back(value);
				}
				outRows.push_back(rowVec);
			}
		}
	}

	//remove all rows with less than 3 columns
	outRows.erase(std::remove_if(outRows.begin(), outRows.end(),
								 [](const std::vector<std::string>& row) { return row.size() < 3; }),
				  outRows.end());

	{
		//add new highscore to the outRows
		time_t t = std::time(nullptr);
		tm tm = *std::localtime(&t);

		std::ostringstream oss;
		oss << std::put_time(&tm, "%Y-%m-%d %H-%M");

		std::vector<std::string> newRow = {
				oss.str(),
				player.getName(),
				std::to_string(score)
		};

		outRows.push_back(newRow);
	}

	//sort outRows by score
	std::sort(outRows.begin(), outRows.end(), [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
		return std::stoi(a[2]) > std::stoi(b[2]);
	});

	//keep only the top scores
	int maxScores = 5;
	if (outRows.size() > maxScores) {
		outRows.erase(outRows.begin() + maxScores, outRows.end());
	}

	//write outRows to csv
	std::ofstream stream(Utils::highscoresFile);
	csv2::Writer<csv2::delimiter<','>> writer(stream);

	writer.write_rows(outRows);
	stream.close();
}
