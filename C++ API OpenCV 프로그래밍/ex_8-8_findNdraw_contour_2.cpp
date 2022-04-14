/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:\\example\\dataset\\contours.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	threshold(srcImg, srcImg, 128, 255, THRESH_BINARY);

	Mat srcImg2 = srcImg.clone();
	Mat dstImg(srcImg2.size(), CV_8UC3);
	cvtColor(srcImg2, dstImg, COLOR_GRAY2BGR);

	int mode = RETR_TREE;
	int method = CHAIN_APPROX_SIMPLE;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(srcImg, contours, hierarchy, mode, method);

	Scalar color[4] = { Scalar(255, 0 , 0),
						Scalar(0, 255, 0),
						Scalar(0, 0, 255),
						Scalar(0, 255, 255) };

	for (int k = 0; k < contours.size(); k++)
	{
		imshow("dstImg, k = " + to_string(k), dstImg);
		cvtColor(srcImg2, dstImg, COLOR_GRAY2BGR);
		drawContours(dstImg, contours, k, Scalar(0, 0, 255), 2);

		for (int i = 0; i < 4; i++)
		{
			if (hierarchy[k][i] < 0) continue;
			drawContours(dstImg, contours, hierarchy[k][i], color[i], 2);
		}
	}

	imshow("dstImg", dstImg);
	waitKey(0);
	return 0;
}
*/