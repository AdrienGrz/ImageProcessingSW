#ifndef TESTFILTER_H
#define TESTFILTER_H

#pragma once
#include "pch.h"
#include <opencv2/opencv.hpp>
#include <string>
#include "highPassFilterLibrary.h"
#include "lowPassFilterLibrary.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace cv;

class testFilter
{
public:
	testFilter(string path, string img_file_name,string filter, int order);
	~testFilter();
	void processTestFilter();
	// getters
	//string get_input_path();

	// setters
	void set_img_input(string path);
	void set_filter_index(unsigned int index);
	void set_kernel_size(int order);
	//void set_input_path();
	//void set_output_path();


private:
	//string input_path;
	//string output_path;
	int kernel_size;
	Mat img_input;
	vector<string> filter_lists;
	unsigned int filter_index;
};

#endif // !TESTFILTER_H



