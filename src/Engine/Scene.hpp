//
// Created by technicjelle on 30/10/22.
//

#ifndef CHTHONIC_METAL_SCENE_HPP
#define CHTHONIC_METAL_SCENE_HPP

#include <SFML/Graphics/RenderWindow.hpp>

namespace Engine
{
	class Scene
	{
	public:
		virtual void setup();

		virtual void update(sf::RenderWindow* window, float deltaTime);
	};
}


#endif //CHTHONIC_METAL_SCENE_HPP
