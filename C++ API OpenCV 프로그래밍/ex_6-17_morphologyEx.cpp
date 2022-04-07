/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 모폴로지, Morphology
// 모폴로지 연산은 구조요소를 이용하여 반복적으로 영역을 확장시켜 떨어진 부분 또는 구멍을 채우거나, 잡음을 축소하여 제거하는 등의 연산으로
// 침식(erode), 팽창(dilate), 열기(opening), 닫기(closing) 등이 있다.
int main() {
	Mat srcImg = imread("D:\\example\\dataset\\morphology.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;
	imshow("srcImg", srcImg);

	Size size(5, 5);
	// getStructuringElement
	// 모폴로지 연산을 위한 ksize 크기의 모양 shape 구조 요소를 반환한다.
	Mat rectKernel = getStructuringElement(MORPH_RECT, size);

	int iterations = 5;
	Point anchor(-1, -1);

	Mat openImg;
	morphologyEx(srcImg, openImg, MORPH_OPEN, rectKernel, anchor, iterations);
	imshow("openImg", openImg);

	Mat closeImg;
	morphologyEx(srcImg, closeImg, MORPH_CLOSE, rectKernel, anchor, iterations);
	imshow("closeImg", closeImg);

	Mat gradientImg;
	morphologyEx(srcImg, gradientImg, MORPH_GRADIENT, rectKernel, anchor, iterations);
	imshow("gradientImg", gradientImg);

	Mat tophatImg;
	morphologyEx(srcImg, tophatImg, MORPH_TOPHAT, rectKernel, anchor, iterations);
	imshow("tophatImg", tophatImg);

	Mat blackhatImg;
	morphologyEx(srcImg, blackhatImg, MORPH_BLACKHAT, rectKernel, anchor, iterations);
	imshow("blackhatImg", blackhatImg);

	waitKey(0);
	return 0;
}
*/