/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

vector<vector<Point>> myFindContours(Mat& srcImg);

int main()
{
	Mat refImg = imread("D:\\example\\dataset\\shapes\\refShapes.png", IMREAD_GRAYSCALE);
	Mat tempImg = imread("D:\\example\\dataset\\shapes\\refShapes1.png", IMREAD_GRAYSCALE);
	if (refImg.empty() || tempImg.empty()) return -1;

	Scalar colorTable[] = { Scalar(0, 0, 255),
							Scalar(0, 255, 0),
							Scalar(255, 0, 0) };
	vector<vector<Point>> refContours = myFindContours(refImg);
	vector<vector<Point>> tempContours = myFindContours(tempImg);
	if (refContours.size() < 1 || tempContours.size() < 1) return -1;

	Mat refRGB;
	cvtColor(refImg, refRGB, COLOR_GRAY2BGR);
	for (int k = 0; k < refContours.size(); k++) drawContours(refRGB, refContours, k, colorTable[k], 2);
	imshow("refRGB", refRGB);

	Mat tempRGB;
	cvtColor(tempImg, tempRGB, COLOR_GRAY2BGR);

	int minK;
	double minD;
	int method = 3;
	for (int i = 0; i < tempContours.size(); i++) // matching tempContours
	{
		// find matches
		minK = 0;
		minD = matchShapes(refContours[0], tempContours[i], method, 0);
		for (int k = 1; k < refContours.size(); k++)
		{
			double d = matchShapes(refContours[k], tempContours[i], method, 0);
			if (d < minD)
			{
				minD = d;
				minK = k;
			}
		}
		drawContours(tempRGB, tempContours, i, colorTable[minK], 2);
	}
	imshow("tempRGB", tempRGB);
	waitKey(0);
	return 0;
}

vector<vector<Point>> myFindContours(Mat& srcImg)
{
	GaussianBlur(srcImg, srcImg, Size(3, 3), 0.0);

	Mat bImg;
	threshold(srcImg, bImg, 128, 255, THRESH_BINARY_INV + THRESH_OTSU);
	erode(bImg, bImg, Mat(), Point(-1, -1), 1);
	dilate(bImg, bImg, Mat(), Point(-1, -1), 2);

	vector<vector<Point>> contours;
	findContours(bImg, contours, noArray(), RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	return contours;
}
*/