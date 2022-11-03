#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat img, img_ycrcb, mask;
	img = imread("ref.png");
	mask = imread("mask.bmp", IMREAD_GRAYSCALE);
	cvtColor(img, img_ycrcb, COLOR_BGR2YCrCb);

	if (img.empty() || mask.empty())
	{
		cerr << "Image load failed" << endl;
		return -1;
	}

	Mat hist;
	int chs[] = { 1, 2 };
	int histSize[] = { 128, 128 };
	float cr_range[] = { 0, 256 };
	float cb_range[] = { 0, 256 };
	const float* ranges[] = { cr_range, cb_range };

	calcHist(&img_ycrcb, 1, chs, mask, hist, 2, histSize, ranges);

	img = imread("kids.png");
	cvtColor(img, img_ycrcb, COLOR_BGR2YCrCb);
	Mat backproj;
	calcBackProject(&img_ycrcb, 1, chs, hist, backproj, ranges, 1, true);

	imshow("input image", img);
	imshow("backproject image", backproj);

	waitKey(0);

	return 0;
}