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

	int npts;
	const Point* pts;
	Point ptStart, ptEnd;
	float s = 1000;
	int distType = DIST_L2;
	Vec4f lineFit;

	vector<Point> approxCurve;
	double epsilon = 50;

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
			case '1':
				if (g_points.size() < 1) break;

				dstImg = Scalar::all(255);
				npts = g_points.size();
				pts = (Point*)g_points.data();
				polylines(dstImg, &pts, &npts, 1, closed, Scalar(0, 255, 0), 2);

				// fitLine
				// 주어진 좌표들을 직선으로 근사시켜 저장한다. DIST_L2 일 때 직선 근사가 가장 빠르게 계산된다.
				fitLine(g_points, lineFit, distType, 0, 0.01, 0.01);
				ptStart.x = cvRound(s * lineFit[0] + lineFit[2]);
				ptStart.y = cvRound(s * lineFit[1] + lineFit[3]);
				ptEnd.x = cvRound(-s * lineFit[0] + lineFit[2]);
				ptEnd.y = cvRound(-s * lineFit[1] + lineFit[3]);
				line(dstImg, ptStart, ptEnd, Scalar(255, 0, 0), 2);

				break;
			case '2':
				if (g_points.size() < 1) break;

				dstImg = Scalar::all(255);
				npts = g_points.size();
				pts = (Point*)g_points.data();
				polylines(dstImg, &pts, &npts, 1, closed, Scalar(0, 255, 0), 2);

				// approxPolyDP
				// 주어진 다각형, 윤곽선, 경계선을 epsilon에 주어진 정확도로 근사시켜 입력보다 줄어든 좌표들을 저장한다.
				approxPolyDP(g_points, approxCurve, epsilon, closed);
				pts = (const Point*)approxCurve.data();
				npts = approxCurve.size();
				polylines(dstImg, &pts, &npts, 1, closed, Scalar(0, 0, 255), 2);

				break;
			case '3':
				if (g_points.size() < 1) break;

				dstImg = Scalar::all(255);
				npts = g_points.size();
				pts = (Point*)g_points.data();
				polylines(dstImg, &pts, &npts, 1, closed, Scalar(0, 255, 0), 2);

				// fitEllipse
				// 주어진 좌표들을 fitLine와 같은 기법으로 근사시킨 직선을 둘러싸면서,
				// 타원을 둘러싸는 회전이 고려된 사각형을 반환한다.
				RotatedRect rect;
				rect = fitEllipse(g_points);
				ellipse(dstImg, rect, Scalar(255, 0, 255), 2);

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