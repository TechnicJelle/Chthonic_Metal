//
// Created by technicjelle on 03/11/22.
//

#ifndef CHTHONIC_METAL_UTILS_HPP
#define CHTHONIC_METAL_UTILS_HPP

#include <SFML/Graphics/Color.hpp>

namespace Utils {
	inline sf::Color lerpColour(sf::Color& start, sf::Color& end, float percent) {
		sf::Uint8 r = (sf::Uint8)((float)start.r + (float)(end.r - start.r) * percent);
		sf::Uint8 g = (sf::Uint8)((float)start.g + (float)(end.g - start.g) * percent);
		sf::Uint8 b = (sf::Uint8)((float)start.b + (float)(end.b - start.b) * percent);
		sf::Uint8 a = (sf::Uint8)((float)start.a + (float)(end.a - start.a) * percent);

		return {r, g, b, a};
	}
}

#endif //CHTHONIC_METAL_UTILS_HPP