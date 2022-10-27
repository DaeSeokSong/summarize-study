//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat src = imread("building.jpg", IMREAD_GRAYSCALE);
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return 0;
//	}
//
//	Mat edge;
//	Canny(src, edge, 50, 150);
//
//	vector<Vec2f> lines;
//	HoughLines(edge, lines, 1, CV_PI / 180, 250);
//
//	Mat dst;
//	cvtColor(edge, dst, COLOR_GRAY2BGR);
//
//	for (size_t i = 0; i < lines.size(); i++)
//	{
//		float r = lines[i][0];
//		float t = lines[i][1];
//
//		double cos_t = cos(t);
//		double sin_t = sin(t);
//
//		double x0 = r * cos_t;
//		double y0 = r * sin_t;
//
//		double alpha = 1000;
//
//		Point pt1(cvRound(x0 + alpha * (-sin_t)), cvRound(y0 + alpha * cos_t));
//		Point pt2(cvRound(x0 - alpha * (-sin_t)), cvRound(y0 - alpha * cos_t));
//		line(dst, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);
//	}
//
//	imshow("src", src);
//	imshow("dst", dst);
//
//	waitKey(0);
//
//	return 0;
//}