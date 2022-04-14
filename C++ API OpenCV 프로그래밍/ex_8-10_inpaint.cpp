/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

typedef struct _DATA{
	Mat img;
	Mat mask;
} DATA;

void onMouse(int event, int x, int y, int flags, void* param);

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat dstImg = srcImg.clone();
	Mat mask = Mat::zeros(srcImg.size(), CV_8U);
	imshow("dstImg", dstImg);

	DATA data = { dstImg, mask };
	setMouseCallback("dstImg", onMouse, (void*)&data);

	double inpaintRadius = 5;
	int flags = INPAINT_TELEA;

	bool bEscKey = false;
	int nKey;
	while(!bEscKey)
	{
		nKey = waitKey(0);
		switch (nKey)
		{
			case 27:
				bEscKey = true;
				break;
			case 'r' :
				mask = 0;
				srcImg.copyTo(dstImg);
				imshow("dstImg", dstImg);
				break;
			case ' ' :
				inpaint(dstImg, mask, dstImg, inpaintRadius, flags);
				imshow("dstImg", dstImg);
				break;
		}
	}

	return 0;
}

void onMouse(int event, int x, int y, int flags, void* param)
{
	DATA* data = (DATA*)param;
	Mat mask = data->mask;
	Mat dstImg = data->img;
	switch (event)
	{
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON)
		{
			circle(mask, Point(x, y), 10, Scalar::all(255), -1);
			circle(dstImg, Point(x, y), 10, Scalar::all(255), -1);
		}
	}
	imshow("dstImg", dstImg);
}
*/