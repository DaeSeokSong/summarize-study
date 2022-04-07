/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;
	imshow("srcImg", srcImg);

	int border = 3;
	Size kSize(border * 2 + 1, border * 2 + 1);

	Mat dstImg1;
	// boxFilter는 디폴트로 정규화를 하도록 되어있으며, 정규화를 하게 되면 filter2D, sepFilter2D와 결과가 같다.
	boxFilter(srcImg, dstImg1, -1, kSize);
	imshow("dstImg1", dstImg1);

	Mat dstImg2;
	int d = kSize.width;
	double sigmaColor = 10.0;
	double sigmaSpace = 10.0;
	bilateralFilter(srcImg, dstImg2, d, sigmaColor, sigmaSpace);
	imshow("dstImg2", dstImg2);

	Mat dstImg3;
	bilateralFilter(srcImg, dstImg3, -1, sigmaColor, sigmaSpace);
	imshow("dstImg3", dstImg3);

	waitKey(0);
	return 0;
}
*/