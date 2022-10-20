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
	Mat frame, grayFrame;

	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));

	float alpha = 0.02;
	int nTh = 50;
	int frameNum = -1;
	Mat avgImg, diffImg, mask;

	while (true)
	{
		capture >> frame;
		if (frame.empty()) break;

		frameNum++;

		cvtColor(frame, grayFrame, COLOR_BGR2GRAY);
		GaussianBlur(grayFrame, grayFrame, Size(5, 5), 0.5);
		if (frameNum == 0)
		{
			avgImg = grayFrame;
			continue;
		}

		avgImg.convertTo(avgImg, CV_32F);
		grayFrame.convertTo(grayFrame, CV_32F);
		absdiff(grayFrame, avgImg, diffImg);
		threshold(diffImg, mask, nTh, 255, THRESH_BINARY);
		mask.convertTo(mask, CV_8U);

		erode(mask, mask, kernel, Point(-1, -1), 2);
		dilate(mask, mask, kernel, Point(-1, -1), 3);
		imshow("mask", mask);

		bitwise_not(mask, mask);
		accumulateWeighted(grayFrame, avgImg, alpha, mask);

		avgImg.convertTo(avgImg, CV_8U);
		imshow("avgImg", avgImg);

		int ckey = waitKey(delay);
		if (ckey == 27) break;
	}

	return 0;
}
*/