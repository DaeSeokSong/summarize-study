/*
#include <iostream>
#include <opencv2/opencv.hpp>

#define MAX_HUE 360
#define MAX_SATURATION 255
#define MAX_VALUE 255

using namespace std;

int main() {
	cv::namedWindow("Display <ORIGIN>");
	cv::namedWindow("Display <RESULT>");
	cv::namedWindow("Display <BACKGROUND>");

	cv::VideoCapture camera;
	camera.open(0);

	if (!camera.isOpened()) {
		cout << "■□■□■□ 카메라 인식 실패 ■□■□■□" << endl;
		return -1;
	}

	cv::Mat result;
	cv::Mat frame;
	cv::Mat frameGray;
	cv::Mat bgImg(cv::Size(640, 480), CV_8UC1, cv::Scalar(255, 255, 255));
	while (true) {
		camera >> frame;
		if (frame.empty()) break;

		cv::cvtColor(frame, frameGray, cv::COLOR_BGR2GRAY);
		cv::absdiff(frameGray, bgImg, result);
		cv::threshold(result, result, 100, 255, cv::THRESH_BINARY);

		cv::imshow("Display <ORIGIN>", frame);
		cv::imshow("Display <RESULT>", result);
		cv::imshow("Display <BACKGROUND>", bgImg);

		char inputKey = cv::waitKey(1);
		if (inputKey == 27) break;
		else if (inputKey == 99) cv::cvtColor(frame, bgImg, cv::COLOR_BGR2GRAY);
	}

	return 0;
}
*/