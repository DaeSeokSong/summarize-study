#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("circuit.bmp");
	Mat templ = imread("crystal.bmp");

	if (img.empty() || templ.empty())
	{
		cerr << "Image load failed" << endl;
		return -1;
	}

	img = img + Scalar(50, 50, 50);

	Mat noise(img.size(), CV_32SC3);
	randn(noise, 0, 10);
	add(img, noise, img, Mat(), CV_8UC3);

	Mat res, res_norm;
	matchTemplate(img, templ, res, TM_CCOEFF_NORMED);
	normalize(res, res_norm, 0, 255, NORM_MINMAX, CV_8U);

	double maxv;
	Point maxLoc;
	minMaxLoc(res, 0, &maxv, 0, &maxLoc);
	cout << "maxv: " << maxv << endl;
	rectangle(img, Rect(maxLoc.x, maxLoc.y, templ.cols, templ.rows), Scalar(0, 0, 255), 2);

	imshow("templ", templ);
	imshow("res_norm", res_norm);
	imshow("img", img);

	waitKey(0);

	return 0;
}