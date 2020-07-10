#include "../../Headers/Utils/Manager.h"

sf::Texture Manager::DisplaySimpleMandelbrot(sf::RenderWindow &window)
{
	sf::Texture texture;
	sf::Sprite sprite;

	sprite.setTexture(texture);
	texture.loadFromImage(mandelbrot.calculateFullImage());

	return texture;
}

void Manager::AnimateToACoordinatePoint(float endingZoomX, float endingZoomY, float endingStepX, 
	float endingStepY, float startingZoomX, float startingZoomY, float startingStepX, float startingStepY)
{
	animator.smoothZoom(endingZoomX, endingZoomY, endingStepX, endingStepY, startingZoomX, startingZoomY, startingStepX, startingStepY);
}

void Manager::animateToJuliaCoordinatePoint(float endingZoom, float endingStepX, float endingStepY, float startingZoom, float startingStepX, float startingStepY)
{
	animator.smoothZoomToJulia(endingZoom, endingStepX, endingStepY, startingZoom, startingStepX, startingStepY);
}

sf::Texture Manager::DisplaySimpleJulia(sf::RenderWindow& window)
{
	sf::Texture texture;
	sf::Sprite sprite;

	sprite.setTexture(texture);
	texture.loadFromImage(julia.calculateFullImage());

	return texture;
}

sf::Texture Manager::zoomToMandelbrotPoint(sf::RenderWindow& window, float zoomX, float stepX, float zoomY, float stepY)
{
	sf::Texture texture;
	sf::Sprite sprite;

	texture.loadFromImage(mandelbrot.calculateFullImage(zoomX, stepX, zoomY, stepY));
	sprite.setTexture(texture);

	return texture;
}

sf::Texture Manager::zoomToJuliaPoint(sf::RenderWindow& window, float zoom, float stepX, float stepY)
{
	sf::Texture texture;
	sf::Sprite sprite;

	texture.loadFromImage(julia.calculateFullImage(zoom, stepX, stepY));
	sprite.setTexture(texture);

	return texture;
}

void Manager::compareColors()
{
	Screenshotter s;
	Colorizer c;

	CreateDirectory("../ColorsComparison", NULL);
	CreateDirectory("../ColorsComparison/Julia", NULL);
	CreateDirectory("../ColorsComparison/Mandelbrot", NULL);

	// (r,g,b) : 3^3 possible combination
	for (int i = 0; i != 27; i++) {
		sf::Texture texture;

		texture.loadFromImage(julia.calculateFullImageForColorComparison(i));

		
		std::string path = "../ColorsComparison/Julia/1/"  + c.getColorNameForIndex(i) + ".png";

		s.takeScreenshot(texture, path);
	}
}
