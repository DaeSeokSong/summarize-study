/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = Mat::zeros(512, 512, CV_8UC1);

	rectangle(srcImg, Point(50, 100), Point(200, 400), Scalar::all(255), -1);
	rectangle(srcImg, Point(80, 150), Point(180, 350), Scalar::all(0), -1);

	rectangle(srcImg, Point(250, 100), Point(450, 400), Scalar::all(255), -1);
	rectangle(srcImg, Point(280, 150), Point(420, 350), Scalar::all(255), -1);
	rectangle(srcImg, Point(320, 200), Point(380, 300), Scalar::all(255), -1);

	Mat dstImg(srcImg.size(), CV_8UC3);
	cvtColor(srcImg, dstImg, COLOR_GRAY2BGR);

	int mode = RETR_LIST;
	int method = CHAIN_APPROX_SIMPLE;

	vector<vector<Point>> contours;
	findContours(srcImg, contours, noArray(), mode, method);
	for (int k = 0; k < contours.size(); k++)
	{
		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dstImg, contours, k, color, 4);
	}

	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}
*/