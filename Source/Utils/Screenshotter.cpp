#include "../../Headers/Utils/Screenshotter.h"
  

void Screenshotter::takeScreenshot(sf::Texture texture, const std::string& filename)
{
	if (texture.copyToImage().saveToFile(filename))
	{
		std::cout << "screenshot saved to " << filename << std::endl;
	}
}

