/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:/example/dataset/lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat_<uchar> lut(1, 256);	// 1* 256 크기의 Mat 행렬
	for (int i = 0; i < 256; i++) lut(i) = 256 - i;

	Mat_<uchar> dstImg;
	LUT(srcImg, lut, dstImg);	// src에 lut 행렬 적용

	imshow("srcImg", srcImg);
	imshow("dstImg", dstImg);
	waitKey(0);

	return 0;
}
*/