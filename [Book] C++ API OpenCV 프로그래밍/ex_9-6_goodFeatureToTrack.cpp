/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\life\\bookcover.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	int maxCorners = 8;
	double qualityLevel = 0.001;
	double minDistance = 10;
	int blockSize = 3;
	bool useHarrisDetector = true;
	double k = 0.04;

	// goodFeaturesToTrack
	// 8비트 또는 32비트 실수의 단일 채널 영상에서 뚜렷한 코너점을 검출한다.
	// 믈체의 포인트 기반 추적에서 초기화할 때 사용한다.
	// HarrisDetector와 cornerMinEigenVal 함수 또는 cornerMinEigenVal 하나만을 사용하여 코너점 측정값을 계산한다.
	vector<Point> cornerPoints;
	goodFeaturesToTrack(srcImg, cornerPoints, maxCorners, qualityLevel, minDistance, noArray(), blockSize, useHarrisDetector, k); // noArray() == mask

	Mat dstImg(srcImg.size(), CV_8UC3);
	cvtColor(srcImg, dstImg, COLOR_GRAY2BGR);

	vector<Point>::const_iterator it;
	for (it = cornerPoints.begin(); it != cornerPoints.end(); ++it)
	{
		circle(dstImg, *it, 5, Scalar(0, 255, 255), 2);
	}
	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}
*/