//
// Created by technicjelle on 30/10/22.
//

#ifndef CHTHONIC_METAL_GAME_HPP
#define CHTHONIC_METAL_GAME_HPP

#include <vector>
#include <chrono>

#include "Scene.hpp"

namespace Engine
{
	class Game
	{
	private:
		std::string title;

		sf::RenderWindow window;
		std::vector<Scene*> scenes;
		Scene* activeScene;

		std::chrono::time_point<std::chrono::system_clock> frameTimePoint1, frameTimePoint2;
		float frameTimer = 1.0f;
		uint frameCount = 0;
		uint lastFPS = 0;

	public:
		Game(int width, int height, std::string title, bool vsync, sf::RenderWindow** outWindow);

		void run();

		void addScene(Scene* scene);

		void setActiveScene(Scene* scene);

		uint getFPS() const;
	};
}


#endif //CHTHONIC_METAL_GAME_HPP
