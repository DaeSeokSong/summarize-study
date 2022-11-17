#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void labeling_basic();
void contours_basic();
void contours_hier();
void contour_apps();

void contourPolygons();
void setLabel(Mat& img, const vector<Point>& pts, const String& label);

int main()
{
	//// Ex1
	//labeling_basic();

	//// Ex2
	//contours_basic();

	//// Ex3
	//contours_hier();

	//// Ex4
	//contour_apps();

	// Ex5
	contourPolygons();

	return 0;
}

void labeling_basic()
{
	uchar data[] = {
		0, 0, 1, 1, 0, 0 ,0 ,0,
		1, 1, 1, 1, 0, 0, 1, 0,
		1, 1, 1, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 1, 0,
		0, 0, 0, 1, 1, 1, 1, 0,
		0, 0, 0, 1, 0, 0, 1, 0,
		0, 0, 1, 1, 1, 1, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};

	Mat src = Mat(8, 8, CV_8UC1, data) * 255;

	Mat labels;
	int cnt = connectedComponents(src, labels);

	cout << "src:\n" << src << endl;
	cout << "labels:\n " << labels << endl;
	cout << "num of labels: " << cnt << endl;
}

void contours_basic()
{
	Mat src = imread("contours.bmp", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return;
	}

	vector<vector<Point>> contours;
	findContours(src, contours, RETR_LIST, CHAIN_APPROX_NONE);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst, contours, i, color, 2);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
}

void contours_hier()
{
	Mat src = imread("contours.bmp", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return;
	}

	vector<vector<Point>> contours_ccomp, contours_tree;
	vector<Vec4i> hierarchy_ccomp, hierarchy_tree;
	findContours(src, contours_ccomp, hierarchy_ccomp, RETR_CCOMP, CHAIN_APPROX_NONE);
	findContours(src, contours_tree, hierarchy_tree, RETR_TREE, CHAIN_APPROX_NONE);

	Mat dst_ccomp, dst_tree;
	cvtColor(src, dst_ccomp, COLOR_GRAY2BGR);
	cvtColor(src, dst_tree, COLOR_GRAY2BGR);
	for (int idx = 0; idx >= 0; idx = hierarchy_ccomp[idx][0])
	{
		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst_ccomp, contours_ccomp, idx, color, -1, LINE_8, hierarchy_ccomp);
	}
	for (int idx = 0; idx >= 0; idx = hierarchy_tree[idx][0])
	{
		Scalar color(rand() & 255, rand() & 255, rand() & 255);
		drawContours(dst_tree, contours_tree, idx, color, -1, LINE_8, hierarchy_tree);
	}

	imshow("src", src);
	imshow("dst_ccomp", dst_ccomp);
	imshow("dst_tree", dst_tree);

	waitKey(0);
}

void contour_apps()
{
	Mat src = imread("beta.png", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return;
	}

	Mat bin;
	threshold(src, bin, 128, 255, THRESH_BINARY | THRESH_OTSU);
	morphologyEx(bin, bin, MORPH_OPEN, Mat());

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(bin, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (int idx = 0; idx >= 0; idx = hierarchy[idx][0])
	{
		Scalar color(rand() & 255, rand() & 255, rand() & 255);

		drawContours(dst, contours, idx, color, 2, LINE_AA, hierarchy, 2, Point(0, 0));

		Rect rect = boundingRect(contours[idx]);
		rectangle(dst, rect, Scalar(0, 0, 255), 2, LINE_AA, 0);

		RotatedRect rrect = minAreaRect(contours[idx]);
		Point2f vectices[4];
		for (int i = 0; i < 4; i++)
		{
			line(dst, vectices[i], vectices[(i + 1) % 4], Scalar(255, 0, 0), 2, LINE_AA, 0);
		}
		float angle = rrect.angle;
		cout << "\nrotated angle: " << cvRound(angle) << endl;

		Point2f center;
		float radius;
		minEnclosingCircle(contours[idx], center, radius);
		circle(dst, center, radius, Scalar(0, 255, 255), 2, LINE_AA, 0);

		double len = arcLength(contours[idx], true);
		cout << "\nlen of contour: " << cvRound(len) << endl;

		double area = contourArea(contours[idx], false);
		cout << "\narea of contour: " << cvRound(area) << endl;
	}

	imshow("dst", dst);
	
	waitKey(0);
}

void setLabel(Mat& img, const vector<Point>& pts, const String& label)
{
	Rect rc = boundingRect(pts);
	rectangle(img, rc, Scalar(0, 0, 255), 1);
	putText(img, label, rc.tl(), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
}

void contourPolygons()
{
	Mat src = imread("polygon.bmp");

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return;
	}

	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);

	Mat bin;
	threshold(gray, bin, 200, 255, THRESH_BINARY_INV | THRESH_OTSU);

	vector<vector<Point>> contours;
	findContours(bin, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	for (vector<Point>& pts : contours)
	{
		if (contourArea(pts) < 400) continue;

		vector<Point> approx;
		approxPolyDP(pts, approx, arcLength(pts, true) * 0.02, true);

		int vtc = (int)approx.size();

		if (vtc == 3) setLabel(src, pts, "TRI");
		else if(vtc == 4) setLabel(src, pts, "RECT");
		else if (vtc > 4)
		{
			double len = arcLength(pts, true);
			double area = contourArea(pts);
			double ratio = 4. * CV_PI * area / (len * len);

			if (ratio > 0.8) setLabel(src, pts, "CIR");
		}
	}

	imshow("src", src);

	waitKey(0);
}