/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return - 1;
	imshow("srcImg", srcImg);

	int ksize = 7;
	Mat dstImg1;
	medianBlur(srcImg, dstImg1, ksize);
	imshow("dstImg1", dstImg1);

	Mat dstImg2;
	blur(srcImg, dstImg2, Size(ksize, ksize));
	imshow("dstImg2", dstImg2);

	Mat dstImg3;
	GaussianBlur(srcImg, dstImg3, Size(ksize, ksize), 0.0);
	imshow("dstImg3", dstImg3);

	ksize = 11;
	Mat dstImg4;
	GaussianBlur(srcImg, dstImg4, Size(ksize, ksize), 0.0);
	imshow("dstImg4", dstImg4);

	Mat kx = getGaussianKernel(ksize, 0.0);
	Mat ky = getGaussianKernel(ksize, 0.0);
	Mat kxy = kx * ky.t();

	Mat dstImg5;
	sepFilter2D(srcImg, dstImg5, -1, kx, ky);
	imshow("dstImg5", dstImg5);

	Mat dstImg6;
	filter2D(srcImg, dstImg6, -1, kxy);
	imshow("dstImg6", dstImg6);

	waitKey(0);
	return 0;
}
*/