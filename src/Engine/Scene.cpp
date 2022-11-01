//
// Created by technicjelle on 30/10/22.
//

#include <cstdio>

#include "Scene.hpp"

namespace Engine
{
	void Scene::setWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}

	void Scene::setup()
	{
		printf("Scene setup %p\n", this);
	}

	void Scene::update(float deltaTime)
	{
//		printf("Scene update, %f\n", deltaTime);
	}
}
