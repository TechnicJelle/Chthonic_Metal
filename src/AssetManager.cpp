//
// Created by technicjelle on 08/11/22.
//

#include "AssetManager.hpp"
#include "Engine/Random.hpp"

AssetManager::AssetManager()
{
	if (!fontAnotherDanger.loadFromFile("assets/fonts/Another Danger/Another Danger - Demo.otf")) throw std::runtime_error("Could not load fontAnotherDanger");
	if (!fontTeko.loadFromFile("assets/fonts/Teko/Teko-Medium.ttf")) throw std::runtime_error("Could not load fontTeko");
	if (!fontReggaeOne.loadFromFile("assets/fonts/Reggae One/ReggaeOne-Regular.ttf")) throw std::runtime_error("Could not load fontReggaeOne");

	if (!txBackground.loadFromFile("assets/background.png")) throw std::runtime_error("Could not load txBackground");

	if (!txPookman_Chorizo.loadFromFile("assets/pookmans/chorizo.png")) throw std::runtime_error("Could not load txPookman_Chorizo");
	printf("txPookman_Chorizo location: %p\n", &txPookman_Chorizo);
	if (!txPookman_Pukechoo.loadFromFile("assets/pookmans/pukechoo.png")) throw std::runtime_error("Could not load txPookman_Pukechoo");
	printf("txPookman_Pukechoo location: %p\n", &txPookman_Pukechoo);
	if (!txPookman_Scoot.loadFromFile("assets/pookmans/scoot.png")) throw std::runtime_error("Could not load txPookman_Scoot");
	printf("txPookman_Scoot location: %p\n", &txPookman_Scoot);

	if (!txMaterialIcon_DeleteSweep.loadFromFile("assets/material-icons/delete-sweep-outline-black.png")) throw std::runtime_error("Could not load txMaterialIcon_DeleteSweep");
}

sf::Texture &AssetManager::getRandomPookmanTexture()
{
	int random = Random::randi(3);
	switch (random)
	{
		case 0:
			return txPookman_Chorizo;
		case 1:
			return txPookman_Pukechoo;
		case 2:
			return txPookman_Scoot;
		default:
			throw std::runtime_error("Could not get random pookman texture");
	}
}
