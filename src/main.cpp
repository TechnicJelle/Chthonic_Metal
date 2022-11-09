#include <SFML/Graphics.hpp>

#include "Engine/Game.hpp"
#include "Scenes/MainMenu.hpp"
#include "Scenes/CharacterSelection.hpp"
#include "Scenes/Fight.hpp"

int main(int argc, char** argv)
{
	// Default Settings
	int width = 1920;
	int height = 1080;
	bool vsync = true;

	// Parse Arguments for Settings
	if (argc > 1) {
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
	MainMenu mainMenu = MainMenu(&game, window);
	game.addScene(&mainMenu, Utils::SceneName::MAIN_MENU);

	// >Character Selection Screen
	CharacterSelection characterSelectionScreen = CharacterSelection(&game, window);
	game.addScene(&characterSelectionScreen, Utils::SceneName::CHARACTER_SELECTION);

	// >Fight Screen
	Fight fightScreen = Fight(&game, window);
	game.addScene(&fightScreen, Utils::SceneName::FIGHT);

	// Start at Main Menu
	game.setActiveScene(Utils::SceneName::MAIN_MENU);

	// Run Game
	game.run();

	return 0;
}