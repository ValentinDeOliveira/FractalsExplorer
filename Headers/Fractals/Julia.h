#include <SFML\Graphics\Image.hpp>
#include "../Utils/Colorizer.h"
#include "../Utils/Constants.h"

#pragma once
class Julia
{
	private:
		Colorizer* colors;

		float const c_x = 0.285;
		float const c_y = 0.01;

		//Other points of Julia set
		/*
		float const c_x = -0.7;
		float const c_y = 0.27015;
			
		float const c_x = -0.835;
		float const c_y = -0.2321;

		float const c_x = -0.8;
		float const c_y = 0.156;

		float const c_x = -0.4;
		float const c_y = 0.6;

		float const c_x = -1;
		float const c_y = 0;

		float const c_x = 0.3;
		float const c_y = 0.6;

		float const c_x = 0.355;
		float const c_y = 0.355;

		float const c_x = 0.355534;
		float const c_y = 0.337292;
		*/


	public:
		Julia();

		sf::Image calculateFullImage(float zoom = 0.9, float stepX = 0, float stepY = 0);

		sf::Image calculateFullImageForColorComparison(int colorOrder = 0, float zoom = 0.9, float stepX = 0, float stepY = 0);

	private:
		int calculateIterations(float x, float y, float zoom, float stepX, float stepY);
};

