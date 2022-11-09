//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat src = imread("milkdrop.bmp", IMREAD_GRAYSCALE);
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return -1;
//	}
//
//	Mat img_bin;
//	threshold(src, img_bin, 0, 255, THRESH_BINARY | THRESH_OTSU);
//
//	// 7x7 크기의 십자가 모양(cross) 구조 요소
//	Mat crossK = getStructuringElement(MORPH_CROSS, Size(7, 7));
//	// 3x5 크기의 타원(ellipse) 모양의 구조 요소
//	Mat ellipseK = getStructuringElement(MORPH_ELLIPSE, Size(3, 5));
//
//	Mat bin_erd, bin_dila;
//	erode(img_bin, bin_erd, crossK);
//	dilate(img_bin, bin_dila, ellipseK);
//
//	imshow("src", src);
//	imshow("img_bin", img_bin);
//	imshow("img_bin_erd", bin_erd);
//	imshow("img_bin_dila", bin_dila);
//
//	waitKey(0);
//
//	return 0;
//}