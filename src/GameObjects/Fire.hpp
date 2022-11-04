//
// Created by technicjelle on 03/11/22.
//

#ifndef CHTHONIC_METAL_FIRE_HPP
#define CHTHONIC_METAL_FIRE_HPP


#include "../Engine/GameObject.hpp"

class Fire : public Engine::GameObject
{
private:
	// Designer variables
	static const int RESOLUTION = 200;
	static const int STEPS_BETWEEN_COLOURS = 6; //The higher this value, the higher the flames.

	// Palette variables
	static const int PALETTE_SIZE = 5;
	static inline sf::Color colours[PALETTE_SIZE] = {
			sf::Color(0, 0, 0), // Black
			sf::Color(100, 0, 0), // Red
			sf::Color(180, 80, 0), // Orange
			sf::Color(255, 255, 0), // Yellow
			sf::Color(255, 255, 255), // White
	};

	std::vector<sf::Color> palette;

	// Fire variables
	unsigned int PIXEL_SIZE = -1;
	unsigned int PXL_WIDTH = -1;
	unsigned int PXL_HEIGHT = -1;
	unsigned int PXL_TOTAL = -1;

	unsigned int* firePixels;

private:
	// Palette functions
	static std::vector<sf::Color> makePalette();

	[[maybe_unused]] static void printPalette(std::vector<sf::Color>* palette);

	static void drawPalette(std::vector<sf::Color>* palette, sf::RenderWindow* window);

	// Fire functions
	unsigned int* createFireArray();

	void drawFireArray();

	void doFire();

	// GameObject functions
public:
	explicit Fire(sf::RenderWindow* window);

	void draw() override;
};


#endif //CHTHONIC_METAL_FIRE_HPP
