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

	int blockSize = 5;
	int ksize = 3;
	double k = 0.01;

	// cornerHarris
	// 단일 채널 8비트 또는 실수 입력 영상에서 Harris 코너 검출 반응값을 위한
	// CV_32FC1 자료형의 dst에 계산한다. Sobel 커널(필터)를 사용한다.
	// k는 Harris 코너 검출 상수로, 반응값의 행렬 dst에서 지역 극대값이 코너점이 된다.
	// 임계값을 적용하여 너무 많은 코너점이 나오는 걸 방지한다.
	Mat R;
	cornerHarris(srcImg, R, blockSize, ksize, k);
	threshold(R, R, 0.01, 0, THRESH_TOZERO);

	vector<Point> cornerPoints = FindLocalMaxima(R);
	Mat dstImg(srcImg.size(), CV_8UC3);
	cvtColor(srcImg, dstImg, COLOR_GRAY2BGR);

	vector<Point>::const_iterator it;
	for (it = cornerPoints.begin(); it != cornerPoints.end(); ++it)
	{
		circle(dstImg, *it, 5, Scalar(255, 0, 255), 2);
		int x = (*it).x;
		int y = (*it).y;
		float fValue = R.at<float>(y, x);
	}
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