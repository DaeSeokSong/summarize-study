/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png");
	if (srcImg.empty()) return -1;
	imshow("BGR image", srcImg);

	Mat hsvImg;
	cvtColor(srcImg, hsvImg, COLOR_BGR2HSV);
	imshow("HSV image", hsvImg);

	Scalar lowerb(0, 40, 0);
	Scalar upperb(20, 180, 255);
	Mat dstImg;
	inRange(hsvImg, lowerb, upperb, dstImg);
	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}
*/