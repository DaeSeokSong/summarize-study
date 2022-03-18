/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	namedWindow("Example2_3");

	VideoCapture cap;
	cap.open(0);
	//cap.open("D:/example/dataset/Robin.avi");

	Mat frame;
	while (true) {
		cap >> frame;
		if (frame.empty()) break;

		imshow("Example2_3", frame);
		if (waitKey(0) >= 0) break;
	}

	return 0;
}
*/