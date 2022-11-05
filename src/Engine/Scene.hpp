//
// Created by technicjelle on 30/10/22.
//

#ifndef CHTHONIC_METAL_SCENE_HPP
#define CHTHONIC_METAL_SCENE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "GameObject.hpp"

namespace Engine
{
	class Scene
	{
	protected:
		sf::RenderWindow* window;
		std::vector<GameObject*> gameObjects;

	private:
		void updateGameObjects(float deltaTime);
		void drawGameObjects();

	protected:
		explicit Scene(sf::RenderWindow* window);

	public:
		virtual void onActivate();

		virtual void update(float deltaTime);
	};
}


#endif //CHTHONIC_METAL_SCENE_HPP
