/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\momentTest.png");
	if (srcImg.empty()) return -1;
	else srcImg.convertTo(srcImg, CV_32F);

	// integral
	// CV_8U, CV_32F, CV_64F 실수 영상의 입력을 받아 적분 영상을 만든다.
	// 적분 영상을 사용하면 사각 영역의 합계, 평균, 표준편차 등을 빠르게 계산할 수 있다.
	// 그렇기에 Haar-like 특징, SURF 등에서 사용한다.
	Mat sumImg, sqsumImg, tiltedSumImg;
	integral(srcImg, sumImg, sqsumImg, tiltedSumImg);

	imshow("srcImg", srcImg);
	imshow("sumImg", sumImg);
	imshow("sqsumImg", sqsumImg);
	imshow("tiltedSumImg", tiltedSumImg);

	waitKey(0);
	return 0;
}
*/