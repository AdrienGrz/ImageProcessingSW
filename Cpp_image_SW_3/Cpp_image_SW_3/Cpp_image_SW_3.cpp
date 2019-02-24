
#include "pch.h"
#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>
//#include <boost/filesystem.hpp>
#include <gtest/gtest.h>
#include "lowPassFilterLibrary.h"
#include "highPassFilterLibrary.h"

using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{
    cout << "Hello World!\n"; 

	/*
	// get current working directory
	std::string cwd = boost::filesystem::current_path().generic_string();
	String input_images_path = cwd + "images_test_input";

	vector<String> fn;
	glob(input_images_path, fn, true);
	Mat image; // recursive, if you want
	for (size_t i = 0; i < fn.size(); i++)
	{
		image = imread(fn[i]);
	}

	//

	// Mat image = imread("daft_punk_puplFiction.png");
	String windowName = "test image";
	namedWindow(windowName);
	imshow(windowName, image);
	waitKey(3000);			// display the output for 3 sec
	destroyWindow(windowName);

	/*	
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	*/


	return 0;

}
