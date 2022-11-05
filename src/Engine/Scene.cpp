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

	void Scene::onActivate()
	{
		printf("Scene onActivate %p\n", this);
	}

	void Scene::update(float deltaTime)
	{
		updateGameObjects(deltaTime);
		drawGameObjects();
	}

	void Scene::updateGameObjects(float deltaTime) {
		for (GameObject* gameObject : gameObjects)
		{
			gameObject->update(deltaTime);
		}
	}

	void Scene::drawGameObjects()
	{
		for (GameObject* gameObject : gameObjects)
		{
			gameObject->draw();
		}
	}
}
