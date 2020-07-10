#include <SFML\Graphics\Image.hpp>
#include "../Utils/Colorizer.h"
#include "../Utils/Constants.h"

#ifndef MANDELBROT_H
#define MANDELBROT_H

class Mandelbrot
{
	private:
		static float constexpr SCREEN_RATIO = (float)Constants::WIDTH / (float)Constants::HEIGHT;
		Colorizer *colors;

	public:
		Mandelbrot();

		sf::Image calculateFullImage(float zoomX = 0.8, float stepX = -0.5, float zoomY = 0.8, float stepY = 0);

		sf::Image calculateFullImageForColorComparison(int colorOrder = 0, float zoomX = 0.8, float stepX = -0.5, float zoomY = 0.8, float stepY = 0);

	private:
		int calculateIterationsZoom(float x, float y, float zoomX, float stepX, float zoomY, float stepY);
};

#endif