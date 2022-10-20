/*
#include <iostream>
#include "opencv2/opencv.hpp"

#define THRESHOLD 3

using namespace std;
using namespace cv;

void DrawOpticalFlow(Mat& flow, Mat& image)
{
	int x, y;

	Point p1, p2;
	Size size = image.size();
	Size shiftSize = Size(4, 4);

	for (y = 0; y < size.height; y += shiftSize.height)
	{
		for (x = 0; x < size.width; x += shiftSize.width)
		{
			Point2f delta = flow.at<Point2f>(y, x);
			float len = sqrt(delta.x * delta.x + delta.y * delta.y);
			if (len < THRESHOLD) continue;

			p1.x = x;
			p1.y = y;
			p2.x = cvRound(p1.x + delta.x);
			p2.y = cvRound(p1.y + delta.y);
			line(image, p1, p2, Scalar(255, 0, 0));
		}
	}
}

int main()
{
	VideoCapture capture("D:\\example\\dataset\\video\\handShaking.mp4");
	if (!capture.isOpened()) return -1;

	Size size = Size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(CAP_PROP_FRAME_HEIGHT));

	int fps = (int)(capture.get(CAP_PROP_FPS));
	if (fps == 0) fps = 24;

	int delay = 1000 / fps;
	Mat frame, dstImg;

	Mat curImg, prevImg;
	Mat flow;

	int fourcc = VideoWriter::fourcc('d', 'i', 'v', 'x');
	bool isColor = true;
	VideoWriter outputVideo("D:\\example\\dataset\\video\\trackingFlow.mp4", fourcc, fps, size, isColor);
	if (!outputVideo.isOpened()) return -1;
	if (fourcc != -1)
	{
		imshow("dstImg", NULL);
		waitKey(100);
	}

	int frameNum = -1;
	double pyr_scale = 0.5;
	int levels = 3;
	int winsize = 11;
	int iterations = 5;
	int poly_n = 5;
	double poly_sigma = 1.1;
	int flags = 0;

	while (true)
	{
		capture >> frame;
		if (frame.empty()) break;

		frameNum++;

		pyrDown(frame, dstImg);
		cvtColor(dstImg, curImg, COLOR_BGR2GRAY);
		if (frameNum < 1)
		{
			curImg.copyTo(prevImg);
			continue;
		}
		if (frameNum > 1)
		{
			flags = OPTFLOW_USE_INITIAL_FLOW;
		}

		calcOpticalFlowFarneback(prevImg, curImg, flow,
			pyr_scale, levels, winsize, iterations, poly_n, poly_sigma, flags);
		DrawOpticalFlow(flow, dstImg);

		outputVideo << dstImg;
		imshow("dstImg", dstImg);

		curImg.copyTo(prevImg);

		int ckey = waitKey(delay);
		if (ckey == 27) break;
	}

	return 0;
}
*/