
#include "pch.h"
#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>
//#include <boost/filesystem.hpp>
#include <gtest/gtest.h>
#include "lowPassFilterLibrary.h"
//#include "highPassFilterLibrary.h"

using namespace std;
using namespace cv;

const int windowTimer = 10000; // [ms]

int main(int argc, char* argv[])
{
    cout << "Hello World!\n"; 


	// read test image
	Mat image = imread("Vancouver.jpg");
	String windowName = "test image";
	namedWindow(windowName);
	imshow(windowName, image);
	
	
	// test for blur function
	Mat imgTestBlur = image;
	
	const int order = 21;
	averageBlur(imgTestBlur, order); // passage by reference
	
	String windowNameBlur = "average blur image output";
	namedWindow(windowNameBlur);
	imshow(windowNameBlur, imgTestBlur);
	
	
	// test for gaussian function
	Mat imgTestGaussian = image;

	//const int order = 21;
	gaussianFilter(imgTestGaussian, order); // passage by reference

	String windowNameGaussian = "gaussian blur image output";
	namedWindow(windowNameGaussian);
	imshow(windowNameGaussian, imgTestGaussian);


	// test for median function
	Mat imgTestMedian = image;

	//const int order = 21;
	medianFilter(imgTestMedian, order); // passage by reference

	String windowNameMedian = "Median blur image output";
	namedWindow(windowNameMedian);
	imshow(windowNameMedian, imgTestMedian);


	waitKey(0);			// display the output 
	destroyAllWindows();
	return 0;

}



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