/*
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	VideoCapture capture("D:\\example\\dataset\\video\\Robin.avi");
	if (!capture.isOpened()) return -1;

	Size size = Size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(CAP_PROP_FRAME_HEIGHT));

	int frameNum = 0;
	int fps = (int)(capture.get(CAP_PROP_FPS));
	int delay = 1000 / fps;
	Mat frame, grayFrame;
	Mat sumImg(size, CV_32F, Scalar::all(0));

	while (true)
	{
		capture >> frame;
		if (frame.empty()) break;

		cvtColor(frame, grayFrame, COLOR_BGR2GRAY);
		accumulate(grayFrame, sumImg);
		imshow("frame", frame);
		frameNum++;

		int ckey = waitKey(delay);
		if (ckey == 27) break;
	}
	sumImg = sumImg / (float)frameNum;
	imwrite("D:\\example\\dataset\\BkgImage1.jpg", sumImg);

	return 0;
}
*/