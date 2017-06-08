#include <SFML/Graphics.hpp>
#include <Windows.h>

#define SECONDS_PER_FRAME 16
#define MAX_FRAMES_PER_ANIMATION 10

/**
* @brief This takes in input from the player
* @return NULL
*/
void Input()
{

}

/**
* @brief This updates the world each frame.
* @return NULL
*/
void Update()
{

}

/**
* @brief This actually makes all the pretty colors appear on the screen.
* @return NULL
*/
void Draw()
{

}


struct Animation
{
	int count;
	sf::IntRect frames[MAX_FRAMES_PER_ANIMATION];
	int times[MAX_FRAMES_PER_ANIMATION];
};

int main(int argc, char **args)
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Week 2 Project");
	sf::Clock clock;
	sf::Texture texture;
	sf::IntRect rectSource(0, 0, 100, 100);
	Animation animation;
	animation.count = 3;
	texture.loadFromFile("secondproject/sheet_hero_idle", rectSource);
	sf::Sprite sprite(texture);

	int x = 0;
	int y = 0;

	while (window.isOpen())
	{
		sf::Event event;
		int frame = 0;
		int frameTimer = 200;
		x = (x + 1) % 200;
		y = (y + 1) % 200;
		rectSource.left = x;
		rectSource.top = y;
		sprite.setTextureRect(animation.frames[frame]);
		sprite.setPosition(sf::Vector2f(x, y));

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::F)
				{
					printf("F was pressed, also, this is dumb.");
				}
				break;
			}
		}
		window.clear();
		window.draw(sprite);
		window.display();
		if (clock.getElapsedTime().asMilliseconds() < SECONDS_PER_FRAME)
		{
			sf::sleep(sf::milliseconds(SECONDS_PER_FRAME - clock.getElapsedTime().asMilliseconds()));
		}
		frameTimer -= clock.getElapsedTime().asMilliseconds();

		if (frameTimer <= 0)
			frame = (frame + 1) % 3;
		clock.restart();
	}
	return 0;
}
