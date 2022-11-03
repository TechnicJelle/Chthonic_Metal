#include <SFML/Graphics.hpp>
#include <iostream>

#include "Engine/Game.hpp"
#include "Scenes/MainMenu.hpp"

int main(int argc, char** argv)
{
	// Default Settings
	int width = 1920;
	int height = 1080;
	bool vsync = true;

	// Parse Arguments for Settings
	if(argc > 1) {
		if (argc > 2) {
			width = std::stoi(argv[1]);
			height = std::stoi(argv[2]);
		}
		if (argc > 3) {
			vsync = std::stoi(argv[3]);
		}
	}

	// Create Game with Settings
	sf::RenderWindow* window;
	Engine::Game game = Engine::Game(width, height, "Chthonic Metal - v0.0.1", vsync, &window);

	// Create Scenes

	// >Main Menu
	MainMenu mainMenu = MainMenu(window);
	game.addScene(&mainMenu);

	// >Character Selection Screen

	// >Fight Screen

	// Start at Main Menu
	game.setActiveScene(&mainMenu);
	mainMenu.setup();

	// Run Game
	game.run();

	return 0;
}