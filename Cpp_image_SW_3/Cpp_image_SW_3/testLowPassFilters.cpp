#include "pch.h"
#include <gtest/gtest.h>
#include "testFilter.h"
#include "lowPassFilterLibrary.h"

using namespace std;

/* Scénario d'un test de low pass filter
- consrtuire une image test 
- appliquer le filtre 
- sauvegarder l'image de sortie 
- afficher le résultat du test

- le test est soit à traitement unique ou sur un ensemble de paramètres
*/



// Gtest for function averageFilter
TEST(LowPassFilterTest, testAverageBlur) {
	string path = "path to choose";
	string img_file_name = "noisy_Elaine_image.png";
	int order = 21;
	string filter = "average";

	// create test object
	testFilter testAverage(path,img_file_name,filter,order);

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
TEST(LowPassFilterTest, testAverageBlur) {
	string path = "path to choose";
	string img_file_name = "noisy_Elaine_image.png";
	int order = 21;
	string filter = "median";

	// create test object
	testFilter testMedian(path, img_file_name, filter, order);

	// proceed test
	testMedian.processTestFilter();
}