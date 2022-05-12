/*
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg(512, 512, CV_8UC3, Scalar::all(255));
	Mat srcImg2(srcImg.size(), srcImg.type());
	Mat dstImg(srcImg.size(), srcImg.type());
	Size dsize = dstImg.size();
	Point2f center(dsize.width / 2, dsize.height / 2);

	circle(srcImg, center, 50, Scalar(255, 0, 0), 2);
	circle(srcImg, center, 100, Scalar(0, 255, 0), 2);
	circle(srcImg, center, 200, Scalar(0, 0, 255), 2);

	circle(srcImg, Point(center.x + 50, center.y), 5, Scalar(0, 0, 0), -1);
	circle(srcImg, Point(center.x - 50, center.y), 5, Scalar(127, 255, 0), -1);
	circle(srcImg, Point(center.x, center.y + 50), 5, Scalar(0, 127, 255), -1);
	circle(srcImg, Point(center.x, center.y - 50), 5, Scalar(0, 255, 255), -1);

	circle(srcImg, Point(center.x + 100, center.y), 10, Scalar(0, 0, 0), -1);
	circle(srcImg, Point(center.x - 100, center.y), 10, Scalar(127, 255, 0), -1);
	circle(srcImg, Point(center.x, center.y + 100), 10, Scalar(0, 127, 255), -1);
	circle(srcImg, Point(center.x, center.y - 100), 10, Scalar(0, 255, 255), -1);

	circle(srcImg, Point(center.x + 200, center.y), 20, Scalar(0, 0, 0), -1);
	circle(srcImg, Point(center.x - 200, center.y), 20, Scalar(127, 255, 0), -1);
	circle(srcImg, Point(center.x, center.y + 200), 20, Scalar(0, 127, 255), -1);
	circle(srcImg, Point(center.x, center.y - 200), 20, Scalar(0, 255, 255), -1);

	double maxR = sqrt(center.x * center.x + center.y * center.y);
	float M = dsize.width / log(maxR);

	logPolar(srcImg, dstImg, center, M, INTER_CUBIC);
	logPolar(dstImg, srcImg2, center, M, INTER_CUBIC + WARP_INVERSE_MAP);

	imshow("srcImg", srcImg);
	imshow("srcImg2", srcImg2);
	imshow("dstImg", dstImg);
	waitKey(0);
	return 0;
}
*/