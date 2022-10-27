//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//void unsharp_mask();
//
//int main()
//{
//	unsharp_mask();
//
//	return 0;
//}
//
//void unsharp_mask()
//{
//	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//	imshow("src", src);
//
//	for (int sigma = 1; sigma < 6; sigma++)
//	{
//		Mat blurred, blurred_33, blurred_99, blurred_1515;
//		GaussianBlur(src, blurred, Size(), sigma);
//		GaussianBlur(src, blurred_33, Size(3, 3), sigma);
//		GaussianBlur(src, blurred_99, Size(9, 9), sigma);
//		GaussianBlur(src, blurred_1515, Size(15, 15), sigma);
//
//		float alpha = 1.f;
//		Mat dst = (1 + alpha) * src - alpha * blurred;
//		Mat dst2 = (1 + alpha) * src - alpha * blurred_33;
//		Mat dst3 = (1 + alpha) * src - alpha * blurred_99;
//		Mat dst4 = (1 + alpha) * src - alpha * blurred_1515;
//
//		String desc = format("sigma: %d", sigma);
//		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
//
//		imshow("dst[sigma = " + to_string(sigma) + "], 17019040 송대석", dst);
//		imshow("dst[sigma = " + to_string(sigma) + "], k = 3, 17019040 송대석", dst2);
//		imshow("dst[sigma = " + to_string(sigma) + "], k = 9, 17019040 송대석", dst3);
//		imshow("dst[sigma = " + to_string(sigma) + "], k = 15, 17019040 송대석", dst4);
//		waitKey(0);
//	}
//}