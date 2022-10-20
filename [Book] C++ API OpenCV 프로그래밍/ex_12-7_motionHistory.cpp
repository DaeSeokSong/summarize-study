/*

#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/optflow/motempl.hpp"

using namespace std;
using namespace cv;
using namespace cv::motempl;

const double MHI_DURATION = 1;
const double MAX_TIME_DELTA = 0.5;
const double MIN_TIME_DELTA = 0.05;
const int N = 4;

void DifferenceIFrames(Mat& src1, Mat& src2, Mat& dst, int nTh)
{
	absdiff(src1, src2, dst);
	threshold(dst, dst, nTh, 255, THRESH_BINARY);
}

void Mhi2MotionImage(Mat& mhi, Mat& motion, Mat& mask, double timeStamp)
{
	if (motion.empty()) motion.create(mhi.size(), CV_8UC3);

	double scale = 255. / MHI_DURATION;
	double t = MHI_DURATION - timeStamp;
	mask = mhi * scale + t * scale;
	mask.convertTo(mask, CV_8U);

	motion = Scalar::all(0);
	Mat tmp = Mat::zeros(mhi.size(), CV_8U);
	Mat outImg[] = { mask, tmp, tmp };
	merge(outImg, 3, motion);
}

void DrawMotionOrientation(vector<Rect> rects, Mat& silh, Mat& mhi,
	Mat& orient, Mat& mask, Mat& dstImg, double timeStamp)
{
	int i, x, y;
	int count;
	Rect comp_rect;
	Scalar color;
	Point center;
	double r, angle;
	Size size = dstImg.size();

	for (i = -1; i < rects.size(); i++)
	{
		if (i < 0)
		{
			comp_rect = Rect(0, 0, size.width, size.height);
			color = Scalar(255, 0, 0);
			r = 100;
		}
		else
		{
			comp_rect = rects[i];
			if (comp_rect.width * comp_rect.height < 100) continue;
			color = Scalar(0, 0, 255);
			r = 30;
		}

		Mat silhROI = silh(comp_rect);
		Mat mhiROI = mhi(comp_rect);
		Mat orientROI = orient(comp_rect);
		Mat maskROI = mask(comp_rect);

		angle = calcGlobalOrientation(orientROI, maskROI, mhiROI, timeStamp, MHI_DURATION);
		angle = 360.0 - angle;

		count = countNonZero(silhROI);
		if (count < comp_rect.width * comp_rect.height * 0.001) continue;

		center = Point((comp_rect.x + comp_rect.width / 2), (comp_rect.y + comp_rect.height / 2));
		circle(dstImg, center, cvRound(r * 1.2), color, 3, -1);

		x = cvRound(center.x + r * cos(angle * CV_PI / 180));
		y = cvRound(center.y - r * sin(angle * CV_PI / 180));

		line(dstImg, center, Point(x, y), color, 3, -1);
	}
}

int main()
{
	VideoCapture capture("D:\\example\\dataset\\YT_Protector\\Video\\Slow_walk.mp4");
	if (!capture.isOpened()) return -1;

	Size size = Size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(CAP_PROP_FRAME_HEIGHT));

	int fps = (int)(capture.get(CAP_PROP_FPS));
	int delay = 1000 / fps;
	Mat frame, dstImg;

	double timeStamp;
	int nTh = 50;
	int last = 0;
	int prev, curr;

	int frameNum = -1;
	Mat silh, orient, motion, mask, segmask;
	Mat mhi(size, CV_32F, Scalar::all(0));
	vector<Mat> buffer(N);
	vector<Rect> boundingRects;

	while (true)
	{
		capture >> frame;
		if (frame.empty()) break;

		frameNum++;

		cvtColor(frame, buffer[last], COLOR_BGR2GRAY);
		curr = last;
		prev = (curr + 1) % N;
		last = prev;
		silh = buffer[prev];

		if (frameNum < N) continue;

		DifferenceIFrames(buffer[prev], buffer[curr], silh, nTh);
		imshow("silh", silh);

		timeStamp = (double)clock() / CLOCKS_PER_SEC;
		updateMotionHistory(silh, mhi, timeStamp, MHI_DURATION);
		Mhi2MotionImage(mhi, motion, mask, timeStamp);
		imshow("motion", motion);

		calcMotionGradient(mhi, mask, orient, MAX_TIME_DELTA, MIN_TIME_DELTA);
		segmentMotion(mhi, segmask, boundingRects, timeStamp, MAX_TIME_DELTA);

		frame.copyTo(dstImg);
		if (boundingRects.size() > 0)
		{
			DrawMotionOrientation(boundingRects, silh, mhi, orient, mask, dstImg, timeStamp);
		}
		imshow("dstImg", dstImg);

		int ckey = waitKey(delay);
		if (ckey == 27) break;
	}

	return 0;
}

*/