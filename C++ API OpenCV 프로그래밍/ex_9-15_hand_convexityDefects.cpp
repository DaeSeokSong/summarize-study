/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\hand.png");
	if (srcImg.empty()) return -1;

	Mat dstImg = srcImg.clone();
	GaussianBlur(srcImg, srcImg, Size(3, 3), 0.0);

	Mat hsvImg;
	cvtColor(srcImg, hsvImg, COLOR_BGR2HSV);
	imshow("hsvImg", hsvImg);

	Mat bImg;
	Scalar lowerb(0, 40, 0);
	Scalar upperb(20, 180, 255);
	inRange(hsvImg, lowerb, upperb, bImg);

	erode(bImg, bImg, Mat());
	dilate(bImg, bImg, Mat(), Point(-1, -1), 2);
	imshow("bImg", bImg);

	vector<vector<Point>> contours;
	findContours(bImg, contours, noArray(), RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	if (contours.size() < 1) return -1;

	int maxK = 0;
	double maxArea = contourArea(contours[0]);
	for (int k = 1; k < contours.size(); k++)
	{
		double area = contourArea(contours[k]);
		if (area > maxArea)
		{
			maxK = k;
			maxArea = area;
		}
	}
	vector<Point> handContour = contours[maxK];

	vector<int> hull;
	convexHull(handContour, hull);

	vector<Point> ptsHull;
	for (int k = 0; k < hull.size(); k++)
	{
		int i = hull[k];
		ptsHull.push_back(handContour[i]);
	}
	drawContours(dstImg, vector<vector<Point>>(1, ptsHull), 0, Scalar(255, 0, 0), 2);

	vector<Vec4i> defects;
	convexityDefects(handContour, hull, defects);
	for (int k = 0; k < defects.size(); k++)
	{
		Vec4i v = defects[k];
		Point ptStart = handContour[v[0]];
		Point ptEnd = handContour[v[1]];
		Point ptFar = handContour[v[2]];
		float depth = v[3] / 256.0;
		if (depth > 10)
		{
			line(dstImg, ptStart, ptFar, Scalar(0, 255, 0), 2);
			line(dstImg, ptStart, ptEnd, Scalar(0, 0, 255), 2);
			circle(dstImg, ptStart, 6, Scalar(255, 0, 255), 2);
			circle(dstImg, ptEnd, 6, Scalar(0, 255, 255), 2);
			circle(dstImg, ptFar, 6, Scalar(255, 255, 255), 2);
		}
	}
	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}
*/