#include "pch.h"
#include "lowPassFilterLibrary.h"
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <iostream>

using namespace cv;
using namespace std;

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
	catch (const exception& e) {
		cout << e.what();
	}
}


// Apply an gaussian blur to the image as a low pass filter
// with a kernel of size (order, order)
void gaussianFilter(cv::Mat imgTest, int order)
{
	static int ordersList[10] = { 3,5,7,9,11,13,15,17,19,21 };
	Mat imgOutput;

	try {
		//if (std::find(std::begin(ordersList), std::end(ordersList), order) != std::end(ordersList)) {
		GaussianBlur(imgTest, imgOutput, Size(order, order), 0.0, 0.0); // sigmaX = sigmaY = default with size of kernel
		imgTest = imgOutput;
		//}
	}
	catch (const exception& e) {
		cout << e.what();
	}
}

// apply the non-linear median filter on the image
// with the kernel size order
void medianFilter(cv::Mat imgTest, int order)
{
	try{
		medianBlur(imgTest, imgTest, order);
	}
	catch (const exception& e) {
		cout << e.what();
	}
}



;
