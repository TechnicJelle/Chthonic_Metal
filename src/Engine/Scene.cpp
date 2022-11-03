//
// Created by technicjelle on 30/10/22.
//

#include <cstdio>

#include "Scene.hpp"

namespace Engine
{
	Scene::Scene(sf::RenderWindow* window)
	{
		printf("Scene created\n");
		this->window = window;
	}

	void Scene::setup()
	{
		printf("Scene setup %p\n", this);
	}

	void Scene::update(float deltaTime)
	{
		drawGameObjects();
	}

	void Scene::drawGameObjects()
	{
		for (GameObject* gameObject : gameObjects)
		{
			gameObject->draw();
		}
	}
}
