#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define TH 10

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\circle2.png");
	if (srcImg.empty()) return -1;
	imshow("srcImg", srcImg);

	Mat srcImg8;
	cvtColor(srcImg, srcImg8, COLOR_BGR2GRAY);

	Mat dstImg8;
	threshold(srcImg8, dstImg8, 0, 255, THRESH_BINARY_INV + THRESH_OTSU);
	imshow("dstImg8", dstImg8);

	Mat distance, distImg8;
	distanceTransform(dstImg8, distance, DIST_L1, 3);
	normalize(distance, distImg8, 0, 255, NORM_MINMAX, CV_8U);
	imshow("distance", distImg8);

	Mat mask;
	mask = distance > TH;
	imshow("mask", mask);

	vector<vector<Point>> contours;
	findContours(mask, contours, noArray(), RETR_LIST, CHAIN_APPROX_SIMPLE);
	if (contours.size() < 1) return -1;

	Mat markers = Mat::zeros(srcImg.size(), CV_32S);
	for (int k = 0; k < contours.size(); k++)
	{
		drawContours(markers, contours, k, k + 1, -1);
	}

	// create background marker
	circle(markers, Point(5, 5), 3, Scalar::all(contours.size() + 1), -1);

	// segment objects by using markers
	Mat dstImg = srcImg.clone();
	watershed(dstImg, markers);

	// make color tables for displaying objects
	Mat colorTable(contours.size() + 1, 1, CV_8UC3);
	Vec3b color;
	for (int k = 0; k < contours.size(); k++)
	{
		color[0] = rand() & 180 + 50;
		color[1] = rand() & 180 + 50;
		color[2] = rand() & 180 + 50;
		colorTable.at<Vec3b>(k, 0) = color;
	}

	// display objects using markers
	for (int y = 0; y < markers.cols; y++)
	{
		for (int x = 0; x < markers.rows; x++)
		{
			int k = markers.at<int>(y, x);
			// boundary
			if (k == -1) color[0] = color[1] = color[2] = 255;
			else if (k <= 0 || k > contours.size()) color[0] = color[1] = color[2] = 0;
			else
			{
				color = colorTable.at<Vec3b>(k - 1, 0);
				dstImg.at<Vec3b>(y, x) = color;
			}
		}
	}

	addWeighted(dstImg, 0.5, srcImg, 0.5, 0, dstImg);
	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}