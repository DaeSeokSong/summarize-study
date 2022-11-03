#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("pepper.bmp");

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return -1;
	}

	Mat img_hsv;
	cvtColor(src, img_hsv, COLOR_BGR2HSV);

	vector<Mat> planes;
	split(img_hsv, planes);

	for (int k = 0; k < planes[0].rows; k++)
	{
		for (int i = 0; i < planes[0].cols; i++)
		{
			if (planes[0].at<uchar>(k, i) >= 5 && planes[0].at<uchar>(k, i) < 175)
			{
				planes[0].at<uchar>(k, i) = 0;
				planes[1].at<uchar>(k, i) = 0;
			}
		}
	}

	Mat dst;
	merge(planes, dst);
	cvtColor(dst, dst, COLOR_HSV2BGR);

	imshow("dst", dst);
	waitKey(0);

	return 0;
}