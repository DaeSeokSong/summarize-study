#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void threshold();
void adaptive_threshold();
void on_trackbar(int pos, void* userdata);

int main()
{
	//// Ex1
	//threshold();

	//// Ex2
	//adaptive_threshold();

	// Ex3
	VideoCapture cap("vtest.avi");

	if (!cap.isOpened())
	{
		cout << "Video open FAIL" << endl;
		return 0;
	}

	Mat rectK = getStructuringElement(MORPH_RECT, Size(3, 3));

	Mat frame, inversed;
	while (true)
	{
		cap >> frame;
		if (frame.empty()) break;

		cvtColor(frame, frame, COLOR_BGR2GRAY);
		threshold(frame, frame, 0, 255, THRESH_BINARY | THRESH_OTSU);

		Mat cannyF;
		Canny(frame, cannyF, 50, 127);

		Mat dilateF, erodeF, openF, closeF, gradF;
		morphologyEx(frame, dilateF, MORPH_DILATE, rectK);
		morphologyEx(frame, erodeF, MORPH_ERODE, rectK);
		morphologyEx(frame, openF, MORPH_OPEN, rectK);
		morphologyEx(frame, closeF, MORPH_CLOSE, rectK);
		morphologyEx(frame, gradF, MORPH_GRADIENT, rectK);

		Mat diffF;
		absdiff(dilateF, openF, diffF);

		imshow("Original frame", frame);
		imshow("Canny frame", cannyF);
		imshow("DiffAbs(dilate-open) frame", diffF);
		imshow("Morph Dilate frame", dilateF);
		imshow("Morph Erode frame", erodeF);
		imshow("Morph Open frame", openF);
		imshow("Morph Close frame", closeF);
		imshow("Morph Gradient frame", gradF);

		int input_key = waitKey(100);

		if (input_key == 27) break;
	}

	return 0;
}

void threshold()
{
	//Mat src = imread("sudoku.jpg", IMREAD_GRAYSCALE);
	Mat src = imread("camera.jpg", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return;
	}

	Mat dst;
	//threshold(src, dst, 0, 255, THRESH_BINARY);
	threshold(src, dst, 0, 255, THRESH_BINARY | THRESH_OTSU);
 
	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
}

void adaptive_threshold()
{
	Mat src = imread("sudoku.jpg", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return;
	}

	Mat thres_OSTU;
	threshold(src, thres_OSTU, 0, 255, THRESH_BINARY | THRESH_OTSU);

	imshow("src", src);
	imshow("thres_OSTU", thres_OSTU);

	namedWindow("dst");
	createTrackbar("Block Size", "dst", 0, 200, on_trackbar, (void*)&src);
	setTrackbarPos("Block Size", "dst", 11);

	waitKey(0);
}

void on_trackbar(int pos, void* userdata)
{
	Mat src = *(Mat*)userdata;

	int bsize = pos;
	if (bsize % 2 == 0) bsize--;
	if (bsize < 3) bsize = 3;

	Mat dst;
	adaptiveThreshold(src, dst, 255,
		ADAPTIVE_THRESH_GAUSSIAN_C,
		THRESH_BINARY,
		bsize, 5);

	imshow("dst", dst);
}