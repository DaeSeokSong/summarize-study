//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	VideoCapture cap("stopwatch.avi");
//
//	if (!cap.isOpened())
//	{
//		cout << "Video open FAIL" << endl;
//		return 0;
//	}
//
//	cout << "Frame width = " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
//	cout << "Frame height = " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
//	cout << "Frame count = " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;
//
//	double fps = cap.get(CAP_PROP_FPS);
//	cout << "FPS = " << fps << endl;
//
//	int delay = cvRound(1000 / fps);
//
//	Mat frame, inversed;
//	while (true)
//	{
//		cap >> frame;
//		if (frame.empty()) break;
//
//		inversed = ~frame;
//
//		imshow("Frame [17019040 송대석]", frame);
//		imshow("Inversed [17019040 송대석]", inversed);
//
//		if (cv::waitKey(delay) == 27) break;
//	}
//
//	return 0;
//}