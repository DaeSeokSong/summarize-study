//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat img1 = imread("cat.bmp");
//	if (img1.empty())
//	{
//		cout << "Image load fail" << endl;
//		return -1;
//	}
//
//	Mat img2 = img1(Rect(220, 120, 340, 240));
//	Mat img3 = img1(Rect(220, 120, 340, 240)).clone();
//
//	img2 = ~img2;
//
//	imshow("img1 by 송대석", img1);
//	imshow("img2 by 송대석", img2);
//	imshow("img3 by 송대석", img3);
//	waitKey(0);
//
//	return 0;
//}