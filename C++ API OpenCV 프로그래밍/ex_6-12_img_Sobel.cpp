/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;
	imshow("srcImg", srcImg);

	int ksize = 3;
	int ddepth = CV_32F;
	Mat dstGx, dstGy;
	Sobel(srcImg, dstGx, ddepth, 1, 0, ksize);
	Sobel(srcImg, dstGy, ddepth, 0, 1, ksize);

	int dtype = CV_8U;
	Mat dstImgGx;
	normalize(abs(dstGx), dstImgGx, 0, 255, NORM_MINMAX, dtype);
	imshow("dstImgGx", dstImgGx);

	Mat dstImgGy;
	normalize(abs(dstGy), dstImgGy, 0, 255, NORM_MINMAX, dtype);
	imshow("dstImgGy", dstImgGy);

	Mat dstMag;
	// magnitude, (각 요소의) 제곱 합계의 제곱근을 계산한다.
	magnitude(dstGx, dstGy, dstMag);
	Mat dstImgGxy;
	normalize(dstMag, dstImgGxy, 0, 255, NORM_MINMAX, dtype);
	imshow("dstImgGxy", dstImgGxy);

	waitKey(0);
	return 0;
}
*/