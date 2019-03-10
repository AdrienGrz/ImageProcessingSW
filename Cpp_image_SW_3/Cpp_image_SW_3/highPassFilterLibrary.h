#pragma once
#ifndef HIGHPASSFILTERLIBRARY_H
#define HIGHPASSFILTERLIBRARY_H

#include <opencv2/opencv.hpp>

using namespace cv;

Mat prewitt_x_Filter(cv::Mat imgTest);

Mat prewitt_y_Filter(cv::Mat imgTest);

Mat sobel_x_Filter(cv::Mat imgTest);

Mat sobel_y_Filter(cv::Mat imgTest);

Mat norm2_of_gradient(cv::Mat img_d_X, cv::Mat img_d_Y);


Mat norm2_of_prewitt(cv::Mat imgTest);

Mat norm2_of_sobel(cv::Mat imgTest);


#endif // !HIGHPASSFILTERLIBRAR_H