//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	//// 6-1
//	//Mat src1 = imread("lena.jpg", IMREAD_GRAYSCALE);
//	//Mat src2 = imread("square.bmp", IMREAD_GRAYSCALE);
//
//	//if (src1.empty() || src2.empty())
//	//{
//	//	cerr << "Image load fail" << endl;
//	//	return -1;
//	//}
//	//resize(src1, src1, Size(256, 256));
//
//	//imshow("src1", src1);
//	//imshow("src2", src2);
//
//	//Mat dst1, dst2, dst3, dst4;
//
//	//add(src1, src2, dst1);
//	//addWeighted(src1, 0.5, src2, 0.5, 0, dst2);
//	//subtract(src1, src2, dst3);
//	//absdiff(src1, src2, dst4);
//
//	//imshow("dst1", dst1);
//	//imshow("dst2", dst2);
//	//imshow("dst3", dst3);
//	//imshow("dst4", dst4);
//
//	//waitKey(0);
//
//
//
//	// 6-2
//	Mat src1 = imread("lena.jpg", IMREAD_GRAYSCALE);
//	Mat src2 = imread("square.bmp", IMREAD_GRAYSCALE);
//
//	if (src1.empty() || src2.empty())
//	{
//		cerr << "Image load fail" << endl;
//		return -1;
//	}
//	resize(src1, src1, Size(256, 256));
//
//	imshow("src1", src1);
//	imshow("src2", src2);
//
//	Mat dst1, dst2, dst3, dst4;
//
//	bitwise_and(src1, src2, dst1);
//	bitwise_or(src1, src2, dst2);
//	bitwise_xor(src1, src2, dst3);
//	bitwise_not(src1, dst4);
//
//	imshow("dst1", dst1);
//	imshow("dst2", dst2);
//	imshow("dst3", dst3);
//	imshow("dst4", dst4);
//
//	waitKey(0);
//
//	return 0;
//}