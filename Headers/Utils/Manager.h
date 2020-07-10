#include <SFML\Window\Window.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

#include "../Fractals/Mandelbrot.h"
#include "../Utils/Animator.h"
#include "../Fractals/Julia.h"

#ifndef MANAGER_H
#define MANAGER_H

class Manager
{
	public:
		Mandelbrot mandelbrot = Mandelbrot();
		Animator animator = Animator();
		Screenshotter screenshotter = Screenshotter();
		Julia julia = Julia();
		
	public:
		sf::Texture DisplaySimpleMandelbrot(sf::RenderWindow& window);

		sf::Texture zoomToMandelbrotPoint(sf::RenderWindow& window, float zoomX, float stepX, float zoomY, float stepY);

		void AnimateToACoordinatePoint(float endingZoomX, float endingZoomY, float endingStepX, float endingStepY, 
									   float zoomX = 0.8, float stepX = -0.5, float zoomY = 0.8, float stepY = 0);

		void animateToJuliaCoordinatePoint(float endingZoom, float endingStepX, float endingStepY,
										   float startingZoom = 1, float startingStepX = 0, float startingStepY = 0);


		sf::Texture DisplaySimpleJulia(sf::RenderWindow& window);

		sf::Texture zoomToJuliaPoint(sf::RenderWindow& window, float zoom, float stepX, float stepY);

		void compareColors();
};

#endif
