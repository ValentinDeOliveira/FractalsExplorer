#include "../../Headers/Utils/WindowInteractor.h"

void WindowInteractor::initWindow(sf::RenderWindow &window, sf::Texture texture)
{
	sf::Sprite sprite;
	sprite.setTexture(texture);
	drawSprite(window, sprite);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::F11:
					if (isFullScreen) {
						window.create(sf::VideoMode(Constants::WIDTH, Constants::HEIGHT), "Fractale", sf::Style::Default);
						drawSprite(window, sprite);
					}
					else {
						window.create(sf::VideoMode(Constants::WIDTH, Constants::HEIGHT), "Fractale", sf::Style::Fullscreen);
						drawSprite(window, sprite);
					}
				}
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

	}
}

void WindowInteractor::drawSprite(sf::RenderWindow& window, sf::Sprite sprite)
{
	invertIsFullScreen();

	window.clear();
	window.draw(sprite);
	window.display();
}

void WindowInteractor::invertIsFullScreen()
{
	if (isFullScreen) isFullScreen = false;
	else isFullScreen = true;
}
