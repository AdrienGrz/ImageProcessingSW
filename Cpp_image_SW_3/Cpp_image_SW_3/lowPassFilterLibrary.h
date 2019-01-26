#pragma once
#include "pch.h"
#include <opencv2/opencv.hpp>

void averageBlur(cv::Mat imgTest, int order);

void gaussianFilter(cv::Mat imgTest, int order);

void medianFilter(cv::Mat imgTest, int order);