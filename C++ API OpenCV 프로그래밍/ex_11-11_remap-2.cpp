/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Point2f center(256.0f, 256.0f);
	double angle = -45.0;
	double scale = 1.0;
	Mat rotMat = getRotationMatrix2D(center, angle, scale);

	vector<Point2f> srcCorners;
	srcCorners.push_back(Point2f(0, 0));
	srcCorners.push_back(Point2f(srcImg.cols - 1, 0));
	srcCorners.push_back(Point2f(srcImg.cols - 1, srcImg.rows - 1));
	srcCorners.push_back(Point2f(0, srcImg.rows - 1));

	vector<Point2f> dstCorners;
	transform(srcCorners, dstCorners, rotMat);

	float minX, minY;
	float maxX, maxY;
	for (int i = 0; i < dstCorners.size(); i++)
	{
		if (i == 0)
		{
			minX = maxX = dstCorners[i].x;
			minY = maxY = dstCorners[i].y;
		}
		else
		{
			if (minX > dstCorners[i].x) minX = dstCorners[i].x;
			if (minY > dstCorners[i].y) minY = dstCorners[i].y;
			if (maxX < dstCorners[i].x) maxX = dstCorners[i].x;
			if (maxY < dstCorners[i].y) maxY = dstCorners[i].y;
		}
	}

	Size dsize;
	dsize.width = cvRound(maxX - minX);
	dsize.height = cvRound(maxY - minY);

	Mat mapX(dsize, CV_32FC1);
	Mat mapY(dsize, CV_32FC1);

	rotMat.at<double>(0, 2) -= minX;
	rotMat.at<double>(1, 2) -= minY;

	Mat iMat;
	invertAffineTransform(rotMat, iMat);

	Mat A(3, 1, CV_64F);
	Mat B;
	for (int i = 0; i < dsize.height; i++)
	{
		for (int k = 0; k < dsize.width; k++)
		{
			A.at<double>(0, 0) = i;
			A.at<double>(1, 0) = k;
			A.at<double>(2, 0) = 1.0;
			B = iMat * A;

			mapX.at<float>(k, i) = B.at<double>(0, 0);
			mapY.at<float>(k, i) = B.at<double>(1, 0);
		}
	}

	Mat dstImg;
	remap(srcImg, dstImg, mapX, mapY, INTER_LINEAR);

	imshow("dstImg", dstImg);
	waitKey(0);
	return 0;
}
*/