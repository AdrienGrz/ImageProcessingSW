
#include "pch.h"
#include <opencv2/opencv.hpp>
#include <string>
#include "stdio.h"
#include <iostream>
#include <boost/filesystem.hpp>
#include <gtest/gtest.h>
#include "lowPassFilterLibrary.h"
//#include "highPassFilterLibrary.h"

using namespace std;
using namespace cv;
namespace fs = boost::filesystem;

// global variables
const int windowTimer = 10000; // [ms]
const fs::path project_path = fs::current_path();
const string project_dir = fs::current_path().string();



int main(int argc, char* argv[])
{
	cout << "Hello World!\n";

	//use relative path
	fs::path relative_img_path = "Cpp_image_SW_3/images_test_input";
	// std::string  input_img_dir = 
	const fs::path input_img_dir = fs::absolute(relative_img_path, project_path);
	cout << "img input path is " << input_img_dir.string() << endl;
	

	// read test image
	fs::path file = "Vancouver.jpg";
	fs::path imageVancouveur = input_img_dir / file;
	//cout << "vancouver is at the path" << endl;
	//cout << imageVancouveur.string() << endl;


	cv::String imageNameCV = cv::String(imageVancouveur.string());
	cout << "image Name is " << imageNameCV << endl;

	String imageName = "C:\\Users\\Adrien\\source\\repos\\Cpp_Image_SW_2\\ImageProcessingSW\\Cpp_image_SW_3\\Cpp_image_SW_3\\images_test_input\\Vancouver.jpg";
	Mat image = imread(imageName, CV_32F);
	
	int height = image.rows;
	int width = image.cols;
	cout << "the test image has the dimension (height,width) = (" << height << "," << width << ")" << endl;
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
WARNING : this getcwd call is deprecated

std::string get_working_path()
{
	const int MAXPATHLEN = 1000;
	char temp[MAXPATHLEN];
	return (getcwd(temp, sizeof(temp)) ? std::string(temp) : std::string(""));
}
*/

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