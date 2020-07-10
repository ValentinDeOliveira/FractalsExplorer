#include <SFML\Graphics\Texture.hpp>

#include <string>
#include <iostream>  

#ifndef SCREENSHOTTER_H
#define SCREENSHOTTER_H

class Screenshotter
{	
	public:
		void takeScreenshot(const sf::Texture s, const std::string& filename);

};

#endif