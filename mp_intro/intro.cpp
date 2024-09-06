#include "RGB/png.h"
#include "RGB/rgbapixel.h"

#include <string>
#include <cmath>

void rotate(std::string inputFile, std::string outputFile) {
	PNG pic(inputFile);
	// Your code here
	int width = pic.width();
	int height = pic.height();
	int height_limit = height / 2;

	for (int y = 0; y < height_limit; y++)
	{
		for (int x = 0; x < width; x++)
		{
			// Change the pixel positions
			RGBAPixel *top = pic(x, y);
			RGBAPixel *bottom = pic(width - x - 1, height - y - 1);

			// Swap pixel values
			RGBAPixel temp = *top;
            *top = *bottom;
            *bottom = temp;
		}
	}

	pic.writeToFile(outputFile);
}

PNG myArt(unsigned int width, unsigned int height) {
	PNG png(width, height);
	// Your code here
	int width_int = width;
	int height_int = height;

	for (int y = 0; y < height_int; y++){
		for (int x = 0; x < width_int; x++){
			RGBAPixel *currPixel = png(x,y);

			// Calculate the color values based on the position
            int red = static_cast<int>((x / static_cast<double>(width)) * 255);
            int green = static_cast<int>((y / static_cast<double>(height)) * 255);
            int blue = 255;

            // Set the color of the pixel
            currPixel->red = red;
            currPixel->green = green;
            currPixel->blue = blue;

		}
	}
	return png;
}
