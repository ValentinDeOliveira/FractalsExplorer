#include "../../Headers/Utils/Animator.h"
#include "../../Headers/Fractals/Julia.h"


Animator::Animator()
{
	if (!CreateDirectory(PATH_TO_RES.c_str(), NULL)) {
		std::cerr << "Impossible to create directory at the path : " << PATH_TO_RES << std::endl;
	}
		
	mandelbrot = new Mandelbrot();
}

void Animator::smoothZoom(float endingZoomX, float endingZoomY, float endingStepX, float endingStepY,
	float startingZoomX, float startingZoomY, float startingStepX, float startingStepY)
{
	int index = 0;
	Julia julia = Julia();
	sf::Image img;
	sf::Texture texture;
	sf::Sprite sprite;

	unsigned int iterations = (int)(startingZoomX / endingZoomX);
	float stepForXZoom = abs((startingZoomX - endingZoomX) / iterations);
	float stepForYZoom = abs((startingZoomY - endingZoomY) / iterations);

	float stepForXStep = abs(startingStepX - endingStepX) / iterations;
	float stepForYStep = abs(startingStepY - endingStepY) / iterations;

	for (unsigned int n = 0; n < iterations; n++)
	{
		img.create(Constants::WIDTH, Constants::HEIGHT);

	
		texture.loadFromImage(julia.calculateFullImage(startingZoomX, startingStepX, startingStepY));
		sprite.setTexture(texture, true);

		

		screenshotter.takeScreenshot(texture, getImagePath(index));
		
		startingZoomX += stepForXZoom;
		startingStepX += stepForXStep;
		startingStepY += stepForYStep;
		startingZoomY += stepForYZoom;

		index++;
	}
}

void Animator::smoothZoomToJulia(float endingZoom, float endingStepX, float endingStepY,
								 float startingZoom, float startingStepX, float startingStepY)
{
	int index = 0;
	Julia julia = Julia();
	sf::Image img;
	sf::Texture texture;
	sf::Sprite sprite;

	unsigned int iterations = (int)(endingZoom / startingZoom);
	float stepForZoom = abs((startingZoom - endingZoom) / iterations);
	
	float stepForXStep = abs(startingStepX - endingStepX) / iterations;
	float stepForYStep = abs(startingStepY - endingStepY) / iterations;

	for (unsigned int n = 0; n < iterations + 1; n++)
	{
		img.create(Constants::WIDTH, Constants::HEIGHT);


		texture.loadFromImage(julia.calculateFullImage(startingZoom, startingStepX, startingStepY));
		sprite.setTexture(texture, true);

		startingStepX += stepForXStep;
		startingStepY += stepForYStep;
		startingZoom += stepForZoom;

		screenshotter.takeScreenshot(texture, getImagePath(index));


		index++;
	}
}

std::string Animator::getImagePath(unsigned short index)
{
	return PATH_TO_RES + std::to_string(index) + ".png";
}