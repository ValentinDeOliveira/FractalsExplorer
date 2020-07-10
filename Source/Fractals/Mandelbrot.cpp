#include "../../Headers/Fractals/Mandelbrot.h"
#include "../../Headers/Utils/Timer.h"

Mandelbrot::Mandelbrot()
{
	colors = new Colorizer();
}

int Mandelbrot::calculateIterationsZoom(float x, float y, float zoomX, float stepX, float zoomY, float stepY)
{
	float z_x = 0;
	float z_y = 0;
	
	float c_x = SCREEN_RATIO  * (x - Constants::HALF_WIDTH) / (zoomX * Constants::HALF_WIDTH) + (float)stepX;
	float c_y = (y - Constants::HALF_HEIGHT)/ (zoomY * Constants::HALF_HEIGHT) + stepY;

	int index = 0;

	while ((z_x * z_x) + (z_y * z_y) < 4 && index <= Constants::MAX_ITER) {
		auto tmp = z_x;

		z_x = z_x * z_x - z_y * z_y + c_x;
		z_y = 2 * z_y * tmp + c_y;
		index++;
	}
	return  index;
}


sf::Image Mandelbrot::calculateFullImage(float zoomX, float stepX, float zoomY, float stepY)
{
	sf::Image img;
	img.create(Constants::WIDTH, Constants::HEIGHT);

	Timer timer;


	timer.startTimer();
	for (int x = 0; x < Constants::WIDTH; x++)
	{
		for (int y = 0; y < Constants::HEIGHT; y++)
		{
			img.setPixel(x, y, colors->getColorForMandelbrotIteration(Mandelbrot::calculateIterationsZoom((float)x, (float)y, zoomX, stepX, zoomY, stepY)));
		}
	}
	timer.showEllapsedTime();

	return img;
}

sf::Image Mandelbrot::calculateFullImageForColorComparison(int colorOrder, float zoomX, float stepX, float zoomY, float stepY)
{
	sf::Image img;
	img.create(Constants::WIDTH, Constants::HEIGHT);

	for (int x = 0; x < Constants::WIDTH; x++)
	{
		for (int y = 0; y < Constants::HEIGHT; y++)
		{
			img.setPixel(x, y, colors->getColorForComparison(Mandelbrot::calculateIterationsZoom((float)x, (float)y, zoomX, stepX, zoomY, stepY), colorOrder));
		}
	}
	return img;
}
