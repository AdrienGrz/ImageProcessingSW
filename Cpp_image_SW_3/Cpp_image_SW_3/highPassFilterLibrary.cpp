#include "pch.h"
#include "highPassFilterLibrary.h"
#include <opencv2/opencv.hpp>
#include <iostream>


// apply derivative x filter with a Prewitt kernel
// the size of the kernel is order
Mat prewitt_x_Filter(cv::Mat imgTest)
{
	// normalized prewitt x kenel
	const static cv::Mat kernel_prewitt_x = (cv::Mat_<double>(3, 3,CV_32F) << -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f);
	try {
		cv::Mat prewitt_x_output;
		cv::filter2D(imgTest, prewitt_x_output, CV_32F, kernel_prewitt_x, Point(-1,-1),BORDER_REPLICATE);
		return prewitt_x_output;
	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}	
}

/*

Mat prewitt_y_Filter(cv::Mat imgTest)
{
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

Mat norm2_of_gradient(cv::Mat img_d_X, cv::Mat img_d_Y, cv::Mat norm2_output)
{
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

Mat nomr2_of_prewitt(cv::Mat imgTest)
{
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

Mat sobel_x_Filter(cv::Mat imgTest)
{
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

Mat sobel_y_Filter(cv::Mat imgTest)
{
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

Mat norm2_of_sobel(cv::Mat imgTest)
{
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

*/