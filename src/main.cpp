#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Chthonic Metal - v0.0.1");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Texture texture;
	if (!texture.loadFromFile("assets/vase.png"))
		return 1;

	sf::Sprite sprite = sf::Sprite(texture);
	sprite.setPosition(200, 150);

	while (window.isOpen())
	{
		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(shape);
		window.draw(sprite);

		window.display();
	}

	return 0;
}