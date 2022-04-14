/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void floodFillPostprocess(Mat& img, const Scalar& colorDiff);

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png");
	if (srcImg.empty()) return -1;

	int maxLevel = 4;
	double sp = 10, sr = 40;

	Mat dstImg1;
	Mat dstImg2;
	pyrMeanShiftFiltering(srcImg, dstImg1, sp, sr, maxLevel);
	dstImg2 = dstImg1.clone();
	floodFillPostprocess(dstImg2, Scalar::all(2));

	imshow("srcImg", srcImg);
	imshow("dstImg1", dstImg1);
	imshow("dstImg2", dstImg2);

	waitKey(0);
	return 0;
}

void floodFillPostprocess(Mat& img, const Scalar& colorDiff)
{
	RNG rng = theRNG();
	Mat mask(img.rows + 2, img.cols + 2, CV_8U, Scalar::all(0));

	for (int y = 0; y < img.rows; y++)
	{
		for (int x = 0; x < img.cols; x++)
		{
			Scalar newVal(rng(256), rng(256), rng(256));
			floodFill(img, mask, Point(x, y), newVal, 0, colorDiff, colorDiff);
		}
	}
}
*/