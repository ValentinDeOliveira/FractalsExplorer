#include "../../Headers/Utils/Colorizer.h"
#include "../../Headers/Fractals/Mandelbrot.h"
#include <iostream>
#include <algorithm>


//thx to https://solarianprogrammer.com/2013/02/28/mandelbrot-set-cpp-11/
sf::Color Colorizer::getColorForMandelbrotIteration(int iteration)
{
	if (iteration >= Constants::MAX_ITER)
		return FRACTAL_COLOR;

	//Avoid the black circle around the fractal
	if (iteration <= 1)
		iteration++;

	double t = ((double)log(iteration) / LOG_MAX_ITER);
	
	int r = (int)(9*(1-t)*t*t*t*255);
 	int g = (int)(15*(1-t)*(1-t)*t*t*255);
 	int b =  (int)(8.5*(1-t)*(1-t)*(1-t)*t*255);

	return sf::Color(g, r, b);
}

sf::Color Colorizer::getColorForJuliaIteration(int iteration)
{
	//Avoid the black circle around the fractal
	if (iteration <= 1)	
		iteration++;

	double t = (double)log(iteration) / LOG_MAX_ITER;


	int r = (int)(9 * (1 - t) * t * t * t * 255);
	int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

	
	
	return sf::Color(b, g, r);
}

sf::Color Colorizer::getColorForComparison(int iteration, int colorOrder)
{
	if (iteration == 1)
		iteration++;

	double t = (double)log(iteration) / LOG_MAX_ITER;

	int r = (int)(9 * (1 - t) * t * t * t * 255);
	int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	
	
	sf::Color color;
	
	switch (colorOrder % 3)
	{
		case 0:
			color.b = b;
			break;
		case 1:
			color.b = g;
			break;
		case 2:
			color.b = r;
			break;
	}

	switch ((colorOrder / 3) % 3)
	{
		case 0:
			color.g = b;
			break;
		case 1:
			color.g = g;
			break;
		case 2:
			color.g = r;
			break;
	}

	switch ((colorOrder / 9) % 3)
	{
		case 0:
			color.r = b;
			break;
		case 1:
			color.r = g;
			break;
		case 2:
			color.r = r;
			break;
	}

	return color;
}

std::string Colorizer::getColorNameForIndex(int index)
{
	std::string name = "";

	switch ((index / 9) % 3)
	{
	case 0:
		name += "b";
		break;
	case 1:
		name += "g";
		break;
	case 2:
		name += "r";
		break;
	}


	switch ((index / 3) % 3)
	{
	case 0:
		name += "b";
		break;
	case 1:
		name += "g";
		break;
	case 2:
		name += "r";
		break;
	}

	switch (index % 3)
	{
		case 0:
			name += "b";
			break;
		case 1:
			name += "g";
			break;
		case 2:
			name += "r";
			break;
	}

	return name;
}

