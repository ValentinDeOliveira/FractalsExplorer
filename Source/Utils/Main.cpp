#include "../../Headers/Utils/Manager.h"
#include "../../Headers/Utils/WindowInteractor.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(Constants::WIDTH, Constants::HEIGHT), "Fractale", sf::Style::Fullscreen);
	Manager m = Manager();
	WindowInteractor wi = WindowInteractor();

	Mandelbrot ma = Mandelbrot();

	sf::Texture texture;
	sf::Sprite sprite;

	sprite.setTexture(texture);
	texture.loadFromImage(ma.calculateFullImage());

	wi.initWindow(window, texture);
}