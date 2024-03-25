#include "RGB/png.h"
#include "RGB/rgbapixel.h"

#include <string>
#include <cmath>
#include <complex>

void rotate(std::string inputFile, std::string outputFile)
{
	// Load the input image
	PNG pic(inputFile);
	unsigned int width = pic.width();
	unsigned int height = pic.height();

	PNG rotated(width, height);
	// Rotating
	// x = (width - 1 - x)
	// y = (height - 1 - y)
	for (unsigned int x = 0; x < width; x++)
	{
		for (unsigned int y = 0; y < height; y++)
		{

			// Calculate the new position for the current pixel
			unsigned int newX = width - 1 - x;
			unsigned int newY = height - 1 - y;

			RGBAPixel *takeOriginalPixel = pic(x, y);
			RGBAPixel *inputPixelToRotatedPic = rotated(newX, newY);

			// Copy the pixel data
			*inputPixelToRotatedPic = *takeOriginalPixel;
		}
	}
	// Save the rotated image
	rotated.writeToFile(outputFile);
}

PNG myArt(unsigned int width, unsigned int height)
{
	PNG png(width, height);
	// Define colors
	RGBAPixel color1(255, 0, 0);			  // Red
	RGBAPixel color2(0, 255, 0);			  // Green
	RGBAPixel color3(0, 0, 255);			  // Blue
	RGBAPixel backgroundColor(255, 255, 255); // White

	// Center of the image
	int centerX = width / 2;
	int centerY = height / 2;
	int maxRadius = std::min(width, height) / 2; // Maximum radius

	// Drawing concentric circles
	for (unsigned int x = 0; x < width; x++)
	{
		for (unsigned int y = 0; y < height; y++)
		{
			// Calculate the distance from the center
			int distance = std::sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));

			// Determine which circle the point is in
			if (distance < maxRadius)
			{
				int circleWidth = maxRadius / 10; // width of each concentric circle band
				int whichCircle = distance / circleWidth;

				if (whichCircle % 3 == 0)
				{
					*png(x, y) = color1;
				}
				else if (whichCircle % 3 == 1)
				{
					*png(x, y) = color2;
				}
				else
				{
					*png(x, y) = color3;
				}
			}
			else
			{
				*png(x, y) = backgroundColor; // Set background color
			}
		}
	}
	return png;
}
