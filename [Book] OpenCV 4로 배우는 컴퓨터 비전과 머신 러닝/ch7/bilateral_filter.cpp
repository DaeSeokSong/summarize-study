//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	VideoCapture cap;
//	cap.open(0);
//
//	if (!cap.isOpened())
//	{
//		cout << "Web cam open FAIL" << endl;
//		return -1;
//	}
//	int cap_w = cap.get(CAP_PROP_FRAME_WIDTH);
//	int cap_h = cap.get(CAP_PROP_FRAME_HEIGHT);
//
//	Mat noise(Size(cap_w, cap_h), CV_32FC1);
//	randn(noise, 0, 10);
//
//	Mat frame, grayF, GaussF, bilaterF;
//	while (true)
//	{
//		cap >> frame;
//		if (frame.empty()) break;
//
//		cvtColor(frame, grayF, COLOR_BGR2GRAY);
//
//		add(grayF, noise, grayF, Mat(), CV_8U);
//
//		GaussianBlur(grayF, GaussF, Size(), 10);
//		bilateralFilter(grayF, bilaterF, -1, 15, 10);
//
//		imshow("frame", grayF);
//		imshow("GaussianBlur", GaussF);
//		imshow("bilateralFilter", bilaterF);
//
//		int input_key = waitKey(1);
//		if (input_key == 'c')
//		{
//			imwrite("frame_17019040.jpg", grayF);
//			imwrite("gaussianblur_frame_17019040.jpg", GaussF);
//			imwrite("bilateral_filter_frame_17019040.jpg", bilaterF);
//		}
//		else if (input_key == 27) break;
//	}
//
//	return 0;
//}