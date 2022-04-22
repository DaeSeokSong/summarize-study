/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

vector<vector<Point>> myFindContours(Mat& srcImg);
void onMouse(int event, int x, int y, int flags, void* param);

vector<Point> g_points;

int main()
{
	Mat refImg = imread("D:\\example\\dataset\\shapes\\templateShapes.png", IMREAD_GRAYSCALE);
	if (refImg.empty()) return -1;

	Scalar colorTable[] = { Scalar(0, 0, 255),
							Scalar(0, 255, 0),
							Scalar(255, 0, 0) };

	Mat dstImg(Size(512, 512), CV_8UC3, Scalar::all(255));
	imshow("dstImg", dstImg);
	setMouseCallback("dstImg", onMouse, (void*)&dstImg);

	vector<vector<Point>> refContours = myFindContours(refImg);
	if (refContours.size() < 1) return -1;

	Mat refRGB;
	cvtColor(refImg, refRGB, COLOR_GRAY2BGR);
	for (int k = 0; k < refContours.size(); k++) drawContours(refRGB, refContours, k, colorTable[k], 2);
	imshow("refRGB", refRGB);

	int npts;
	const Point* pts;
	vector<Point> approxCurve;

	int method = 3;
	int minK;
	double minD;

	bool bEscKey = false;
	while (!bEscKey)
	{
		int nKey = waitKey(0);
		switch (nKey)
		{
		case 27:
			bEscKey = true;
			break;
		case 'r':
			g_points.clear();
			dstImg = Scalar::all(255);
			break;
		case ' ':
			if (g_points.size() < 1) break;

			approxCurve = g_points;
			approxPolyDP(g_points, approxCurve, 10, true);

			// matches
			minD = matchShapes(refContours[0], approxCurve, method, 0);
			minK = 0;
			for (int k = 1; k < refContours.size(); k++)
			{
				double d = matchShapes(refContours[k], approxCurve, method, 0);
				if (d < minD)
				{
					minD = d;
					minK = k;
				}
			}

			pts = (const Point*)approxCurve.data();
			npts = approxCurve.size();
			polylines(dstImg, &pts, &npts, 1, true, colorTable[minK], 4);

			break;
		}
		imshow("dstImg", dstImg);
	}

	return 0;
}

vector<vector<Point>> myFindContours(Mat& srcImg)
{
	GaussianBlur(srcImg, srcImg, Size(3, 3), 0.0);

	Mat bImg;
	threshold(srcImg, bImg, 128, 255, THRESH_BINARY_INV + THRESH_OTSU);
	erode(bImg, bImg, Mat(), Point(-1, -1), 1);
	dilate(bImg, bImg, Mat(), Point(-1, -1), 2);

	vector<vector<Point>> contours;
	findContours(bImg, contours, noArray(), RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	return contours;
}

void onMouse(int event, int x, int y, int flags, void* param)
{
	Mat* data = (Mat*)param;
	Mat dstImg = *data;
	switch (event)
	{
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON)
		{
			circle(dstImg, Point(x, y), 4, Scalar::all(0), -1);
			g_points.push_back(Point(x, y));
		}
		break;
	}
	imshow("dstImg", dstImg);
}
*/