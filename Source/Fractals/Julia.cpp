#include "../../Headers/Fractals/Julia.h"
#include <iostream>

Julia::Julia()
{
	colors = new Colorizer();
}

sf::Image Julia::calculateFullImage(float zoom, float stepX, float stepY)
{
	sf::Image img;
	img.create(Constants::WIDTH, Constants::HEIGHT);

	for (int x = 0; x < Constants::WIDTH; x++)
	{
		for (int y = 0; y < Constants::HEIGHT; y++)
		{
			img.setPixel(x, y, colors->getColorForJuliaIteration(Julia::calculateIterations(x, y, zoom, stepX, stepY)));
		}
	}
	return img;
}

sf::Image Julia::calculateFullImageForColorComparison(int colorOrder, float zoom, float stepX, float stepY)
{
	sf::Image img;
	img.create(Constants::WIDTH, Constants::HEIGHT);

	for (int x = 0; x < Constants::WIDTH; x++)
	{
		for (int y = 0; y < Constants::HEIGHT; y++)
		{
			img.setPixel(x, y, colors->getColorForComparison(Julia::calculateIterations(x, y, zoom, stepX, stepY), colorOrder));
		}
	}
	return img;
}

int Julia::calculateIterations(float x, float y, float zoom, float stepX, float stepY)
{
	float z_x = 1.5 * ((float)x - Constants::HALF_WIDTH) / (zoom * Constants::HALF_WIDTH) + stepX;
	float z_y = 1.0 * ((float)y - Constants::HALF_HEIGHT) / (zoom * Constants::HALF_HEIGHT) + stepY;



	int index = 0;

	while ((z_x * z_x) + (z_y * z_y) < 4 && index <= Constants::MAX_ITER) {
		auto tmp = z_x;

		z_x = z_x * z_x - z_y * z_y + c_x;
		z_y = 2 * z_y * tmp + c_y;
		index++;
	}
	return index;
}
