
#include "pch.h"
#include <opencv2/opencv.hpp>
#include <string>
#include "stdio.h"
#include <iostream>
#include <boost/filesystem.hpp>
#include <gtest/gtest.h>
#include "lowPassFilterLibrary.h"
#include "highPassFilterLibrary.h"

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
	const fs::path input_img_dir = fs::absolute(relative_img_path, project_path);
	cout << "img input path is \n" << input_img_dir.string() << endl;
	const fs::path const_dir = input_img_dir;
	const fs::path base = fs::current_path();



	//fs::path canon = canonical(const_dir, base);

	//fs::path canon = fs::canonical(input_img_dir);

	// C:\Users\Adrien\source\repos\Cpp_Image_SW_2\ImageProcessingSW\Cpp_image_SW_3\Cpp_image_SW_3\images_test_output\high_pass_filter_output\Prewitt_x_output
	//cout << "its canonical form is \n";
	//cout << canon.string() << endl;
	
	
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
	
	//*************************************************************************
	// *********************** low pass functions test ************************
	//*************************************************************************

	// test for blur function
	Mat imgTestBlur = image.clone();
								
	const int order = 21;
	averageBlur(imgTestBlur, order); // passage by reference
	
	string output_path = "C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/low_pass_filter_output/averageBlur.jpg";
	imwrite(output_path, imgTestBlur);
	String windowNameBlur = "average blur image output";
	namedWindow(windowNameBlur);
	imshow(windowNameBlur, imgTestBlur);
	
	
	// test for gaussian function
	Mat imgTestGaussian = image.clone();

	//const int order = 21;
	gaussianFilter(imgTestGaussian, order); // passage by reference

	output_path = "C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/low_pass_filter_output/gaussianFilter.jpg";
	imwrite(output_path, imgTestGaussian);
	String windowNameGaussian = "gaussian blur image output";
	namedWindow(windowNameGaussian);
	imshow(windowNameGaussian, imgTestGaussian);


	// test for median function
	Mat imgTestMedian = image.clone();

	//const int order = 21;
	medianFilter(imgTestMedian, order); // passage by reference

	output_path = "C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/low_pass_filter_output/medianFilter.jpg";
	imwrite(output_path, imgTestMedian);
	String windowNameMedian = "Median blur image output";
	namedWindow(windowNameMedian);
	imshow(windowNameMedian, imgTestMedian);


	//*************************************************************************
	/********************* high pass function test ******************/
	//*************************************************************************
	



	// test prewitt x gradient
	Mat imgTestPrewitt_x;
	cvtColor(image.clone(), imgTestPrewitt_x, CV_BGR2GRAY);

	Mat imgOutputPrewitt_x = prewitt_x_Filter(imgTestPrewitt_x);

	output_path = "C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/high_pass_filter_output/prewitt_x_Filter.jpg";
	imwrite(output_path, imgOutputPrewitt_x);
	String windowNamePrewitt_x = "Prewitt gradient in x direction image output";
	namedWindow(windowNamePrewitt_x);
	imshow(windowNamePrewitt_x, imgOutputPrewitt_x);


	// test prewitt y gradient
	Mat imgTestPrewitt_y;
	cvtColor(image.clone(), imgTestPrewitt_y, CV_BGR2GRAY);

	Mat imgOutputPrewitt_y = prewitt_y_Filter(imgTestPrewitt_y);

	output_path = "C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/high_pass_filter_output/prewitt_y_Filter.jpg";
	imwrite(output_path, imgOutputPrewitt_y);
	String windowNamePrewitt_y = "Prewitt gradient in y direction image output";
	namedWindow(windowNamePrewitt_y);
	imshow(windowNamePrewitt_y, imgOutputPrewitt_y);


	// test sobel x gradient
	Mat imgTestSobel_x;
	cvtColor(image.clone(), imgTestSobel_x, CV_BGR2GRAY);

	Mat imgOutputSobel_x = sobel_x_Filter(imgTestSobel_x);

	output_path = "C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/high_pass_filter_output/sobel_x_Filter.jpg";
	imwrite(output_path, imgOutputSobel_x);
	String windowNameSobel_x = "Sobel gradient in x direction image output";
	namedWindow(windowNameSobel_x);
	imshow(windowNameSobel_x, imgOutputSobel_x);


	// test sobel y gradient
	Mat imgTestSobel_y;
	cvtColor(image.clone(), imgTestSobel_y, CV_BGR2GRAY);

	Mat imgOutputSobel_y = sobel_y_Filter(imgTestSobel_y);

	output_path = "C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/high_pass_filter_output/sobel_y_Filter.jpg";
	imwrite(output_path, imgOutputSobel_y);
	String windowNameSobel_y = "Sobel gradient in y direction image output";
	namedWindow(windowNameSobel_y);
	imshow(windowNameSobel_y, imgOutputSobel_y);


	// test norm2 function

	Mat imgTestNorm2;
	cvtColor(image.clone(), imgTestNorm2, CV_BGR2GRAY);

	Mat imgNorm2_output = norm2_of_gradient(imgOutputPrewitt_x, imgOutputPrewitt_y);

	output_path = "C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/high_pass_filter_output/norm2_Prewitt.jpg";
	imwrite(output_path, imgNorm2_output);
	String windowNameimgNorm2_output = "Module of Prewitt gradient";
	namedWindow(windowNameimgNorm2_output);
	imshow(windowNameimgNorm2_output, imgNorm2_output);


	// test norm2 Prewitt

	Mat imgTestNorm2_prewitt;
	cvtColor(image.clone(), imgTestNorm2_prewitt, CV_BGR2GRAY);

	Mat imgNorm2_prewitt_output = norm2_of_prewitt(imgTestNorm2_prewitt);

	output_path = "C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/high_pass_filter_output/norm2_Prewitt_2.jpg";
	imwrite(output_path, imgNorm2_prewitt_output);
	String windowNameimgNorm2_prewitt_output = "Module of Prewitt gradient";
	namedWindow(windowNameimgNorm2_prewitt_output);
	imshow(windowNameimgNorm2_prewitt_output, imgNorm2_prewitt_output);


	// test norm2 Sobel

	Mat imgTestNorm2_sobel;
	cvtColor(image.clone(), imgTestNorm2_sobel, CV_BGR2GRAY);

	Mat imgNorm2_sobel_output = norm2_of_sobel(imgTestNorm2_sobel);

	output_path = "C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/high_pass_filter_output/norm2_Sobel.jpg";
	imwrite(output_path, imgNorm2_sobel_output);
	String windowNameimgNorm2_sobel_output = "Module of Sobel gradient";
	namedWindow(windowNameimgNorm2_sobel_output);
	imshow(windowNameimgNorm2_sobel_output, imgNorm2_sobel_output);


	waitKey(0);			// display the output 
	destroyAllWindows();
	
	return 0;

}

/*


/*

vector<String> fn;
glob(input_images_path, fn, true);
Mat image; // recursive, if you want
for (size_t i = 0; i < fn.size(); i++)
{
	image = imread(fn[i]);
}

/*
testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
*/