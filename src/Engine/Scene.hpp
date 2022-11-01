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
	protected:
		sf::RenderWindow* window{};

	public:
		void setWindow(sf::RenderWindow* window);

		virtual void setup();

		virtual void update(float deltaTime);
	};
}


#endif //CHTHONIC_METAL_SCENE_HPP
