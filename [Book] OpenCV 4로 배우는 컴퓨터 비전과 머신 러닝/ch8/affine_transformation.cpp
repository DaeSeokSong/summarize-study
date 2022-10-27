//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat src = imread("tekapo.bmp");
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return 0;
//	}
//
//	// Scale down, translation matrix
//	float data[] = { 0.5f, 0.f, 50.f, 0.1f, 0.7f, 50.1f };
//	Mat M(2, 3, CV_32F, data);
//	cout << "M = " << endl;
//	cout << M << endl;
//
//	Mat dst1;
//	warpAffine(src, dst1, M, Size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(50, 50, 100));
//
//	vector<Point2f> sP = { Point2f(10, 10), Point2f(30, 70), Point2f(100, 80) };
//	vector<Point2f> tP;
//	transform(sP, tP, M); // trasformation matrix(M) 알고 있을 때 tP 결정
//	
//	Mat cM = getAffineTransform(sP, tP);
//	cout << "cM = " << endl;
//	cout << cM << endl;
//
//	Mat dst2;
//	warpAffine(src, dst2, cM, Size());
//
//	imshow("dst1", dst1);
//	imshow("dst2", dst2);
//	waitKey(0);
//
//	return 0;
//}