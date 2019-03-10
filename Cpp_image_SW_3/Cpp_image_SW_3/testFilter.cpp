#include "pch.h"
#include "testFilter.h"


using namespace std;
using namespace cv;

testFilter::testFilter(string input_path, string img_file_name, string filter, int order)
{
	set_img_input(img_file_name);// imread
	set_output_path("default");
	set_kernel_size(order);
	filter_lists = {"average","gaussian","median"};

	bool filter_present = false;
	
	for(unsigned int i =0; i<=filter_lists.size();++i)
	{
		if (filter == filter_lists[i]) {
			filter_present = true;
			set_filter_index(i);
			cout << "the filter is known" << endl;
			cout << "filter selected " << filter_lists[filter_index] << endl;
		};
	}
	/*
	string input_path;
	string output_path;
	Mat imp_output;
	*/

}


testFilter::~testFilter()
{
	cout << "calling testFilter destructor" << endl;
}

void testFilter::processTestFilter()
{
	// 
	Mat imgOut;
	cvtColor(img_input, imgOut, CV_BGR2GRAY);

	string windowName = "grayscale input image";
	namedWindow(windowName);
	imshow(windowName, imgOut);
	waitKey(3000); // display the output for 3 sec

	int order = 21;

	switch (filter_index)
	{
	case 0:
		averageBlur(imgOut, kernel_size);
		set_output_path("C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/low_pass_filter_output/averageBlur.jpg");
	case 1:
		gaussianFilter(imgOut, kernel_size);
		set_output_path("C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/low_pass_filter_output/gaussianFilter.jpg");
	case 2:
		medianFilter(imgOut, kernel_size);
		set_output_path("C:/Users/Adrien/source/repos/Cpp_Image_SW_2/ImageProcessingSW/Cpp_image_SW_3/Cpp_image_SW_3/images_test_output/low_pass_filter_output/medianFilter.jpg");
	default:
		cout << "no filter applied" << endl;
		break;
	}

	if (output_path != "default") {
		String outputTitle = filter_lists[filter_index] + " filter with order " + to_string(kernel_size);

		//save image
		cv::imwrite(output_path, imgOut);

		imshow(outputTitle, imgOut);
		waitKey(3000);	// display the output for 3 sec
		destroyWindow(windowName);
		destroyAllWindows();
	}
}


void testFilter::set_img_input(string img_file_name)
{	
	img_input = imread(img_file_name);
}

void testFilter::set_output_path(string output_path) {
	output_path = output_path;
}

void testFilter::set_filter_index(unsigned int index)
{
	filter_index = index;
}

void testFilter::set_kernel_size(int order)
{
	kernel_size = order;
}
