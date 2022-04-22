/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\momentTest.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat dstImg;
	cvtColor(srcImg, dstImg, COLOR_GRAY2BGR);

	threshold(srcImg, srcImg, 200, 255, THRESH_BINARY);

	int mode = RETR_LIST;
	int method = CHAIN_APPROX_SIMPLE;

	vector<vector<Point>> contours;
	findContours(srcImg, contours, noArray(), mode, method);

	for (int k = 0; k < contours.size(); k++)
	{
		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dstImg, contours, k, color, 4);

		Moments M = moments(contours[k]);

		Point2f center;
		center.x = M.m10 / M.m00;
		center.y = M.m01 / M.m00;

		circle(dstImg, center, 5, Scalar(0, 255, 0), -1);
		imshow("dstImg", dstImg);

		Mat hu;
		HuMoments(M, hu);
		for (int i = 0; i < hu.rows; i++)
		{
			cout << "hu[" << i << "] = ";
			cout << hu.at<double>(i) << endl;
		}
	}

	waitKey(0);
	return 0;
}
*/