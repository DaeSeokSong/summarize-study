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
			case 27 :
				bEscKey = true;
				break;
			case 'r' :
				g_points.clear();
				dstImg = Scalar::all(255);
				break;
			case ' ' :
				if (g_points.size() < 1) break;

				const Point* pts = (const Point*)g_points.data();

				int npts = g_points.size();
				polylines(dstImg, &pts, &npts, 1, closed, Scalar(255, 0, 0), 2);

				// arcLength
				// 곡선 또는 윤곽선의 길이를 계산한다.
				double length = arcLength(g_points, closed);
				cout << "arcLength = " << length << endl;

				// contourArea
				// 윤곽선 내부의 면적을 계산한다.
				double area = contourArea(g_points, true);
				cout << "contourArea = " << area << endl;

				// boundingRect
				// 주어진 좌표점들의 바운딩 직사각형을 계산해 반환한다.
				Rect rect = boundingRect(g_points);
				rectangle(dstImg, rect, Scalar(0, 0, 255), 2);

				// minEnclosingCircle
				// 주어진 좌표들을 둘러싸는 면적이 최소인 원을 중심점 center, 반지름 radius로 반환한다.
				Point2f center;
				float radius;
				minEnclosingCircle(g_points, center, radius);
				circle(dstImg, center, radius, Scalar(0, 255, 0), 2);

				// minAreaRect
				// 주어진 좌표들을 둘러싸는 면적이 최소인 회전이 고려된 사각형을 반환한다.
				RotatedRect minRect = minAreaRect(g_points);
				Point2f rectPoints[4];
				minRect.points(rectPoints);
				for (int i = 0; i < 4; i++) line(dstImg, rectPoints[i], rectPoints[(i + 1) % 4], Scalar(255, 0, 255), 2);

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
		case EVENT_MOUSEMOVE :
			if (flags & EVENT_FLAG_LBUTTON)
			{
				circle(dstImg, Point(x, y), 2, Scalar::all(0), -1);
				g_points.push_back(Point(x, y));
			}
			break;
	}
	imshow("dstImg", dstImg);
}
*/