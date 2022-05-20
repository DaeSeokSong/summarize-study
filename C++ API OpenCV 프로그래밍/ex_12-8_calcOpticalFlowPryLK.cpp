/*
#include <iostream>
#include "opencv2/opencv.hpp"

#define MAX_POINTS 16

using namespace std;
using namespace cv;

Point g_pt1, g_pt2;
bool g_bLeftDownAndMove = false;
bool g_bROI = false;

void onMouse(int mevent, int x, int y, int flags, void* param)
{
	switch (mevent)
	{
		case EVENT_LBUTTONDOWN:
			g_bLeftDownAndMove = false;
			g_pt1 = Point(x, y);
			break;
		case EVENT_MOUSEMOVE:
			if (flags == EVENT_FLAG_LBUTTON)
			{
				g_pt2 = Point(x, y);
				g_bLeftDownAndMove = true;
			}
			break;
		case EVENT_LBUTTONUP:
			g_pt2 = Point(x, y);
			g_bROI = true;
			g_bLeftDownAndMove = false;
			break;
	}
}

void DrawTrackingPoints(vector<Point2f>& points, Mat& img)
{
	for (int i = 0; i < points.size(); i++)
	{
		int x = cvRound(points[i].x);
		int y = cvRound(points[i].y);
		circle(img, Point(x, y), 3, Scalar(255, 0, 0), 2);
	}
}

int main()
{
	VideoCapture capture("D:\\example\\dataset\\video\\handShaking.mp4");
	if (!capture.isOpened()) return -1;

	Size size = Size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(CAP_PROP_FRAME_HEIGHT));

	int fps = (int)(capture.get(CAP_PROP_FPS));
	int delay = 1000 / fps;
	Mat frame, dstImg;

	Mat curImg, prevImg;
	namedWindow("dstImg");
	setMouseCallback("dstImg", onMouse, NULL);

	int fourcc = VideoWriter::fourcc('d', 'i', 'v', 'x');
	bool isColor = true;
	VideoWriter outputVideo("D:\\example\\dataset\\video\\trackingRect.mp4", fourcc, fps, size, isColor);
	if (!outputVideo.isOpened()) return -1;
	if (fourcc != -1)
	{
		imshow("dstImg", NULL);
		waitKey(100);
	}

	TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 10, 0.01);
	Size winSize(11, 11);

	vector<Point2f> prevPoints;
	vector<Point2f> currPoints;
	vector<Point2f> boundPoints;

	while (true)
	{
		capture >> frame;
		if (frame.empty()) break;

		frame.copyTo(dstImg);
		imshow("dstImg", dstImg);

		cvtColor(dstImg, curImg, COLOR_BGR2GRAY);
		GaussianBlur(curImg, curImg, Size(5, 5), 0.5);
		if (g_bLeftDownAndMove)
		{
			rectangle(dstImg, g_pt1, g_pt2, Scalar(0, 0, 255), 2);
			outputVideo << dstImg;
			imshow("dstImg", dstImg);
		}

		if (g_bROI)
		{
			Mat mask(size, CV_8U);
			mask = 0;
			int w = g_pt2.x - g_pt1.x + 1;
			int h = g_pt2.y - g_pt1.y + 1;
			mask(Rect(g_pt1.x, g_pt1.y, w, h)) = 1;

			double quailyLevel = 0.001;
			double minDist = 10;
			int blockSize = 3;
			prevPoints.clear();

			goodFeaturesToTrack(prevImg, prevPoints, MAX_POINTS,
				quailyLevel, minDist, mask, blockSize, true, 0.04);

			cornerSubPix(prevImg, prevPoints, winSize, Size(-1, -1), criteria);
			DrawTrackingPoints(prevPoints, dstImg);

			RotatedRect minRect = minAreaRect(prevPoints);
			Point2f rectPoints[4];
			minRect.points(rectPoints);
			for (int i = 0; i < 4; i++) boundPoints.push_back(rectPoints[i]);

			outputVideo << dstImg;
			g_bROI = false;
		}

		if (prevPoints.size() > 0)
		{
			vector<Mat> prevPry, curPry;
			Mat status, err;

			buildOpticalFlowPyramid(prevImg, prevPry, winSize, 3, true);
			buildOpticalFlowPyramid(curImg, curPry, winSize, 3, true);

			calcOpticalFlowPyrLK(prevPry, curPry, prevPoints, currPoints, status, err, winSize);

			for (int i = 0; i < prevPoints.size(); i++)
			{
				if (!status.at<uchar>(i))
				{
					prevPoints.erase(prevPoints.begin() + i);
					currPoints.erase(currPoints.begin() + i);
				}
			}

			if (currPoints.size() > 4)
			{
				cornerSubPix(curImg, currPoints, winSize, Size(-1, -1), criteria);
				DrawTrackingPoints(currPoints, dstImg);

				Mat M = findHomography(prevPoints, currPoints, RANSAC);
				perspectiveTransform(boundPoints, boundPoints, M);
				for (int k = 0; k < 4; k++) line(dstImg, boundPoints[k], boundPoints[(k + 1) % 4], Scalar(0, 255, 255), 2);
			}
			outputVideo << dstImg;
			imshow("dstImg", dstImg);
			prevPoints = currPoints;
		}
		curImg.copyTo(prevImg);

		int ckey = waitKey(delay);
		if (ckey == 27) break;
	}

	return 0;
}
*/