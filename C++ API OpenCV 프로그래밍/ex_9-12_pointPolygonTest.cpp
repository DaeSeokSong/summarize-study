/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int flags, void* param);

vector<Point> g_points;

int main()
{
	Mat dstImg(Size(512, 512), CV_8UC3, Scalar::all(255));
	imshow("dstImg", dstImg);
	setMouseCallback("dstImg", onMouse, (void*)&dstImg);

	bool closed = false;
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
		}
		imshow("dstImg", dstImg);
	}
	return 0;
}

void onMouse(int event, int x, int y, int flags, void* param)
{
	Mat* data = (Mat*)param;
	Mat dstImg = *data;

	int npts;
	const Point* pts;
	double dist;
	switch (event)
	{
		case EVENT_MOUSEMOVE:
			if (flags & EVENT_FLAG_LBUTTON)
			{
				circle(dstImg, Point(x, y), 4, Scalar::all(0), -1);
				g_points.push_back(Point(x, y));
			}
			break;
		case EVENT_FLAG_RBUTTON:
			dstImg = Scalar::all(255);
			circle(dstImg, Point(x, y), 4, Scalar::all(0), -1);

			npts = g_points.size();
			pts = (Point*)g_points.data();
			polylines(dstImg, &pts, &npts, 1, true, Scalar(255, 0, 0), 2);

			// pointPolygonTest
			// 좌표가 윤곽선에 의해 주어지는 다각형 안에 있는지 검사한다.
			dist = pointPolygonTest(g_points, Point(x, y), true);
			cout << "dist = " << dist << endl;

			if (dist > 0) circle(dstImg, Point(x, y), 5, Scalar(0, 255, 0), 4); // inside
			else if (dist < 0) circle(dstImg, Point(x, y), 5, Scalar(0, 0, 255), 4); // outside
			else circle(dstImg, Point(x, y), 5, Scalar(255, 255, 0), 4); // onside, on the line(contour)

			break;
	}
	imshow("dstImg", dstImg);
}
*/