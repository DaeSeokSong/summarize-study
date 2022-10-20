/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png");
	if (srcImg.empty()) return -1;

	int K = 8;

	// make color tables for displaying objects
	Mat colorTable(K, 1, CV_8UC3);
	Vec3b color;
	for (int k = 0; k < K; k++)
	{
		color[0] = rand() & 180 + 50;
		color[1] = rand() & 180 + 50;
		color[2] = rand() & 180 + 50;
		colorTable.at<Vec3b>(k, 0) = color;
	}

	Mat dstImg(srcImg.size(), srcImg.type());

	int attempts = 1;
	int flags = KMEANS_RANDOM_CENTERS;
	TermCriteria criteria(TermCriteria::COUNT + TermCriteria::EPS, 10, 1.0);

	Mat samples = srcImg.reshape(3, srcImg.rows * srcImg.cols);
	samples.convertTo(samples, CV_32FC3);

	Mat labels;
	kmeans(samples, K, labels, criteria, attempts, flags);

	// display objects using markers
	for (int y = 0, k = 0; y < srcImg.cols; y++)
	{
		for (int x = 0; x < srcImg.rows; x++, k++)
		{
			int idx = labels.at<int>(k, 0);
			color = colorTable.at<Vec3b>(idx, 0);
			dstImg.at<Vec3b>(y, x) = color;
		}
	}

	imshow("dstImg", dstImg);
	waitKey(0);
	return 0;
}
*/