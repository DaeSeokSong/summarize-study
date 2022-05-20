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
	int delay = 1000 / fps;
	Mat frame, grayFrame, diffImg;

	Mat bkgImg = imread("D:\\example\\dataset\\BkgImage1.jpg", IMREAD_GRAYSCALE);
	if (bkgImg.empty()) return -1;

	int nTh = 50;
	int frameNum = 0;

	while (true)
	{
		capture >> frame;
		if (frame.empty()) break;

		cvtColor(frame, grayFrame, COLOR_BGR2GRAY);
		GaussianBlur(grayFrame, grayFrame, Size(5, 5), 0.5);

		absdiff(grayFrame, bkgImg, diffImg);
		threshold(diffImg, diffImg, nTh, 255, THRESH_BINARY);

		frameNum++;
		imshow("grayFrame", grayFrame);
		imshow("diffImage", diffImg);

		int ckey = waitKey(delay);
		if (ckey == 27) break;
	}

	return 0;
}
*/