/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

vector<Point> FindLocalMaxima(Mat& src);

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\life\\book.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	// preCornerDetect
	// src에서 코너점 검출을 위한 특징 맵 dst를 Sobel 미분 연산자를 이용하여 계산한다.
	// borderType에 따라 경계값 처리 방식이 달라진다.
	Mat cornerMap;
	preCornerDetect(srcImg, cornerMap, 3);

	cornerMap = abs(cornerMap);
	threshold(cornerMap, cornerMap, 0.01, 0, THRESH_TOZERO);

	vector<Point> cornerPoints = FindLocalMaxima(cornerMap);
	Mat dstImg(srcImg.size(), CV_8UC3);
	cvtColor(srcImg, dstImg, COLOR_GRAY2BGR);

	vector<Point>::const_iterator it;
	for (it = cornerPoints.begin(); it != cornerPoints.end(); ++it) circle(dstImg, *it, 5, Scalar(0, 0, 255), 2);

	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}

vector<Point> FindLocalMaxima(Mat& src)
{
	Mat dilated;
	Mat localMax;
	Size size(11, 11);
	Mat rectKernel = getStructuringElement(MORPH_RECT, size);

	dilate(src, dilated, rectKernel);
	localMax = (src == dilated);

	Mat eroded;
	Mat localMin;

	erode(src, eroded, rectKernel);
	localMin = (src > eroded);

	localMax = (localMax & localMin);

	vector<Point> points;
	for (int y = 0; y < localMax.rows; y++)
	{
		for (int x = 0; x < localMax.cols; x++)
		{
			uchar uValue = localMax.at<uchar>(y, x);
			if (uValue) points.push_back(Point(x, y));
		}
	}

	return points;
}
*/