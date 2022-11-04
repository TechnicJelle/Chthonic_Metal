//
// Created by technicjelle on 03/11/22.
//

#ifndef CHTHONIC_METAL_FIRE_HPP
#define CHTHONIC_METAL_FIRE_HPP


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "../Engine/GameObject.hpp"

class Fire : public Engine::GameObject
{
private:
	// Designer variables
	const unsigned int W = 256;
	const unsigned int H = 144;
	static const int STEPS_BETWEEN_COLOURS = 4; //The higher this value, the higher the flames.

private:
	// Palette variables
	static const int BASE_PALETTE_SIZE = 5;
	static inline sf::Color colours[BASE_PALETTE_SIZE] = {
			sf::Color(0, 0, 0), // Black
			sf::Color(130, 0, 0), // Red
			sf::Color(180, 80, 0), // Orange
			sf::Color(255, 255, 0), // Yellow
			sf::Color(255, 255, 255), // White
	};

	std::vector<sf::Color> palette;

	// Framebuffer variables
	///index into the palette
	sf::Uint8* frameBuffer = new sf::Uint8[W * H];

	// SFML Image variables
	///the actual coloured pixels that will be drawn to the screen
	sf::Uint8* pixels = new sf::Uint8[W*H*4];
	sf::Texture texture;
	sf::Sprite sprite;

private:
	// Palette functions
	static std::vector<sf::Color> makePalette();

	[[maybe_unused]] static void printPalette(std::vector<sf::Color>* palette);

	static void drawPalette(std::vector<sf::Color>* palette, sf::RenderWindow* window);

	// GameObject functions
public:
	explicit Fire(sf::RenderWindow* window);

	void draw() override;

	void frameBufferInit();

	void frameBufferToPixels();

	void doFire();
};


#endif //CHTHONIC_METAL_FIRE_HPP
