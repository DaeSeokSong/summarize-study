/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Size kSize(7, 7);
	Mat avgKernel = Mat::ones(kSize, CV_32F);
	avgKernel /= avgKernel.total();

	Mat avgImg;
	filter2D(srcImg, avgImg, -1, avgKernel);
	imshow("avgImg", avgImg);

	Mat avgX = Mat::ones(1, kSize.width, CV_32F);
	Mat avgY = Mat::ones(kSize.height, 1, CV_32F);
	avgX /= avgX.total();
	avgY /= avgY.total();

	Mat avgImg2;
	sepFilter2D(srcImg, avgImg2, -1, avgX, avgY);
	imshow("avgImg2", avgImg2);
	cout <<
	waitKey(0);
	return 0;
}
*/