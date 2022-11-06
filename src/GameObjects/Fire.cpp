//
// Created by technicjelle on 03/11/22.
//

#include "Fire.hpp"
#include "../Engine/Utils.hpp"
#include "../Engine/Random.hpp"

Fire::Fire(sf::RenderWindow* window) : Engine::GameObject(window, sf::Vector2f(0, 0), (sf::Vector2f)window->getSize())
{
	palette = makePalette();
//	printPalette(&palette);

	texture.create(W, H);
	sprite = sf::Sprite(texture);
	sprite.scale((float)window->getSize().x / (float)W, (float)window->getSize().y / (float)H);

	frameBufferInit();
}

void Fire::update(float deltaTime)
{
	//https://gamedevelopment.tutsplus.com/tutorials/how-to-create-a-custom-2d-physics-engine-the-core-engine--gamedev-7493#timestepping
	// Store the time elapsed since the last frame began
	accumulator += deltaTime;

	// Avoid spiral of death and clamp dt, thus clamping
	// how many times the UpdatePhysics can be called in
	// a single game loop.
	if (accumulator > 0.2f)
		accumulator = 0.2f;

	while (accumulator >= dt)
	{
		accumulator -= dt;

		doFire();
		texture.update(pixels);
	}
}

void Fire::draw()
{
	window->draw(sprite);
//	drawPalette(&palette, window);
}

std::vector<sf::Color> Fire::makePalette()
{
	std::vector<sf::Color> palette;

	for (int i = 0; i < BASE_PALETTE_SIZE - 1; i++) //-1 to make up for the +1 in the loop
	{
		sf::Color c1 = colours[i];
		sf::Color c2 = colours[i + 1];
		for (int s = 0; s < STEPS_BETWEEN_COLOURS; ++s)
		{
			sf::Color c = Utils::lerpColour(c1, c2, (float)s / STEPS_BETWEEN_COLOURS);
			palette.push_back(c);
		}
	}
	palette.push_back(colours[BASE_PALETTE_SIZE - 1]); //make sure pure white is in the palette

	return palette;
}

[[maybe_unused]] void Fire::printPalette(std::vector<sf::Color>* palette)
{
	for (int i = 0; i < palette->size(); i++)
	{
		printf("Palette index %d: %d, %d, %d\n",
			   i, palette->at(i).r, palette->at(i).g, palette->at(i).b);
	}
}

[[maybe_unused]] void Fire::drawPalette(std::vector<sf::Color>* palette, sf::RenderWindow* window)
{
	for (int i = 0; i < palette->size(); i++)
	{
		sf::RectangleShape rect;
		rect.setPosition(sf::Vector2f(10, (float)(i+1) * 10));
		rect.setSize(sf::Vector2f(100, 10));
		rect.setFillColor(palette->at(i));
		rect.setOutlineThickness(0);
		rect.setOutlineColor(sf::Color::Transparent);
		window->draw(rect);
	}
}

void Fire::frameBufferInit()
{
	//Fill with black
	for (int x = 0; x < W; x++)
		for (int y = 0; y < H; y++)
			setPixel(x, y, 0);

	//Set the bottom row to white
	for (int x = 0; x < W; x++)
		setPixel(x, (H - 1), (sf::Uint8)palette.size() - 1);

}

void Fire::doFire()
{
	for(unsigned int x = 0 ; x < W; x++) {
		for (unsigned int y = 1; y < H ; y++) {
			unsigned int colourIndex = 255 - pixels[(x + y * W) * 4 + 3];
			unsigned int indexY = y - 1;
			if(colourIndex) {
				unsigned int rnd = Random::randi(0, 3);
				unsigned int indexX = (x - rnd + 1) % W;
				setPixel(indexX, indexY, colourIndex - (rnd & 1));
			}
			else {
				unsigned int indexX = x;
				setPixel(indexX, indexY, 0);
			}
		}
	}
}

void Fire::setPixel(unsigned int x, unsigned int y, unsigned int colourIndex)
{
	unsigned int index = (x + y * W) * 4;
	sf::Color c = palette[colourIndex];
//	pixels[index + 0] = c.r;
//	pixels[index + 1] = c.g;
//	pixels[index + 2] = c.b;
	memcpy(pixels + index, &c.r, 3 /* * sizeof(c.r) */);
	pixels[index + 3] = 255 - colourIndex;
}
