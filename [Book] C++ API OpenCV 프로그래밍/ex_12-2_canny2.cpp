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

	int fps = (int)(capture.get(CAP_PROP_FPS));

	int delay = 30;
	int frameNum = -1;
	Mat frame, grayImage, edgeImage;

	while (true)
	{
		capture >> frame;
		if (frame.empty()) break;

		cvtColor(frame, grayImage, COLOR_BGR2GRAY);
		Canny(grayImage, edgeImage, 80, 150);

		imshow("frame", frame);
		imshow("edgeImage", edgeImage);

		int ckey = waitKey(delay);
		if (ckey == 27) break;
	}

	return 0;
}
*/