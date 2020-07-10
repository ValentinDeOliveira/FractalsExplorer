#include "Headers/Utils/Manager.h"
#include "Headers/Utils/WindowInteractor.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(Constants::WIDTH, Constants::HEIGHT), "Fractale", sf::Style::Fullscreen);
	Manager m = Manager();
	WindowInteractor wi = WindowInteractor();

	
	sf::Texture texture = m.DisplaySimpleMandelbrot(window);
	

	//m.compareColors();
	wi.initWindow(window, texture);
	//wi.initWindow(window, m.zoomToMandelbrotPoint(window, 10, 0, 10, 0));

}