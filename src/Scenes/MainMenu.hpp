//
// Created by technicjelle on 30/10/22.
//

#ifndef CHTHONIC_METAL_MAINMENU_HPP
#define CHTHONIC_METAL_MAINMENU_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "../Engine/Scene.hpp"
#include "../Engine/Button.hpp"

class MainMenu : public Engine::Scene
{
private:
	const std::string highscoresFile = "assets/highscores.cmgt"; //TODO (once highscores saving is implemented): Remove "assets/" from this string

	sf::Font titleFont;
	sf::Text titleText;
	Engine::Button* playButton;
	Engine::Button* quitButton;
	sf::RectangleShape highscoresPanel;
	sf::Text highscoresHeaderText;
	sf::Font highscoresFont;
	sf::Text highscoresText;

public:
	explicit MainMenu(sf::RenderWindow* window);

	void onActivate() override;

	void update(float deltaTime) override;

	void loadHighscores();
};


#endif //CHTHONIC_METAL_MAINMENU_HPP
