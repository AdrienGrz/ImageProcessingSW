#include "calibration.h"

using namespace cv;
using namespace std;

/*fonction AnalyseGrille:

*/

/*
bool AnalyseGrille(Mat x, ParamCalibration *pc, ParamCalibration3D *sys3d, int index, Mat frame, ParamMire &mire)
{
	vector<Point2f> echiquier;
	bool grille = findChessboardCorners(x, Size(mire.nbC, mire.nbL), echiquier, CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_FAST_CHECK | CALIB_CB_NORMALIZE_IMAGE);
	if (grille)
	{
		Mat imGris;
		cvtColor(x, imGris, CV_BGR2GRAY);
		cornerSubPix(imGris, echiquier, Size(5, 5), Size(-1, -1), TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 100, 0.01));
		drawChessboardCorners(frame, Size(mire.nbC, mire.nbL), Mat(echiquier), false);
		if (sys3d == NULL && pc)
		{
			pc->pointsCamera.push_back(echiquier);
			pc->pointsObjets.push_back(pc->pointsGrille);
		}
		if (sys3d)
		{
			if (index == 0)
			{
				sys3d->pointsCameraGauche.push_back(echiquier);
				sys3d->pointsObjets.push_back(pc->pointsGrille);
			}
			else
				sys3d->pointsCameraDroite.push_back(echiquier);
		}

	}
	else
		return false;
	return true;
}


/* structure paramCalibration

*/

/*
struct ParamCalibration {
	vector<int> typeCalib2D = { CALIB_FIX_PRINCIPAL_POINT + CALIB_FIX_K4 + CALIB_FIX_K5 + CALIB_FIX_K6 + CALIB_ZERO_TANGENT_DIST,CALIB_FIX_K4 + CALIB_FIX_K5 + CALIB_FIX_K6 + CALIB_ZERO_TANGENT_DIST };
	int indexUSB;
	int index;
	vector<Mat> rvecs, tvecs;
	Mat cameraMatrix, distCoeffs;
	Mat mapx;
	Mat mapy;
	int nbImageGrille = 0;
	vector<Point3f>  pointsGrille;
	vector<vector<Point2f>>  pointsCamera;
	vector<vector<Point3f> > pointsObjets;
	Size tailleImage;
	double rms;
	String ficDonnees;
};


/* structure paramCalibration3D

*/
/*
struct ParamCalibration3D {
	vector<int> typeCalib3D = { CALIB_FIX_INTRINSIC + CALIB_ZERO_DISPARITY,CALIB_ZERO_DISPARITY };
	Mat R, T, E, F;
	Mat R1, R2, P1, P2;
	Mat Q;
	vector<Mat> m;
	vector<Mat> d;
	Rect valid1, valid2;
	double rms;
	String ficDonnees;
	vector<vector<Point2f>>  pointsCameraGauche;
	vector<vector<Point2f>>  pointsCameraDroite;
	vector<vector<Point3f> > pointsObjets;
};


/* structure paramMire

*/

/*
struct ParamMire {
	int nbL = 9, nbC = 6;
	int nbLAruco = 5, nbCAruco = 8;
	float dimCarre = 0.0275;
	float dimAruco = 0.034625;
	float sepAruco = 0.02164;
	int dict = cv::aruco::DICT_7X7_250;
	Ptr<aruco::Dictionary> dictionary;
	Ptr<aruco::CharucoBoard> gridboard;
	Ptr<aruco::Board> board;
	Ptr<aruco::DetectorParameters> detectorParams;
};


*/