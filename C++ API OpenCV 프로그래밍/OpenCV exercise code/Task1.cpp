/*
#include <iostream>
#include <opencv2/opencv.hpp>

#define MAX_HUE 360
#define MAX_SATURATION 255
#define MAX_VALUE 255

using namespace std;

int lowerH = 150, lowerS = 60, lowerV = 30;
int upperH = 190, upperS = 255, upperV = 255;
cv::Scalar lower(lowerH, lowerS, lowerV);
cv::Scalar upper(upperH, upperS, upperV);
cv::VideoCapture camera;

void createTrackbarHSV();
void onChangeLowerH(int pos, void*) { lower[0] = pos; }
void onChangeLowerS(int pos, void*) { lower[1] = pos; }
void onChangeLowerV(int pos, void*) { lower[2] = pos; }
void onChangeUpperH(int pos, void*) { upper[0] = pos; }
void onChangeUpperS(int pos, void*) { upper[1] = pos; }
void onChangeUpperV(int pos, void*) { upper[2] = pos; }

int main() {
	cv::namedWindow("Display <ORIGIN>");
	cv::namedWindow("Display <RESULT>");

	camera.open(0);

	if (!camera.isOpened()) {
		cout << "■□■□■□ 카메라 인식 실패 ■□■□■□" << endl;
		return -1;
	}

	createTrackbarHSV();

	cv::Mat frame;
	cv::Mat cvtFrame;
	cv::Mat blueMask;
	while (true) {
		cv::Mat result;

		camera >> frame;
		if (frame.empty()) break;

		cv::cvtColor(frame, cvtFrame, cv::COLOR_BGR2HSV);
		cv::inRange(cvtFrame, lower, upper, blueMask);
		cv::bitwise_and(frame, frame, result, blueMask);

		cv::imshow("Display <ORIGIN>", frame);
		cv::imshow("Display <RESULT>", result);

		if (cv::waitKey(1) == 27) break;
	}

	return 0;
}

void createTrackbarHSV() {
	cv::createTrackbar("Lower H", "Display <RESULT>", &lowerH, MAX_HUE, onChangeLowerH);
	cv::createTrackbar("Lower S", "Display <RESULT>", &lowerS, MAX_SATURATION, onChangeLowerS);
	cv::createTrackbar("Lower V", "Display <RESULT>", &lowerV, MAX_VALUE, onChangeLowerV);
	cv::createTrackbar("Upper H", "Display <RESULT>", &upperH, MAX_HUE, onChangeUpperH);
	cv::createTrackbar("Upper S", "Display <RESULT>", &upperS, MAX_SATURATION, onChangeUpperS);
	cv::createTrackbar("Upper V", "Display <RESULT>", &upperV, MAX_VALUE, onChangeUpperV);
}
*/