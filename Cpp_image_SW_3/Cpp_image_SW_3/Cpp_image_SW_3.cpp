// Cpp_image_SW_3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>
#include <gtest/gtest.h>
#include "lowPassFilterLibrary.h"
#include "highPassFilterLibrary.h"

using namespace std;
using namespace cv;


int main(int argc, char* argv[])
{
    cout << "Hello World!\n"; 


	Mat image = imread("daft_punk_puplFiction.png");
	String windowName = "test image";
	namedWindow(windowName);
	imshow(windowName, image);
	waitKey(3000);			// display the output for 3 sec
	destroyWindow(windowName);

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	return 0;

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
