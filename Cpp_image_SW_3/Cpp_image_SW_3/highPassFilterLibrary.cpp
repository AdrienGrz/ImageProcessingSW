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



Mat prewitt_y_Filter(cv::Mat imgTest)
{
	// normalized prewitt y kenel
	const static cv::Mat kernel_prewitt_y = (cv::Mat_<double>(3, 3, CV_32F) << -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);

	try {
		cv::Mat prewitt_y_output;
		cv::filter2D(imgTest, prewitt_y_output, CV_32F, kernel_prewitt_y, Point(-1, -1), BORDER_REPLICATE);
		return prewitt_y_output;
	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}



Mat sobel_x_Filter(cv::Mat imgTest)
{
	// normalized prewitt x kenel
	const static cv::Mat kernel_sobel_x = (cv::Mat_<double>(3, 3, CV_32F) << -1.0f, 0.0f, 1.0f, -2.0f, 0.0f, 2.0f, -1.0f, 0.0f, 1.0f);
	try {
		cv::Mat sobel_x_output;
		cv::filter2D(imgTest, sobel_x_output, CV_32F, kernel_sobel_x, Point(-1, -1), BORDER_REPLICATE);
		return sobel_x_output;
	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

Mat sobel_y_Filter(cv::Mat imgTest)
{
	// normalized prewitt y kenel
	const static cv::Mat kernel_sobel_y = (cv::Mat_<double>(3, 3, CV_32F) << -1.0f, -2.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 2.0f, 1.0f);

	try {
		cv::Mat sobel_y_output;
		cv::filter2D(imgTest, sobel_y_output, CV_32F, kernel_sobel_y, Point(-1, -1), BORDER_REPLICATE);
		return sobel_y_output;
	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}


Mat norm2_of_gradient(cv::Mat img_d_X, cv::Mat img_d_Y)
{
	cv::Mat norm2_output = img_d_X.clone();
	cv::Mat Gx2 = img_d_X.clone(); // Gx2 = img_d_X^2
	cv::Mat Gy2 = img_d_X.clone(); // Gy2 = img_d_Y^2

	//int height = img_d_X.rows;
	//int width = img_d_X.cols;

	try {
		for (int i = 0; i < img_d_X.rows; i++) {
			for (int j = 0; j < img_d_X.cols; j++) {
		
				Gx2.at<float>(i, j) = img_d_X.at<float>(i, j)*img_d_X.at<float>(i, j);
				Gy2.at<float>(i, j) = img_d_Y.at<float>(i, j)*img_d_Y.at<float>(i, j);

				// euclidian norme2
				norm2_output.at<float>(i, j) = std::sqrt(Gx2.at<float>(i, j) + Gy2.at<float>(i, j));

				return norm2_output;
			}
		}

	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}


Mat norm2_of_prewitt(cv::Mat imgTest)
{
	try {
		cv::Mat prewitt_x_output;
		cv::Mat prewitt_y_output;
		cv::Mat norm2_of_prewitt_output;

		prewitt_x_output = prewitt_x_Filter(imgTest);
		prewitt_y_output = prewitt_y_Filter(imgTest);

		norm2_of_prewitt_output = norm2_of_gradient(prewitt_x_output, prewitt_y_output);

		return norm2_of_prewitt_output;
	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}

Mat norm2_of_sobel(cv::Mat imgTest)
{
	try {
		cv::Mat sobel_x_output;
		cv::Mat sobel_y_output;
		cv::Mat norm2_of_sobel_output;

		sobel_x_output = sobel_x_Filter(imgTest);
		sobel_y_output = sobel_y_Filter(imgTest);

		norm2_of_sobel_output = norm2_of_gradient(sobel_x_output, sobel_y_output);

		return norm2_of_sobel_output;
	}
	catch (const std::exception &e) {
		std::cout << e.what();
	}
}


