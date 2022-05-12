/*
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat dstImg(srcImg.size(), srcImg.type());

	Size dsize = dstImg.size();
	Point2f center(dsize.width / 2, dsize.height / 2);

	float maxR = sqrt(center.x * center.x + center.y * center.y);
	float M = dsize.width / log(maxR);

	Mat mapX(dsize, CV_32FC1);
	Mat mapY(dsize, CV_32FC1);

	for (int phi = 0; phi < dsize.height; phi++)
	{
		for (int rho = 0; rho < dsize.width; rho++)
		{
			float cp = cos(phi * 2 * CV_PI / dsize.height);
			float sp = sin(phi * 2 * CV_PI / dsize.height);
			float r = exp(rho / M);
			float x = r * cp + center.x;
			float y = r * sp + center.y;

			mapX.at<float>(phi, rho) = x;
			mapY.at<float>(phi, rho) = y;
		}
	}

	remap(srcImg, dstImg, mapX, mapY, INTER_LINEAR);

	imshow("srcImg", srcImg);
	imshow("dstImg", dstImg);
	waitKey(0);
	return 0;
}
*/