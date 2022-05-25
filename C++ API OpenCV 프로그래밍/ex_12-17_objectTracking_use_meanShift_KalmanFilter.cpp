#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

#define DIST_TH 0.4

Rect selection;
bool bLButtonDown = false;

typedef enum { INIT, CALC_HIST, TRACKING } STATUS;
STATUS trackingMode = INIT;

void onMouse(int mevent, int x, int y, int flags, void* param)
{
	static Point origin;
	Mat* pMat = (Mat*)param;
	Mat image = Mat(*pMat);

	if (bLButtonDown)
	{
		selection.x = MIN(x, origin.x);
		selection.y = MIN(y, origin.y);
		selection.width = selection.x + abs(x - origin.x);
		selection.height = selection.y + abs(y - origin.y);

		selection.x = MAX(selection.x, 0);
		selection.y = MAX(selection.y, 0);
		selection.width = MIN(selection.width, image.cols);
		selection.height = MIN(selection.height, image.rows);

		selection.width -= selection.x;
		selection.height -= selection.y;
	}

	switch (mevent)
	{
	case EVENT_LBUTTONDOWN:
		origin = Point(x, y);
		selection = Rect(x, y, 0, 0);
		bLButtonDown = true;
		break;
	case EVENT_LBUTTONUP:
		bLButtonDown = false;
		if (selection.width > 0 && selection.height > 0) trackingMode = CALC_HIST;
		break;
	}
}

int main()
{
	VideoCapture capture;
	capture.open(0);
	if (!capture.isOpened()) return -1;

	Size size = Size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(CAP_PROP_FRAME_HEIGHT));

	int fps = (int)(capture.get(CAP_PROP_FPS));
	int delay = 1000 / fps;
	Mat frame;

	Mat dstImg;
	namedWindow("dstImg");
	setMouseCallback("dstImg", onMouse, (void*)&dstImg);

	int histSize = 8;
	float valueRange[] = { 0, 180 };
	const float* ranges[] = { valueRange };
	int channels = 0;
	Mat hist, backProject;

	int fourcc = VideoWriter::fourcc('M', 'J', 'P', 'G');
	bool isColor = true;
	VideoWriter outputVideo("D:\\example\\dataset\\video\\trackingRect_meanShift+KalmanFilter.avi", fourcc, fps, size, isColor);
	if (!outputVideo.isOpened()) return -1;

	if (fourcc != -1)
	{
		cv::imshow("dstImg", NULL);
		waitKey(100);
	}

	TermCriteria criteria = TermCriteria(TermCriteria::COUNT + TermCriteria::EPS, 10, 2);
	Rect trackingWindow;

	Mat hImg, hsvImg, mask;

	// Kalman
	Point2f ptPred;
	Point2f ptEstim;
	Point2f ptMeasured;

	// state vector
	KalmanFilter KF(4, 2, 0);
	Mat measurement(2, 1, CV_32F);

	float dt = 1.0;
	const float A[] = { 1, 0, dt, 0,
						0, 1, 0, dt,
						0, 0, 1, 0,
						0, 0, 0, 1 };

	memcpy(KF.transitionMatrix.data, A, sizeof(A));

	// Init kalman params
	double Q = 1e-5;
	double R = 0.0001;
	const float H[] = { 1, 0, 0, 0,
						0, 1, 0 ,0 };
	memcpy(KF.transitionMatrix.data, H, sizeof(H));

	setIdentity(KF.processNoiseCov, Scalar::all(Q));
	KF.processNoiseCov.at<float>(2, 2) = 0;
	KF.processNoiseCov.at<float>(3, 3) = 0;

	setIdentity(KF.measurementNoiseCov, Scalar::all(R));

	Mat hist1, hist2;

	while (true)
	{
		capture >> frame;
		if (frame.empty()) break;

		cvtColor(frame, hsvImg, COLOR_BGR2HSV);
		frame.copyTo(dstImg);

		if (bLButtonDown && 0 < selection.width && 0 < selection.height)
		{
			Mat dstROI = dstImg(selection);
			bitwise_xor(dstROI, Scalar::all(255), dstROI);
		}

		if (trackingMode)
		{
			int vmin = 50, vmax = 256, smin = 50;
			inRange(hsvImg, Scalar(0, smin, MIN(vmin, vmax)), Scalar(180, 256, MAX(vmin, vmax)), mask);

			int ch[] = { 0, 0 };
			hImg.create(hsvImg.size(), CV_8U);
			mixChannels(&hsvImg, 1, &hImg, 1, ch, 1);

			if (trackingMode == CALC_HIST)
			{
				Mat hImgROI(hImg, selection), maskROI(mask, selection);
				calcHist(&hImgROI, 1, &channels, maskROI, hist, 1, &histSize, ranges);

				hist.copyTo(hist1);
				normalize(hist1, hist1, 1.0);
				normalize(hist, hist, 0, 255, NORM_MINMAX);

				trackingWindow = selection;
				trackingMode = TRACKING;

				// Init the state vector
				ptMeasured = Point2f(trackingWindow.x + trackingWindow.width / 2.0, trackingWindow.y + trackingWindow.height / 2.0);
				KF.statePost.at<float>(0, 0) = ptMeasured.x;
				KF.statePost.at<float>(1, 0) = ptMeasured.y;
				KF.statePost.at<float>(2, 0) = 0;
				KF.statePost.at<float>(3, 0) = 0;

				setIdentity(KF.errorCovPost, Scalar::all(1));
			}

			Mat prediction = KF.predict();
			ptPred.x = prediction.at<float>(0, 0);
			ptPred.y = prediction.at<float>(1, 0);

			calcBackProject(&hImg, 1, &channels, hist, backProject, ranges);
			backProject &= mask;

			meanShift(backProject, trackingWindow, criteria);
			Point pt1 = Point(trackingWindow.x, trackingWindow.y);
			Point pt2 = Point(pt1.x + trackingWindow.width, pt1.y + trackingWindow.height);
			rectangle(dstImg, pt1, pt2, Scalar(0, 0, 255), 2);

			// Validate the result of meanShift
			Mat hImgROI(hImg, trackingWindow), maskROI(mask, trackingWindow);
			calcHist(&hImgROI, 1, &channels, maskROI, hist2, 1, &histSize, ranges);
			normalize(hist2, hist2, 1.0);
			double dist = compareHist(hist1, hist2, HISTCMP_BHATTACHARYYA);
			if (dist < DIST_TH) // A tracking object is detected
			{
				ptMeasured = Point2f(trackingWindow.x + trackingWindow.width / 2.0, trackingWindow.y + trackingWindow.height / 2.0);
				measurement.at<float>(0, 0) = ptMeasured.x;
				measurement.at<float>(1, 0) = ptMeasured.y;

				Mat estimate = KF.correct(measurement);
				ptEstim.x = estimate.at<float>(0, 0);
				ptEstim.y = estimate.at<float>(1, 0);

				trackingWindow = Rect(ptEstim.x - selection.width / 2,
										ptEstim.y - selection.height / 2,
										selection.width, selection.height);

				pt1 = Point(ptMeasured.x - trackingWindow.width / 2, ptMeasured.y - trackingWindow.height / 2);
				pt2 = Point(ptMeasured.x + trackingWindow.width / 2, ptMeasured.y + trackingWindow.height / 2);
				rectangle(dstImg, pt1, pt2, Scalar(0, 0, 255), 2);
				circle(dstImg, ptMeasured, 5, Scalar(0, 0, 255), 2);

				pt1 = Point(ptEstim.x - trackingWindow.width / 2, ptEstim.y - trackingWindow.height / 2);
				pt2 = Point(ptEstim.x + trackingWindow.width / 2, ptEstim.y + trackingWindow.height / 2);
				rectangle(dstImg, pt1, pt2, Scalar(255, 0, 0), 2);
				circle(dstImg, ptEstim, 5, Scalar(255, 0, 0), 2);
			}
			else // not detected
			{
				trackingWindow = Rect(ptPred.x - selection.width / 2, ptPred.y - selection.height / 2, selection.width, selection.height);

				pt1 = Point(ptPred.x - trackingWindow.width / 2, ptPred.y - trackingWindow.height / 2);
				pt2 = Point(ptPred.x + trackingWindow.width / 2, ptPred.y + trackingWindow.height / 2);
				rectangle(dstImg, pt1, pt2, Scalar(0, 255, 0), 2);
				circle(dstImg, ptPred, 5, Scalar(0, 255, 0), 2);
			}
		}

		cv::imshow("dstImg", dstImg);
		outputVideo << dstImg;

		int ckey = waitKey(delay);
		if (ckey == 27) break;
	}

	return 0;
}