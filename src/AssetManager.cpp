//
// Created by technicjelle on 08/11/22.
//

#include "AssetManager.hpp"

AssetManager::AssetManager()
{
	if (!fontAnotherDanger.loadFromFile("assets/fonts/Another Danger/Another Danger - Demo.otf")) throw std::runtime_error("Could not load fontAnotherDanger");
	if (!fontTeko.loadFromFile("assets/fonts/Teko/Teko-Medium.ttf")) throw std::runtime_error("Could not load fontTeko");

	if (!txBackground.loadFromFile("assets/background.png")) throw std::runtime_error("Could not load txBackground");

	if (!txPookman_Chorizo.loadFromFile("assets/pookmans/chorizo.png")) throw std::runtime_error("Could not load txPookman_Chorizo");
	if (!txPookman_Pukechoo.loadFromFile("assets/pookmans/pukechoo.png")) throw std::runtime_error("Could not load txPookman_Pukechoo");
	if (!txPookman_Scoot.loadFromFile("assets/pookmans/scoot.png")) throw std::runtime_error("Could not load txPookman_Scoot");

	if (!txMaterialIcon_DeleteSweep.loadFromFile("assets/material-icons/delete-sweep-outline-black.png")) throw std::runtime_error("Could not load txMaterialIcon_DeleteSweep");
}
