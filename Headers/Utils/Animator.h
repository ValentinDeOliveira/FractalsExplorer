#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include <windows.h>

#include "../Utils/Screenshotter.h"
#include "../Fractals/Mandelbrot.h"

#ifndef ANIMATOR_H
#define ANIMATOR_H

class Animator
{
	private:
		std::string const PATH_TO_RES = "../Results/";

		Mandelbrot *mandelbrot;
		Screenshotter screenshotter;
	
	public:
		Animator();
		
		void smoothZoom(float endingZoomX, float endingZoomY, float endingStepX, float endingStepY, float startingZoomX = 0.0021, 
						float startingZoomY = 0.0021, float startingStepX = 0.7, float startingStepY = 0);

		void smoothZoomToJulia(float endingZoom, float endingStepX, float endingStepY,
							   float startingZoom = 1, float startingStepX = 0, float startingStepY = 0);

	private :
		std::string getImagePath(unsigned short index);
};

#endif