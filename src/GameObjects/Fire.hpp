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
	const float physicsFPS = 30;

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

	// SFML Image variables
	///the actual coloured pixels that will be drawn to the screen
	///Alpha channel is the colour index (index into the palette)
	sf::Uint8* pixels = new sf::Uint8[W*H*4];
	sf::Texture texture;
	sf::Sprite sprite;

	// Timing variables
	const float dt = 1 / physicsFPS;
	float accumulator = 0;

private:
	// Palette functions
	static std::vector<sf::Color> makePalette();

	[[maybe_unused]] static void printPalette(std::vector<sf::Color>* palette);

	[[maybe_unused]] static void drawPalette(std::vector<sf::Color>* palette, sf::RenderWindow* window);

	// Framebuffer functions
	void frameBufferInit();

	void setPixel(unsigned int x, unsigned int y, unsigned int colourIndex);

	// Fire functions
	void doFire();

	// GameObject functions
public:
	explicit Fire(sf::RenderWindow* window);

	void update(float deltaTime) override;

	void draw() override;
};


#endif //CHTHONIC_METAL_FIRE_HPP
