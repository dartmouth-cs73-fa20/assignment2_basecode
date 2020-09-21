#include "a2.h"
#include <cmath>

using namespace std;


// This is a way for you to test your functions.
// We will only grade the contents of a2.cpp
int main()
{
	FloatImage wheat(DATA_DIR "/input/a2/wheat.png");

	FloatImage linear_wheat = changeGamma(wheat, 1.f/2.2f, 1.f);
	linear_wheat.write(DATA_DIR "/output/linear_wheat.png");

	FloatImage brighter_wheat = exposure(wheat, 1.25f);
	brighter_wheat.write(DATA_DIR "/output/brighter_wheat.png");

	FloatImage grey_wheat = color2gray(wheat);
	grey_wheat.write(DATA_DIR "/output/grey_wheat.png");

	vector<FloatImage> lc_wheat = lumiChromi(wheat);
	if (lc_wheat.size() == 2)
	{
		lc_wheat[0].write(DATA_DIR "/output/wheat_lumi.png");
		lc_wheat[1].write(DATA_DIR "/output/wheat_chromi.png");
	}

	FloatImage brighter_contrastier_wheat = brightnessContrastLumi(wheat, 1.5, 2.0f);
	brighter_contrastier_wheat.write(DATA_DIR "/output/brighter_contrastier_wheat.png");

	FloatImage yuv_wheat = rgb2yuv(wheat);
	FloatImage rgb_wheat = yuv2rgb(yuv_wheat);

	FloatImage wheat_difference = (rgb_wheat - wheat) * 100.0f;
	for(int i = 0; i < wheat_difference.size(); ++i)
        wheat_difference(i) = fabs(wheat_difference(i));
	wheat_difference.write(DATA_DIR "/output/wheat_difference.png");

	vector<FloatImage> spanish_wheat = spanish(wheat);
	if (spanish_wheat.size() == 2)
	{
		spanish_wheat[0].write(DATA_DIR "/output/spanish_wheat_chromi.png");
		spanish_wheat[1].write(DATA_DIR "/output/spanish_wheat_lumi.png");
	}

	FloatImage grayworld_flower = grayworld(FloatImage(DATA_DIR "/input/a2/flower.png"));
	grayworld_flower.write(DATA_DIR "/output/grayworld_flower.png");

	FloatImage wheat_histogram = visualizeRGBHistogram(Histogram(wheat, 0), Histogram(wheat, 1), Histogram(wheat, 2));
	wheat_histogram.write(DATA_DIR "/output/wheat_histogram.png");
}
