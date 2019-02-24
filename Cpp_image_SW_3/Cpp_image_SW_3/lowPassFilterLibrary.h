#pragma once
#ifndef LOWPASSFILTERLIBRARY_H
#define LOWPASSFILTERLIBRARY_H

#include "pch.h"
#include <opencv2/opencv.hpp>

// void averageBlur(cv::Mat *imgTest,const int order);
void averageBlur(cv::Mat &imgTest, const int order);

void gaussianFilter(cv::Mat &imgTest,const int order);

void medianFilter(cv::Mat &imgTest,const int order);

#endif // !LOWPASSFILTERLIBRARY_H