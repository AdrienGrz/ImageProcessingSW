#pragma once
#ifndef HIGHPASSFILTERLIBRARY_H
#define HIGHPASSFILTERLIBRARY_H

#include <opencv2/opencv.hpp>

void prewitt_x_Filter(cv::Mat imgTest, cv::Mat prewitt_x_output, int order);

void prewitt_y_Filter(cv::Mat imgTest, cv::Mat prewitt_y_output,int order);

void norm2_of_gradient(cv::Mat img_d_X, cv::Mat img_d_Y, cv::Mat norm2_output);

void nomr2_of_prewitt(cv::Mat imgTest, int order);

void sobel_x_Filter(cv::Mat imgTest, cv::Mat sobel_x_output, int order);

void sobel_y_Filter(cv::Mat imgTest, cv::Mat sobel_y_output, int order);

void norm2_of_sobel(cv::Mat imgTest, int order);

#endif // !HIGHPASSFILTERLIBRAR_H