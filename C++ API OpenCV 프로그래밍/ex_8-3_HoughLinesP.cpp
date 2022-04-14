/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 허프 변환(Hough transform)
// 에지에서 직선 또는 원의 방적식의 파라미터를 검출할 수 있다.
int main() {
	Mat srcImg = imread("D:\\example\\dataset\\line.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat edges;
	Canny(srcImg, edges, 50, 127);
	imshow("edges", edges);

	vector<Vec4i> lines;
	HoughLinesP(edges, lines, 1, CV_PI / 180.0, 10, 30, 10);

	Mat dstImg(srcImg.size(), CV_8UC3);
	cvtColor(srcImg, dstImg, COLOR_GRAY2BGR);

	Vec4i params;
	int x1, y1, x2, y2;
	for (int k = 0; k < lines.size(); k++) {
		params = lines[k];

		x1 = params[0];
		y1 = params[1];
		x2 = params[2];
		y2 = params[3];

		Point pt1(x1, y1);
		Point pt2(x2, y2);

		line(dstImg, pt1, pt2, Scalar(0, 0, 255), 2);
	}

	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}
*/