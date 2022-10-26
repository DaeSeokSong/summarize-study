//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat mask = imread("mask_smile.bmp", IMREAD_GRAYSCALE);
//
//	if (mask.empty())
//	{
//		cerr << "Mask image load failed" << endl;
//		return -1;
//	}
//
//	VideoCapture cap;
//	cap.open(0);
//
//	if (!cap.isOpened())
//	{
//		cout << "Web cam open FAIL" << endl;
//	}
//
//	int cap_w = cap.get(CAP_PROP_FRAME_WIDTH);
//	int cap_h = cap.get(CAP_PROP_FRAME_HEIGHT);
//	cout << "Frame width = " << cvRound(cap_w) << endl;
//	cout << "Frame height = " << cvRound(cap_h) << endl;
//
//	Mat resizedMask;
//	resize(mask, resizedMask, Size(cap_w, cap_h));
//
//	Mat frame, maskedF;
//	while (true)
//	{
//		cap >> frame;
//		if (frame.empty()) break;
//
//		frame.copyTo(maskedF);
//
//		maskedF.setTo(Scalar(0, 255, 255), resizedMask);
//
//		imshow("Frame [1719040 송대석]", frame);
//		imshow("Masked Frame [1719040 송대석]", maskedF);
//
//		int input_key = waitKey(1);
//		
//		if (input_key == 'c') imwrite("masked_frame_17019040.jpg", maskedF);
//		else if (input_key == 27) break;
//	}
//
//	return 0;
//}