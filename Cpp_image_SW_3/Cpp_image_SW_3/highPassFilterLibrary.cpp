#include "pch.h"
#include "highPassFilterLibrary.h"
#include <opencv2/opencv.hpp>
#include <iostream>

// apply dérivative x filter with a Prewitt kernel
// the size of the kernel is order
void prewitt_x_Filter(cv::Mat imgTest, cv::Mat prewitt_x_output, int order)
{
	// normalized prewitt x kenel
	float prewitt_x_kernel[3][3] = { {-1,0,1},
									{-1,0,1},
									{-1,0,1} };
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}


// apply dérivative y filter with a Prewitt kernel
// the size of the kernel is order
void prewitt_y_Filter(cv::Mat imgTest, cv::Mat prewitt_y_output, int order)
{
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

void norm2_of_gradient(cv::Mat img_d_X, cv::Mat img_d_Y, cv::Mat norm2_output)
{
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

void nomr2_of_prewitt(cv::Mat imgTest, int order)
{
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

void sobel_x_Filter(cv::Mat imgTest, cv::Mat sobel_x_output, int order)
{
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

void sobel_y_Filter(cv::Mat imgTest, cv::Mat sobel_y_output, int order)
{
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

void norm2_of_sobel(cv::Mat imgTest, int order)
{
	try {

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

