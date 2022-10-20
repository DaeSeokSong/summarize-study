/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	namedWindow("Example2_10", WINDOW_AUTOSIZE);

	VideoCapture cap;
	if (argc == 1) {
		cap.open(0); // 첫번째 카메라 열기
	}
	else {
		cap.open(argv[1]);
	}

	if (!cap.isOpened()) {
		cerr << "Couldn't open capture." << endl;
		return -1;
	}
}
*/