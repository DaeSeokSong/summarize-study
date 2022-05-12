/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat dstImg(srcImg.size(), srcImg.type());

	Size dsize = dstImg.size();
	Point2f center(dsize.width / 2, dsize.height / 2);
	float R = dsize.width / 2.0;

	Mat mapX(dsize, CV_32FC1);
	Mat mapY(dsize, CV_32FC1);

	for (int i = 0; i < dsize.height; i++)
	{
		for (int k = 0; k < dsize.width; k++)
		{
			double x = i - center.x;
			double y = k - center.y;
			double r = sqrt(x * x + y * y);
			double theta = atan2(y, x);
			double len = min(fabs(center.x / cos(theta)), fabs(center.y / sin(theta)));

			r *= len / R;

			mapX.at<float>(k, i) = r * cos(theta) + center.x;
			mapY.at<float>(k, i) = r * sin(theta) + center.y;
		}
	}

	remap(srcImg, dstImg, mapX, mapY, INTER_LINEAR);

	imshow("srcImg", srcImg);
	imshow("dstImg", dstImg);
	waitKey(0);
	return 0;
}
*/