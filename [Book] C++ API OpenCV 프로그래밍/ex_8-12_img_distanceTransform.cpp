/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	//Mat srcImg = imread("D:\\example\\dataset\\distTest.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;
	imshow("srcImg", srcImg);

	threshold(srcImg, srcImg, 200, 255, THRESH_BINARY);
	int distanceType = DIST_L1;
	int maskSize = 3;

	Mat distance;
	distanceTransform(srcImg, distance, distanceType, maskSize);

	Mat dstImg;
	normalize(distance, dstImg, 0, 255, NORM_MINMAX, CV_8U);
	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}
*/