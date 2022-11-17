#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("kmap_simple.jpg", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return -1;
	}

	Mat bin;
	threshold(src, bin, 128, 255, THRESH_BINARY_INV | THRESH_OTSU);

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(bin, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

	Mat dst, contour_dst, approx_dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);
	cvtColor(src, contour_dst, COLOR_GRAY2BGR);
	cvtColor(src, approx_dst, COLOR_GRAY2BGR);
	for (int idx = 0; idx >= 0; idx = hierarchy[idx][0])
	{
		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst, contours, idx, color, 2, LINE_AA, hierarchy, 2, Point(0, 0));
		drawContours(contour_dst, contours, idx, color, 2, LINE_AA, hierarchy, 2, Point(0, 0));

		vector<Point> approxCurve;
		approxPolyDP(contours[idx], approxCurve, arcLength(contours[idx], true) * 0.005, true);

		int num_vertex = approxCurve.size();
		cout << "num of vertex: " << num_vertex << endl;

		for (int v = 0; v < num_vertex; v++)
		{
			circle(dst, approxCurve[v], 3, Scalar(0, 0, 255), 2);
			line(dst, approxCurve[v], approxCurve[(v + 1) % num_vertex], Scalar(255, 255, 0), 2);

			circle(approx_dst, approxCurve[v], 3, Scalar(0, 0, 255), 2);
			line(approx_dst, approxCurve[v], approxCurve[(v + 1) % num_vertex], Scalar(255, 255, 0), 2);
		}
	}
	resize(contour_dst, contour_dst, contour_dst.size() / 2);
	resize(approx_dst, approx_dst, approx_dst.size() / 2);

	imshow("src", src);
	imshow("dst", dst);
	imshow("contour_dst", contour_dst);
	imshow("approx_dst", approx_dst);

	waitKey(0);

	return 0;
}