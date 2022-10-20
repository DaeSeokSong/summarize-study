/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

typedef struct _DATA {
	Mat img;
	Mat mask;
} DATA;

void onMouse(int event, int x, int y, int flags, void* param);

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png");
	if (srcImg.empty()) return -1;

	Mat dstImg = srcImg.clone();
	imshow("dstImg", dstImg);

	Mat mask = Mat::zeros(srcImg.size(), CV_8U);
	Mat markers = Mat::zeros(srcImg.size(), CV_32S);

	DATA data = { dstImg, mask };
	setMouseCallback("dstImg", onMouse, (void*)&data);

	int mode = RETR_LIST;
	int method = CHAIN_APPROX_SIMPLE;
	vector<vector<Point>> contours;

	bool bEscKey = false;
	int nKey;
	while (!bEscKey)
	{
		nKey = waitKey(0);
		switch (nKey)
		{
			case 27:
				bEscKey = true;
				break;
			case 'r':
				mask = 0;
				srcImg.copyTo(dstImg);
				imshow("dstImg", dstImg);
				break;
			case ' ':
				findContours(mask, contours, noArray(), mode, method);
				if (contours.size() < 1) break;

				markers = 0;
				for (int k = 0; k < contours.size(); k++)
				{
					drawContours(markers, contours, k, k + 1, -1);
				}
				watershed(srcImg, markers);

				// make color tables for displaying objects
				Mat colorTable(contours.size(), 1, CV_8UC3);
				Vec3b color;
				for (int k = 0; k < contours.size(); k++)
				{
					color[0] = rand() & 180 + 50;
					color[1] = rand() & 180 + 50;
					color[2] = rand() & 180 + 50;
					colorTable.at<Vec3b>(k, 0) = color;
				}

				// display objects using markers
				for (int y = 0; y < markers.cols; y++)
				{
					for (int x = 0; x < markers.rows; x++)
					{
						int k = markers.at<int>(y, x);
						// boundary
						if (k == -1) color[0] = color[1] = color[2] = 255;
						else if (k <= 0 || k > contours.size()) color[0] = color[1] = color[2] = 0;
						else
						{
							color = colorTable.at<Vec3b>(k - 1, 0);
							dstImg.at<Vec3b>(y, x) = color;
						}
					}
				}
				addWeighted(dstImg, 0.5, srcImg, 0.5, 0, dstImg);
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