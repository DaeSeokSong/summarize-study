/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

const cv::Scalar lowerB(95, 40, 40);
const cv::Scalar lowerG(30, 65, 75);
const cv::Scalar lowerR(135, 20, 20);
const cv::Scalar upperB(120, 255, 255);
const cv::Scalar upperG(45, 255, 255);
const cv::Scalar upperR(250, 255, 255);

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
	cv::Mat result;

	// HSV
	cv::Mat hsvFrame;
	cv::Mat blueMask;
	cv::Mat greenMask;
	cv::Mat redMask;

	// Threshold
	cv::Mat binBlueMask;
	cv::Mat binGreenMask;
	cv::Mat binRedMask;

	// Contours
	double area;
	cv::Rect boundingBox;
	vector<vector<cv::Point>> blueContours;
	vector<vector<cv::Point>> greenContours;
	vector<vector<cv::Point>> redContours;

	// Start projection on window
	while (true)
	{
		// Get frame per second
		camera >> frame;
		if (frame.empty()) break;
		else result = frame.clone();

		// Create mask
		cv::cvtColor(frame, hsvFrame, cv::COLOR_BGR2HSV);
		cv::inRange(hsvFrame, lowerB, upperB, blueMask);
		cv::inRange(hsvFrame, lowerG, upperG, greenMask);
		cv::inRange(hsvFrame, lowerR, upperR, redMask);

		// Threshold
		cv::threshold(blueMask, binBlueMask, 127, 255, cv::THRESH_OTSU);
		cv::threshold(greenMask, binGreenMask, 127, 255, cv::THRESH_OTSU);
		cv::threshold(redMask, binRedMask, 127, 255, cv::THRESH_OTSU);
		cv::imshow("T1", binBlueMask);
		cv::imshow("T2", binGreenMask);
		cv::imshow("T3", binRedMask);

		// Find contours
		cv::findContours(binBlueMask, blueContours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
		cv::findContours(binGreenMask, greenContours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
		cv::findContours(binRedMask, redContours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

		// Draw contour
		for (vector<cv::Point> contour : blueContours)
		{
			area = cv::contourArea(contour);
			if (area > 300)
			{
				boundingBox = cv::boundingRect(contour);
				cv::rectangle(result, boundingBox, cv::Scalar(255, 0, 0), 2);
				cv::putText(result, "Blue Box", cv::Point(boundingBox.x, boundingBox.y - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 0, 0), 1.5);
			}
		}
		for (vector<cv::Point> contour : greenContours)
		{
			area = cv::contourArea(contour);
			if (area > 300)
			{
				boundingBox = cv::boundingRect(contour);
				cv::rectangle(result, boundingBox, cv::Scalar(0, 255, 0), 2);
				cv::putText(result, "Green Box", cv::Point(boundingBox.x, boundingBox.y - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 1.5);
			}
		}
		for (vector<cv::Point> contour : redContours)
		{
			area = cv::contourArea(contour);
			if (area > 300)
			{
				boundingBox = cv::boundingRect(contour);
				cv::rectangle(result, boundingBox, cv::Scalar(0, 0, 255), 2);
				cv::putText(result, "Red Box", cv::Point(boundingBox.x, boundingBox.y - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255), 1.5);
			}
		}

		// Show image
		cv::imshow("RESULT", result);

		// Function keys
		char inputKey = cv::waitKey(1);
		if (inputKey == 27) break;
	}

	return 0;
}
*/