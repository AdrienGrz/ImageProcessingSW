#include "pch.h"
#include "lowPassFilterLibrary.h"
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <iostream>

using namespace cv;

// Apply an averaging to the image as a low pass filter
// with a kernel of size (order, order)
void averageBlur(Mat imgTest, int order)
{
	static int ordersList[10] = {3,5,7,9,11,13,15,17,19,21};
	Mat imgOutput;

	try {
		//if (std::find(std::begin(ordersList), std::end(ordersList), order) != std::end(ordersList)) {
		blur(imgTest, imgOutput, Size(order, order));
		imgTest = imgOutput;
		//}
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}
};
