#include <iostream>
#include <opencv2/opencv.hpp>

#define MAX_HUE 360
#define MAX_SATURATION 255
#define MAX_VALUE 255

using namespace std;

int main() {
	cv::namedWindow("Display <ORIGIN>");
	cv::namedWindow("Display <RESULT BACK_PROJECT>");
	cv::namedWindow("Display <RESULT MOG2>");
	cv::namedWindow("Display <RESULT BACK_PROJECT + MOG2>");

	cv::VideoCapture camera;
	camera.open(0);

	if (!camera.isOpened()) {
		cout << "■□■□■□ 카메라 인식 실패 ■□■□■□" << endl;
		return -1;
	}

	cv::Mat frame;

	cv::Mat frameHSV;
	cv::Mat hueImg;
	vector<cv::Mat> planes;
	cv::Rect roi(250, 350, 100, 100);
	cv::Mat roiImg;

	int histSize = 256;
	float hValue[] = { 0, 256 };
	const float* ranges[] = { hValue };
	int channels = 0;
	int dims = 1;
	cv::Mat hist;
	cv::Mat hueImg2;
	cv::Mat backProject;

	cv::Mat mog2_1;
	cv::Mat mog2_2;
	// history, 인식된 객체(이진화 영역 중 흰색)가 화면에 남아있는 시간
	// varThreshold, 인식되기 위한 임계값
	cv::Ptr<cv::BackgroundSubtractor> pMOG2_1 = cv::createBackgroundSubtractorMOG2(10, 32.0);
	cv::Ptr<cv::BackgroundSubtractor> pMOG2_2 = cv::createBackgroundSubtractorMOG2(10, 32.0);
	while (true) {
		camera >> frame;
		if (frame.empty()) break;

		cv::cvtColor(frame, frameHSV, cv::COLOR_BGR2HSV);
		cv::split(frameHSV, planes);
		hueImg = planes[0];

		cv::rectangle(frame, roi, cv::Scalar(0, 0, 255), 2);
		roiImg = hueImg(roi);

		cv::calcHist(&roiImg, 1, &channels, cv::Mat(), hist, dims, &histSize, ranges);
		hueImg.convertTo(hueImg2, CV_32F);
		cv::calcBackProject(&hueImg2, 1, &channels, hist, backProject, ranges);
		cv::normalize(backProject, backProject, 0, 255, cv::NORM_MINMAX, CV_8U);

		pMOG2_1->apply(frame, mog2_1);
		cv::threshold(mog2_1, mog2_1, 10, 255, cv::THRESH_BINARY);

		pMOG2_2->apply(backProject, mog2_2);
		cv::threshold(mog2_2, mog2_2, 10, 255, cv::THRESH_BINARY);

		cv::imshow("Display <ORIGIN>", frame);
		cv::imshow("Display <RESULT BACK_PROJECT>", backProject);
		cv::imshow("Display <RESULT MOG2>", mog2_1);
		cv::imshow("Display <RESULT BACK_PROJECT + MOG2>", mog2_2);

		char inputKey = cv::waitKey(1);
		if (inputKey == 27) break;
	}

	return 0;
}