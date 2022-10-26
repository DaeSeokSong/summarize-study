//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//void on_brightness(int pos, void* userdata);
//
//int main()
//{
//	Mat src = imread("lena.jpg", IMREAD_GRAYSCALE);
//
//	if (src.empty())
//	{
//		cerr << "Image load fail" << endl;
//		return -1;
//	}
//
//	namedWindow("dst [17019040 송대석]");
//	createTrackbar("Brightness", "dst [17019040 송대석]", 0, 100, on_brightness, (void*)&src);
//	on_brightness(0, (void*)&src);
//
//	waitKey(0);
//
//	return 0;
//}
//
//void on_brightness(int pos, void* userdata)
//{
//	Mat src = *(Mat*)userdata;
//	Mat dst(src.rows, src.cols, src.type());
//
//	for (int k = 0; k < src.rows; k++)
//	{
//		for (int i = 0; i < src.cols; i++)
//		{
//			dst.at<uchar>(k, i) = saturate_cast<uchar>(src.at<uchar>(k, i) + pos);
//		}
//	}
//
//	imshow("dst [17019040 송대석]", dst);
//}