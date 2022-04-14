/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int flags, void* param);

vector<Point> g_points;

class ClosePoints
{
	private :
		int minDist_;

	public:
		ClosePoints(int minDist) : minDist_(minDist) {}

		bool operator() (const Point& p1, const Point& p2) const
		{
			int dist2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
			return dist2 < (minDist_* minDist_);
		}
};

int main()
{
	Mat dstImg(512, 512, CV_8UC3, Scalar::all(255));
	imshow("dstImg", dstImg);

	setMouseCallback("dstImg", onMouse, (void*)&dstImg);

	bool bEscKey = false;
	int nKey;
	while (!bEscKey)
	{
		nKey = waitKey(0);
		switch (nKey)
		{
		case 27:
			bEscKey = true;
			break;
		case 'r':
			g_points.clear();
			dstImg = Scalar::all(255);
			imshow("dstImg", dstImg);
			break;
		case ' ':
			if (g_points.size() < 1) break;

			vector<int> labels;
			int K = partition(g_points, labels, ClosePoints(100));

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

			// display clusters
			for (int i = 0; i < g_points.size(); i++)
			{
				int k = labels[i];
				Point pt = g_points[i];
				color = colorTable.at<Vec3b>(k, 0);
				circle(dstImg, pt, 10, Scalar(color), -1);
			}
			imshow("dstImg", dstImg);
			break;
		}
	}

	return 0;
}

void onMouse(int event, int x, int y, int flags, void* param)
{
	Mat* data = (Mat*)param;
	Mat dstImg = *data;
	switch (event)
	{
	case EVENT_FLAG_LBUTTON:
		circle(dstImg, Point(x, y), 10, Scalar::all(0), -1);
		g_points.push_back(Point(x, y));
		break;
	}
	imshow("dstImg", dstImg);
}
*/