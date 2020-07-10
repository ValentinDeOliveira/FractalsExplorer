#include <SFML\Graphics\Color.hpp>
#include <string>
#include "Constants.h"

#ifndef COLORIZER_H
#define COLORIZER_H

class Colorizer
{
	private:		
		sf::Color const FRACTAL_COLOR = sf::Color::Black;
		const double LOG_MAX_ITER = (double)log(Constants::MAX_ITER);

	public:
		sf::Color getColorForMandelbrotIteration(int iteration);

		sf::Color getColorForJuliaIteration(int iteration);

		sf::Color getColorForComparison(int iteration, int colorOrder);

		std::string getColorNameForIndex(int index);
};

#endif