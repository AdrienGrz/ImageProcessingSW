#include "pch.h"
#include "gtest/gtest.h"
#include "../Cpp_image_SW_3/testFilter.h"
#include "../Cpp_image_SW_3/highPassFilterLibrary.h"
#include "../Cpp_image_SW_3/lowPassFilterLibrary.h"




TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

// Gtest for function averageFilter
TEST(LowPassFilterTest, testAverageBlur) {
	string path = "path to choose";
	string img_file_name = "noisy_Elaine_image.png";
	int order = 21;
	string filter = "average";

	// create test object
	testFilter testAverage(path, img_file_name, filter, order);

	// proceed test
	testAverage.processTestFilter();
}

// Gtest for function gaussianFilter
TEST(LowPassFilterTest, testGaussianBlur) {
	string path = "path to choose";
	string img_file_name = "noisy_Elaine_image.png";
	int order = 21;
	string filter = "gaussian";

	// create test object
	testFilter testGaussian(path, img_file_name, filter, order);

	// proceed test
	testGaussian.processTestFilter();
}

// Gtest for function medianFilter
TEST(LowPassFilterTest, testMedianFilter) {
	string path = "path to choose";
	string img_file_name = "noisy_Elaine_image.png";
	int order = 21;
	string filter = "median";

	// create test object
	testFilter testMedian(path, img_file_name, filter, order);

	// proceed test
	testMedian.processTestFilter();
}