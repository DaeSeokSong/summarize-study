/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

#define ROI_WIDTH 100
#define ROI_HEIGHT 100

int main()
{
	cv::VideoCapture camera;
	camera.open(0);

	if (!camera.isOpened()) {
		cout << "■□■□■□ 카메라 인식 실패 ■□■□■□" << endl;
		return -1;
	}

	// BGR
	cv::Mat frame;
	cv::Mat grayFrame;
	cv::Mat result;

	// HSV
	cv::Mat hsvFrame;
	vector<cv::Mat> hueFrame;
	cv::Mat hueRoi8U;
	cv::Mat hueRoi32F;
	double avgH = 0, avgS = 0, avgV = 0;
	cv::Scalar color;

	// Histogram
	int histSize = 256;
	float hValue[] = { 0, 256 };
	const float* ranges[] = { hValue };
	int channels = 0;
	int dims = 1;
	cv::Mat roiHist;
	cv::Mat backProject;

	// Threshold
	cv::Mat binFrame;
	cv::Mat mopthK = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

	// Contours
	double area;
	cv::Rect boundingBox;
	vector<vector<cv::Point>> Contours;

	// ROI
	cv::Rect roi((camera.get(cv::CAP_PROP_FRAME_WIDTH) / 2) - (ROI_WIDTH / 2), (camera.get(cv::CAP_PROP_FRAME_HEIGHT) / 2), ROI_WIDTH, ROI_HEIGHT);
	cv::Mat roiFrame;
	vector<cv::Mat> splitedRoi;

	// Start projection on window
	while (true)
	{
		// Get frame per second
		camera >> frame;
		if (frame.empty()) break;
		else result = frame.clone();

		// ROI create
		cv::rectangle(result, roi, cv::Scalar(255, 0, 255), 2);

		// BGR to HSV
		cv::cvtColor(frame, hsvFrame, cv::COLOR_BGR2HSV);

		// Start extract
		if (!roiFrame.empty())
		{
			// Extract Hue
			cv::split(hsvFrame, hueFrame);
			hueFrame[0].copyTo(hueRoi8U);

			// Convert 8U to 32F
			hueRoi8U.convertTo(hueRoi32F, CV_32F);

			// Excute backproject
			cv::calcBackProject(&hueRoi32F, 1, &channels, roiHist, backProject, ranges);
			cv::normalize(backProject, backProject, 0, 255, cv::NORM_MINMAX, CV_8U);
			cv::imshow("backProject", backProject);

			// Threshold
			cv::threshold(backProject, binFrame, 100, 255, cv::THRESH_OTSU);
			cv::morphologyEx(binFrame, binFrame, cv::MORPH_DILATE, mopthK);
			cv::morphologyEx(binFrame, binFrame, cv::MORPH_CLOSE, mopthK);
			cv::morphologyEx(binFrame, binFrame, cv::MORPH_ERODE, mopthK);
			cv::imshow("binMask", binFrame);

			// Find contours
			cv::findContours(binFrame, Contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

			// Draw contour
			for (vector<cv::Point> contour : Contours)
			{
				area = cv::contourArea(contour);
				if (area > 300)
				{
					boundingBox = cv::boundingRect(contour);
					cv::rectangle(result, boundingBox, color, 2);
					cv::putText(result, "Target Color", cv::Point(boundingBox.x, boundingBox.y - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, color, 1.5);
				}
			}
		}

		// Show image
		cv::imshow("RESULT", result);

		// Function keys
		char inputKey = cv::waitKey(1);
		if (inputKey == 27) break;
		else if (inputKey == 99 || inputKey == 67)
		{
			// ============================ROI============================
			// Extract roi
			hsvFrame(roi).copyTo(roiFrame);

			// ============================HSV to RGB============================
			// Extract H, S, V and average each other
			cv::split(roiFrame, splitedRoi);
			avgH = cv::mean(splitedRoi[0])[0];
			avgS = cv::mean(splitedRoi[1])[0];
			avgV = cv::mean(splitedRoi[2])[0];

			// Set RGB color
			color = cv::Scalar(avgH, avgS, avgV);

			// Transform color HSV to RGB
			cv::Mat colorH2R(cv::Size(1, 1), CV_8UC3, color);
			cv::cvtColor(colorH2R, colorH2R, cv::COLOR_HSV2BGR);
			color = cv::Scalar(colorH2R.data[0], colorH2R.data[1], colorH2R.data[2]);

			// ============================ Calculate Histogram============================
			cv::calcHist(&roiFrame, 1, &channels, cv::Mat(), roiHist, dims, &histSize, ranges);
		}
	}

	return 0;
}
*/