//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	VideoCapture cap(0);
//
//	if (!cap.isOpened())
//	{
//		cout << "Video open FAIL" << endl;
//		return 0;
//	}
//
//	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
//	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
//	double fps = cap.get(CAP_PROP_FPS);
//	
//	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
//	int delay = cvRound(1000 / fps);
//
//	VideoWriter outputVideo("SongDaeSeok.avi", fourcc, fps, Size(w, h));
//	VideoWriter inversedVideo("SongDaeSeok_inversed.avi", fourcc, fps, Size(w, h));
//
//	if (!outputVideo.isOpened() || !inversedVideo.isOpened())
//	{
//		cout << "File open Failed" << endl;
//		return 0;
//	}
//
//	Mat frame, inversed;
//	while (true)
//	{
//		cap >> frame;
//		if (frame.empty()) break;
//		else outputVideo << frame;
//
//		inversed = ~frame;
//		inversedVideo << inversed;
//
//		imshow("Frame", frame);
//		imshow("Inversed", inversed);
//
//		if (cv::waitKey(delay) == 27) break;
//	}
//
//	return 0;
//}