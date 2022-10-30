//
// Created by technicjelle on 30/10/22.
//

#include <cstdio>

#include "Scene.hpp"

namespace Engine
{
	void Scene::setup()
	{
		printf("Scene setup %p\n", this);
	}

	void Scene::update(sf::RenderWindow* window, float deltaTime)
	{
//		printf("Scene update, %f\n", deltaTime);
	}
}
