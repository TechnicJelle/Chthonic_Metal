//
// Created by technicjelle on 08/11/22.
//

#ifndef CHTHONIC_METAL_ASSETMANAGER_HPP
#define CHTHONIC_METAL_ASSETMANAGER_HPP

#include <SFML/Graphics/Font.hpp>

#define Asset AssetManager::getInstance()

class AssetManager
{
public:
	sf::Font fontAnotherDanger;
	sf::Font fontTeko;

	sf::Texture txBackground;

	sf::Texture txPookman_Chorizo;
	sf::Texture txPookman_Pukechoo;
	sf::Texture txPookman_Scoot;

	sf::Texture txMaterialIcon_DeleteSweep;

	AssetManager();

	// Singleton pattern
	static AssetManager& getInstance()
	{
		static AssetManager instance;
		return instance;
	}
};


#endif //CHTHONIC_METAL_ASSETMANAGER_HPP
