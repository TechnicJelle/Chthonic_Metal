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

	// get from RESOLUTION and maximum of the screen dimensions
	PIXEL_SIZE = (uint)std::min(window->getSize().x, window->getSize().y) / RESOLUTION;
	PXL_WIDTH = window->getSize().x / PIXEL_SIZE;
	PXL_HEIGHT = window->getSize().y / PIXEL_SIZE;
	PXL_TOTAL = PXL_WIDTH * PXL_HEIGHT;

	firePixels = createFireArray();
}

void Fire::draw()
{
	GameObject::draw();
	drawPalette(&palette, window);
	drawFireArray();
	doFire();
}

std::vector<sf::Color> Fire::makePalette()
{
	std::vector<sf::Color> palette;

	for (int i = 0; i < PALETTE_SIZE-1; i++) //-1 to make up for the +1 in the loop
	{
		sf::Color c1 = colours[i];
		sf::Color c2 = colours[i + 1];
		for (int s = 0; s < STEPS_BETWEEN_COLOURS; ++s)
		{
			sf::Color c = Utils::lerpColour(c1, c2, (float)(s) / STEPS_BETWEEN_COLOURS);
			palette.push_back(c);
		}
	}

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

void Fire::drawPalette(std::vector<sf::Color>* palette, sf::RenderWindow* window)
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

uint* Fire::createFireArray()
{
	uint* array = new uint[PXL_TOTAL];
	for (int i = 0; i < PXL_TOTAL; i++)
	{
		array[i] = 0;
		if (i >= PXL_TOTAL - PXL_WIDTH)
		{
			array[i] = palette.size() - 1;
		}
	}
	return array;
}

void Fire::drawFireArray()
{
	for (int i = 0; i < PXL_TOTAL; i++)
	{
		sf::RectangleShape rect;
		rect.setPosition(sf::Vector2f(
				(float)(i % PXL_WIDTH) * (float)PIXEL_SIZE,
				(float((int)(i / PXL_WIDTH))) * (float)PIXEL_SIZE));
		rect.setSize(sf::Vector2f((float)PIXEL_SIZE, (float)PIXEL_SIZE));
		rect.setFillColor(palette.at(firePixels[i]));
		rect.setOutlineThickness(0);
		rect.setOutlineColor(sf::Color::Black);
		window->draw(rect);
	}
}

void Fire::doFire()
{
	for(uint x = 0 ; x < PXL_WIDTH; x++) {
		for (uint y = 1; y < PXL_HEIGHT ; y++) {
			uint colourIndex = firePixels[x + (y * PXL_WIDTH)];
			if(colourIndex) {
				uint rnd = Random::randi(0, 3);
				uint indexX = (x - rnd + 1) % PXL_WIDTH;
				uint indexY = y - 1;
				firePixels[indexX + (indexY * PXL_WIDTH)] = colourIndex - rnd % 2;
			}
			else {
				uint indexX = x;
				uint indexY = y - 1;
				firePixels[indexX + (indexY * PXL_WIDTH)] = 0;
			}
		}
	}
}
