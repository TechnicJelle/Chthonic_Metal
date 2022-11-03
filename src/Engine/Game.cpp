//
// Created by technicjelle on 30/10/22.
//

#include <SFML/Window/Event.hpp>

#include "Game.hpp"
#include "Random.hpp"

namespace Engine
{
	Game::Game(int width, int height, std::string title, bool vsync, sf::RenderWindow** outWindow)
	{
		this->title = std::move(title);
		window.create(sf::VideoMode(width, height), this->title);
		window.setVerticalSyncEnabled(vsync);
		*outWindow = &window;

		scenes = std::vector<Scene*>();
		activeScene = nullptr;

		frameTimePoint1 = std::chrono::system_clock::now();

		Random::randInit();
	}

	void Game::run()
	{
		while (window.isOpen())
		{
			// Handle Timing
			frameTimePoint2 = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsedTime = frameTimePoint2 - frameTimePoint1;
			frameTimePoint1 = frameTimePoint2;

			// Our time per frame coefficient
			float fElapsedTime = (float)elapsedTime.count();

			// Handle Events
			sf::Event event{ };
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();

			activeScene->update(fElapsedTime);

			window.display();

			// Update Title Bar
			frameTimer += fElapsedTime;
			frameCount++;
			if (frameTimer >= 1.0f)
			{
				lastFPS = frameCount;
				frameTimer -= 1.0f;
				window.setTitle(title + " - FPS: " + std::to_string(getFPS()));
				frameCount = 0;
			}
		}
	}

	void Game::addScene(Scene* scene)
	{
		scenes.push_back(scene);
	}

	void Game::setActiveScene(Scene* scene)
	{
		activeScene = scene;
		printf("Active scene set to %s, at %p\n", typeid(*scene).name(), scene);
	}

	uint Game::getFPS() const
	{
		return lastFPS;
	}
}
