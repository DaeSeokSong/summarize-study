//#include <iostream>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//Rect selection;
//bool bLButtonDown = false;
//
//typedef enum {INIT, CALC_HIST, TRACKING} STATUS;
//STATUS trackingMode = INIT;
//
//void onMouse(int mevent, int x, int y, int flags, void* param)
//{
//	static Point origin;
//	Mat* pMat = (Mat*)param;
//	Mat image = Mat(*pMat);
//	
//	if (bLButtonDown)
//	{
//		selection.x = MIN(x, origin.x);
//		selection.y = MIN(y, origin.y);
//		selection.width = selection.x + abs(x - origin.x);
//		selection.height = selection.y + abs(y - origin.y);
//
//		selection.x = MAX(selection.x, 0);
//		selection.y = MAX(selection.y, 0);
//		selection.width = MIN(selection.width, image.cols);
//		selection.height = MIN(selection.height, image.rows);
//
//		selection.width -= selection.x;
//		selection.height -= selection.y;
//	}
//
//	switch (mevent)
//	{
//		case EVENT_LBUTTONDOWN:
//			origin = Point(x, y);
//			selection = Rect(x, y, 0, 0);
//			bLButtonDown = true;
//			break;
//		case EVENT_LBUTTONUP:
//			bLButtonDown = false;
//			if (selection.width > 0 && selection.height > 0) trackingMode = CALC_HIST;
//			break;
//	}
//}
//
//int main()
//{
//	VideoCapture capture;
//	capture.open(0);
//	if (!capture.isOpened()) return -1;
//
//	Size size = Size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(CAP_PROP_FRAME_HEIGHT));
//
//	int fps = (int)(capture.get(CAP_PROP_FPS));
//	int delay = 1000 / fps;
//	Mat frame;
//
//	Mat dstImg;
//	namedWindow("dstImg");
//	setMouseCallback("dstImg", onMouse, (void*)&dstImg);
//
//	int histSize = 8;
//	float valueRange[] = { 0, 180 };
//	const float* ranges[] = { valueRange };
//	int channels = 0;
//	Mat hist, backProject;
//
//	int fourcc = VideoWriter::fourcc('M', 'J', 'P', 'G');
//	bool isColor = true;
//	VideoWriter outputVideo("D:\\example\\dataset\\video\\trackingRect.avi", fourcc, fps, size, isColor);
//	if (!outputVideo.isOpened()) return -1;
//
//	if (fourcc != -1)
//	{
//		imshow("dstImg", NULL);
//		waitKey(100);
//	}
//
//	TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 10, 2);
//	Rect trackingWindow;
//	
//	Mat hImg, hsvImg, mask;
//
//	while (true)
//	{
//		capture >> frame;
//		if (frame.empty()) break;
//
//		cvtColor(frame, hsvImg, COLOR_BGR2HSV);
//		frame.copyTo(dstImg);
//
//		if (bLButtonDown && 0 < selection.width && 0 < selection.height)
//		{
//			Mat dstROI = dstImg(selection);
//			bitwise_xor(dstROI, Scalar::all(255), dstROI);
//		}
//
//		if (trackingMode)
//		{
//			int vmin = 50, vmax = 256, smin = 50;
//			inRange(hsvImg, Scalar(0, smin, MIN(vmin, vmax)), Scalar(180, 256, MAX(vmin, vmax)), mask);
//
//			int ch[] = { 0, 0 };
//			hImg.create(hsvImg.size(), CV_8U);
//			mixChannels(&hsvImg, 1, &hImg, 1, ch, 1);
//
//			if (trackingMode == CALC_HIST)
//			{
//				Mat hImgROI(hImg, selection), maskROI(mask, selection);
//				calcHist(&hImgROI, 1, &channels, maskROI, hist, 1, &histSize, ranges);
//				normalize(hist, hist, 0, 255, NORM_MINMAX);
//				trackingWindow = selection;
//				trackingMode = TRACKING;
//			}
//
//			calcBackProject(&hImg, 1, &channels, hist, backProject, ranges);
//			backProject &= mask;
//
//			meanShift(backProject, trackingWindow, criteria);
//			Point pt1 = Point(trackingWindow.x, trackingWindow.y);
//			Point pt2 = Point(pt1.x + trackingWindow.width, pt1.y + trackingWindow.height);
//			rectangle(dstImg, pt1, pt2, Scalar(0, 0, 255), 2);
//		}
//
//		imshow("dstImg", dstImg);
//		outputVideo << dstImg;
//
//		int ckey = waitKey(delay);
//		if (ckey == 27) break;
//	}
//
//	return 0;
//}