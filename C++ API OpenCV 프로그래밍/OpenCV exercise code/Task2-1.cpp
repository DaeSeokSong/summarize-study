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

	cv::VideoCapture camera;
	camera.open(0);

	if (!camera.isOpened()) {
		cout << "■□■□■□ 카메라 인식 실패 ■□■□■□" << endl;
		return -1;
	}

	cv::Mat result;
	cv::Mat frame;
	cv::Ptr<cv::BackgroundSubtractor> pMOG2 = cv::createBackgroundSubtractorMOG2();
	while (true) {
		camera >> frame;
		if (frame.empty()) break;

		pMOG2->apply(frame, result);
		cv::threshold(result, result, 10, 255, cv::THRESH_BINARY);

		cv::imshow("Display <ORIGIN>", frame);
		cv::imshow("Display <RESULT>", result);

		char inputKey = cv::waitKey(1);
		if (inputKey == 27) break;
	}

	return 0;
}
*/