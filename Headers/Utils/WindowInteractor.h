#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <SFML\Window\Event.hpp>

#include "../Fractals/Mandelbrot.h"

#ifndef WINDOWINTERACTOR_H
#define WINDOWINTERACTOR_H

class WindowInteractor
{
	private:
		bool isFullScreen = true;

	public:
		void initWindow(sf::RenderWindow &window, sf::Texture texture);

	private:
		void drawSprite(sf::RenderWindow& window, sf::Sprite sprite);

		void invertIsFullScreen();
};

#endif