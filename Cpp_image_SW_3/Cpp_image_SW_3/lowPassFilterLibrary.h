#pragma once
#ifndef LOWPASSFILTERLIBRARY_H
#define LOWPASSFILTERLIBRARY_H

#include "pch.h"
#include <opencv2/opencv.hpp>

void averageBlur(cv::Mat imgTest, int order);

void gaussianFilter(cv::Mat imgTest, int order);

void medianFilter(cv::Mat imgTest, int order);

#endif // !LOWPASSFILTERLIBRARY_H