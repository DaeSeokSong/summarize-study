/*
#include <iostream>
#include <opencv2/opencv.hpp>

#define MAX_HUE 360
#define MAX_SATURATION 255
#define MAX_VALUE 255
#define ROI_WIDTH 250
#define ROI_HEIGHT 250

using namespace std;
using namespace cv;

VideoCapture camera;

int lowerH = 110, lowerS = 0, lowerV = 30;
int upperH = 190, upperS = 255, upperV = 255;
Scalar lower(lowerH, lowerS, lowerV);
Scalar upper(upperH, upperS, upperV);

// HSV
Mat hsvRoi;
Mat roiMask;

// Roi
Mat roiImg;
Mat templateImg;

// Trackbar
int orderNum = -1;
bool isCreateTrackbar = false;

void createTrackbarHSV();
void onChangeTemplateImg(Mat hsvRoi, Mat& hsvMask, Mat roiImg, Mat& templateImg);
void onChangeLowerH(int pos, void*);
void onChangeLowerS(int pos, void*);
void onChangeLowerV(int pos, void*);
void onChangeUpperH(int pos, void*);
void onChangeUpperS(int pos, void*);
void onChangeUpperV(int pos, void*);
vector<Mat> getScaledImgs(Mat templateImg);
void compareTemplate(vector<Mat> scaledImgs, Mat extractedImg, Mat& showFrame);

int main() {
	camera.open(0);

	if (!camera.isOpened()) {
		cout << "■□■□■□ 카메라 인식 실패 ■□■□■□" << endl;
		return -1;
	}

	// BGR
	Mat frame;
	Mat showFrame;

	// HSV
	Mat hsvImg;
	Mat frameMask;

	// Roi
	Rect roi((camera.get(cv::CAP_PROP_FRAME_WIDTH) / 2) - (ROI_WIDTH / 2), (camera.get(cv::CAP_PROP_FRAME_HEIGHT) / 2) - (ROI_HEIGHT / 2), ROI_WIDTH, ROI_HEIGHT);

	while (true) {
		camera >> frame;
		if (frame.empty()) break;

		frame.copyTo(showFrame);
		rectangle(showFrame, roi, cv::Scalar(0, 0, 255), 2);

		if (isCreateTrackbar) {
			// Template match
			Mat extractedImg;

			cvtColor(frame, hsvImg, COLOR_BGR2HSV);

			inRange(hsvImg, lower, upper, frameMask);
			bitwise_and(frame, frame, extractedImg, frameMask);

			compareTemplate(getScaledImgs(templateImg), extractedImg, showFrame);
		}

		cv::imshow("Display <ORIGIN>", showFrame);

		char inputKey = cv::waitKey(1);
		if (inputKey == 27) break;
		else if (inputKey == 99 || inputKey == 67) {
			frame(roi).copyTo(roiImg);

			cvtColor(roiImg, hsvRoi, COLOR_BGR2HSV);
			onChangeTemplateImg(hsvRoi, roiMask, roiImg, templateImg);

			if (!isCreateTrackbar) {
				createTrackbarHSV();
				isCreateTrackbar = true;
			}
		}
	}

	return 0;
}

void createTrackbarHSV() {
	cv::createTrackbar("Lower H", "Display <ORIGIN>", &lowerH, MAX_HUE, onChangeLowerH);
	cv::createTrackbar("Lower S", "Display <ORIGIN>", &lowerS, MAX_SATURATION, onChangeLowerS);
	cv::createTrackbar("Lower V", "Display <ORIGIN>", &lowerV, MAX_VALUE, onChangeLowerV);
	cv::createTrackbar("Upper H", "Display <ORIGIN>", &upperH, MAX_HUE, onChangeUpperH);
	cv::createTrackbar("Upper S", "Display <ORIGIN>", &upperS, MAX_SATURATION, onChangeUpperS);
	cv::createTrackbar("Upper V", "Display <ORIGIN>", &upperV, MAX_VALUE, onChangeUpperV);
}

void onChangeTemplateImg(Mat hsvRoi, Mat& hsvMask, Mat roiImg, Mat& templateImg) {
	templateImg = 0;

	inRange(hsvRoi, lower, upper, roiMask);
	bitwise_and(roiImg, roiImg, templateImg, roiMask);

	cv::imshow("Display <TEMPLATE IMG>", templateImg);
}

void onChangeLowerH(int pos, void*) {
	lower[0] = pos;
	onChangeTemplateImg(hsvRoi, roiMask, roiImg, templateImg);
}
void onChangeLowerS(int pos, void*) {
	lower[1] = pos;
	onChangeTemplateImg(hsvRoi, roiMask, roiImg, templateImg);
}
void onChangeLowerV(int pos, void*) {
	lower[2] = pos;
	onChangeTemplateImg(hsvRoi, roiMask, roiImg, templateImg);
}
void onChangeUpperH(int pos, void*) {
	upper[0] = pos;
	onChangeTemplateImg(hsvRoi, roiMask, roiImg, templateImg);
}
void onChangeUpperS(int pos, void*) {
	upper[1] = pos;
	onChangeTemplateImg(hsvRoi, roiMask, roiImg, templateImg);
}
void onChangeUpperV(int pos, void*) {
	upper[2] = pos;
	onChangeTemplateImg(hsvRoi, roiMask, roiImg, templateImg);
}

vector<Mat> getScaledImgs(Mat templateImg) {
	vector<Mat> reusltImgs;
	Mat resizedImg;

	for (int i = 1; i < 6; i++) {
		double resizing = 0.1 * i;
		resize(templateImg, resizedImg, Size(templateImg.rows * resizing, templateImg.cols * resizing), 0, 0, INTER_LINEAR);
		reusltImgs.push_back(resizedImg);
	}

	for (int i = 1; i < 6; i++) {
		double resizing = 1.0 + (0.1 * i);
		resize(templateImg, resizedImg, Size(templateImg.rows * resizing, templateImg.cols * resizing), 0, 0, INTER_LINEAR);
		reusltImgs.push_back(resizedImg);
	}

	return reusltImgs;
}

void compareTemplate(vector<Mat> scaledImgs, Mat extractedImg, Mat& showFrame) {
	Mat matchedImg;
	Mat curTemplateImg;

	Mat grayExtImg;
	Mat resizedExtImg;

	Mat graySclImg;
	Mat resizedSclImg;

	double minist = -1;
	double minVal;
	Point minLoc;

	cvtColor(extractedImg, grayExtImg, COLOR_BGR2GRAY);
	resize(grayExtImg, resizedExtImg, Size(extractedImg.cols / 3, extractedImg.rows / 3));
	for (Mat img : scaledImgs) {
		cvtColor(img, graySclImg, COLOR_BGR2GRAY);
		resize(graySclImg, resizedSclImg, Size(img.cols / 3, img.rows / 3));

		matchTemplate(resizedExtImg, resizedSclImg, matchedImg, TM_SQDIFF_NORMED);
		minMaxLoc(matchedImg, &minVal, NULL, &minLoc, NULL);

		if (minVal >= 0.0 && minVal < 10.0) {
			if (minist == -1 || minVal < minist) {
				minist = minVal;
				img.copyTo(curTemplateImg);
				if (minVal == 0.0) break;
			}
		}
	}

	minLoc.x *= 3;
	minLoc.y *= 3;
	if (!curTemplateImg.empty()) rectangle(showFrame, minLoc, Point(minLoc.x + curTemplateImg.cols, minLoc.y + curTemplateImg.rows), Scalar(255, 0, 0), 2);
}
*/