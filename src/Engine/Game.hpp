//
// Created by technicjelle on 30/10/22.
//

#ifndef CHTHONIC_METAL_GAME_HPP
#define CHTHONIC_METAL_GAME_HPP

#include <map>
#include <chrono>

#include "Scene.hpp"
#include "Utils.hpp"

namespace Engine
{
	class Game
	{
	private:
		std::string title;

		sf::RenderWindow window;
		std::map<Utils::SceneName, Scene*> scenes;
		Scene* currentlyActiveScene;
		Scene* nextScene;

		std::chrono::time_point<std::chrono::system_clock> frameTimePoint1, frameTimePoint2;
		float frameTimer = 1.0f;
		uint frameCount = 0;
		uint lastFPS = 0;

	public:
		Game(int width, int height, std::string title, bool vsync, sf::RenderWindow** outWindow);

		void run();

		void addScene(Scene* scene, Utils::SceneName sceneName);

		void setActiveScene(Utils::SceneName sceneName);

		uint getFPS() const;
	};
}


#endif //CHTHONIC_METAL_GAME_HPP
