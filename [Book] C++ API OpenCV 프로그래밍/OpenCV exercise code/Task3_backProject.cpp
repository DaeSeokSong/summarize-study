/*
#include <iostream>
#include <opencv2/opencv.hpp>

#define MAX_HUE 360
#define MAX_SATURATION 255
#define MAX_VALUE 255
#define ROI_WIDTH 100
#define ROI_HEIGHT 100

using namespace std;

int main() {
	cv::namedWindow("Display <ORIGIN>");
	cv::namedWindow("Display <RESULT BACK_PROJECT>");
	cv::namedWindow("Display <RESULT BACK_PROJECT(RGB)>");
	cv::namedWindow("Display <COLOR CHAR in BackProject>");

	cv::VideoCapture camera;
	camera.open(0);

	if (!camera.isOpened()) {
		cout << "■□■□■□ 카메라 인식 실패 ■□■□■□" << endl;
		return -1;
	}

	// BGR
	cv::Mat frame;
	cv::Mat originF;

	// HSV
	cv::Mat frameHSV;
	cv::Mat hueImg;
	cv::Mat hueImg2;
	vector<cv::Mat> planes;

	// ROI
	cv::Rect roi((camera.get(cv::CAP_PROP_FRAME_WIDTH) / 2) - (ROI_WIDTH / 2), (camera.get(cv::CAP_PROP_FRAME_HEIGHT) / 2) + ROI_HEIGHT, ROI_WIDTH, ROI_HEIGHT);
	cv::Mat roiImg;

	// Histogram
	int histSize = 256;
	float hValue[] = { 0, 256 };
	const float* ranges[] = { hValue };
	int channels = 0;
	int dims = 1;
	cv::Mat roiHist;
	cv::Mat backProject;

	// Color chart
	cv::Mat chartRGB(cv::Size(camera.get(cv::CAP_PROP_FRAME_WIDTH), camera.get(cv::CAP_PROP_FRAME_HEIGHT)), CV_8U, cv::Scalar(255));
	int minRGB = 0;

	// MOG2
	// history, 인식된 객체(이진화 영역 중 흰색)가 화면에 남아있는 시간
	// varThreshold, 인식되기 위한 임계값
	cv::Ptr<cv::BackgroundSubtractor> pMOG2 = cv::createBackgroundSubtractorMOG2(10, 32.0);
	cv::Mat mog2;
	while (true) {
		cv::Mat rgbBp;
		cv::Mat chartBIN(cv::Size(camera.get(cv::CAP_PROP_FRAME_WIDTH), camera.get(cv::CAP_PROP_FRAME_HEIGHT)), CV_8U, cv::Scalar(255));

		camera >> frame;
		if (frame.empty()) break;
		else frame.copyTo(originF);

		// Convert BGR to HSV
		cv::cvtColor(frame, frameHSV, cv::COLOR_BGR2HSV);
		cv::split(frameHSV, planes);
		planes[0].copyTo(hueImg);

		// ROI Backproject
		cv::rectangle(frame, roi, cv::Scalar(0, 0, 255), 2);
		if (!roiImg.empty()) {
			hueImg.convertTo(hueImg2, CV_32F);
			cv::calcBackProject(&hueImg2, 1, &channels, roiHist, backProject, ranges);

			cv::normalize(backProject, backProject, 0, 255, cv::NORM_MINMAX, CV_8U);
			cv::bitwise_and(originF, originF, rgbBp, backProject);

			for (int x = 0; x < backProject.rows; x++) {
				int height = 0;
				for (int y = 0; y < backProject.cols; y++) {
					if (backProject.at<uchar>(x, y) == 1) {
						chartBIN.at<uchar>(x, height++) = 0;
					}
				}
			}

			cv::imshow("Display <RESULT BACK_PROJECT>", backProject);
			cv::imshow("Display <COLOR CHAR in BackProject>", chartBIN);
			cv::imshow("Display <RESULT BACK_PROJECT(RGB)>", rgbBp);
		}
		cv::imshow("Display <ORIGIN>", frame);

		char inputKey = cv::waitKey(1);
		if (inputKey == 27) break;
		else if (inputKey == 99 || inputKey == 67) {
			roiImg = hueImg(roi);
			cv::calcHist(&roiImg, 1, &channels, cv::Mat(), roiHist, dims, &histSize, ranges);
		}
	}

	return 0;
}
*/