#include <SFML/Graphics.hpp>
// #include <Randomizer.hpp>

int main (int argv, char** args)
{
	sf::RenderWindow window (sf::VideoMode(800,600), "Stupid Effin' Window");

	sf::CircleShape circle;
	circle.setRadius (85);
	circle.setOutlineColor(sf::Color::Cyan);
	circle.setOutlineThickness(5);
	circle.setPosition(50,50);
	window.draw(circle);
	window.display();
	

	while (window.isOpen())
	{
		sf::Event event;
	
		if (window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
			}
		}
	}
	
	window.clear();

	return 0;
}