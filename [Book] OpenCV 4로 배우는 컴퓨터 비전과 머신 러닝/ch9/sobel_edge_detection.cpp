//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//void sobel_edge();
//
//int main()
//{
//	sobel_edge();
//
//	return 0;
//}
//
//void sobel_edge()
//{
//	Mat src = imread("lena.jpg", IMREAD_GRAYSCALE);
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	Mat dx, dy;
//	Sobel(src, dx, CV_32FC1, 1, 0);
//	Sobel(src, dy, CV_32FC1, 0, 1);
//	//Sobel(src, dx, CV_32FC1, 2, 0);
//	//Sobel(src, dy, CV_32FC1, 0, 2);
//	//Scharr(src, dx, CV_32FC1, 1, 0);
//	//Scharr(src, dy, CV_32FC1, 0, 1);
//
//	Mat fmag, mag;
//	magnitude(dx, dy, fmag);
//	fmag.convertTo(mag, CV_8UC1);
//
//	Mat edge;
//	threshold(mag, edge, 150, 255, THRESH_BINARY);
//	
//	Mat fangle, angle;
//	phase(dx, dy, fangle);
//	normalize(fangle, angle, 0, 255, NORM_MINMAX);
//	angle.convertTo(angle, CV_8UC1);
//
//	imshow("src", src);
//	imshow("mag", mag);
//	imshow("edge", edge);
//	imshow("angle", angle);
//
//	waitKey(0);
//}