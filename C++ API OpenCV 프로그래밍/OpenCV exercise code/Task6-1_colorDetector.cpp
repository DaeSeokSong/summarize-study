#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

#define MAX_HUE 360
#define MAX_SATURATION 255
#define MAX_VALUE 255
#define ROI_WIDTH 100
#define ROI_HEIGHT 100

int whatColor(cv::Scalar color);

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
	cv::Mat colorMask;
	cv::Scalar lower(0, 0, 0);
	cv::Scalar upper(360, 255, 255);
	double minVal, maxVal;
	cv::Point maxLoc;
	const double alphaH = 15;
	const double alphaS = 50;
	const double alphaV = 100;
	double minH = 0, minS = 0, minV = 0;
	double maxH = MAX_HUE, maxS = MAX_SATURATION, maxV = MAX_VALUE;
	double avgH = 0, avgS = 0, avgV = 0;
	double lowerH, lowerS, lowerV;
	double upperH, upperS, upperV;
	cv::Scalar color;
	int kindOfColor;

	// Threshold
	cv::Mat binMask;
	cv::Mat mopthK = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

	cv::Mat mopthK1 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(21, 21));


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

		// Start extract
		if (!roiFrame.empty())
		{
			// Create mask
			cv::cvtColor(frame, hsvFrame, cv::COLOR_BGR2HSV);
			cv::inRange(hsvFrame, lower, upper, colorMask);

			// Threshold
			cv::threshold(colorMask, binMask, 100, 255, cv::THRESH_OTSU);

			cv::imshow("bin origin", binMask);

			cv::morphologyEx(binMask, binMask, cv::MORPH_OPEN, mopthK1);
			cv::morphologyEx(binMask, binMask, cv::MORPH_DILATE, mopthK);
			cv::morphologyEx(binMask, binMask, cv::MORPH_CLOSE, mopthK);
			cv::morphologyEx(binMask, binMask, cv::MORPH_ERODE, mopthK);
			cv::imshow("binMask", binMask);

			// Find contours
			cv::findContours(binMask, Contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

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
			// BGR to HSV
			cv::cvtColor(frame, hsvFrame, cv::COLOR_BGR2HSV);

			// Extract roi
			roiFrame = hsvFrame(roi);

			// Extract H, S, V and average each other
			cv::split(roiFrame, splitedRoi);
			cv::medianBlur(splitedRoi[0], splitedRoi[0], 121);
			avgH = cv::mean(splitedRoi[0])[0];
			avgS = cv::mean(splitedRoi[1])[0];
			avgV = cv::mean(splitedRoi[2])[0];

			// Set RGB color
			color = cv::Scalar(avgH, avgS, avgV);
			kindOfColor = whatColor(color);

			// Set min, max of H, S, V
			if (kindOfColor == 0) // Blue
			{
				minH = 95; maxH = 125;
				minS = 40; maxS = 255;
				minV = 40; maxV = 255;
			}
			else if (kindOfColor == 1) // Green
			{
				minH = 30; maxH = 65;
				minS = 65; maxS = 255;
				minV = 75; maxV = 255;
			}
			else if (kindOfColor == 2) // Red, lower
			{
				minH = 0; maxH = 10;
				minS = 35; maxS = 255;
				minV = 50; maxV = 255;
			}
			else if (kindOfColor == 3) // Red, upper
			{
				minH = 165; maxH = 180;
				minS = 35; maxS = 255;
				minV = 50; maxV = 255;
			}

			// Into lower and upper
			if (avgH - alphaH >= minH) lowerH = avgH - alphaH;
			else lowerH = minH;
			if (avgS - alphaS >= minS) lowerS = avgS - alphaS;
			else lowerS = minS;
			if (avgV - alphaV >= minV) lowerV = avgV - alphaV;
			else lowerV = minV;
			if (avgH + alphaH <= maxH) upperH = avgH + alphaH;
			else upperH = maxH;
			if (avgS + alphaS <= maxS) upperS = avgS + alphaS;
			else upperS = maxS;
			if (avgV + alphaV <= maxV) upperV = avgV + alphaV;
			else upperV = maxV;
			lower = cv::Scalar(lowerH, lowerS, lowerV);
			upper = cv::Scalar(upperH, upperS, upperV);

			// Transform color HSV to RGB
			cout << "color (HSV) = " << color << endl;
			cv::Mat colorH2R(cv::Size(1, 1), CV_8UC3, color);
			cv::cvtColor(colorH2R, colorH2R, cv::COLOR_HSV2BGR);
			color = cv::Scalar(colorH2R.data[0], colorH2R.data[1], colorH2R.data[2]);
		}
	}

	return 0;
}

int whatColor(cv::Scalar color)
{
	int result = -1;

	int H = color[0];
	if (H >= 95 && H <= 125) result = 0; // Blue
	else if (H >= 30 && H <= 65) result = 1; // Green
	else if (H >= 0 && H <= 10) result = 2; // Red, lower
	else if (H >= 165 && H <= 180) result = 3; // Red, upper

	cout << "kindOfColor = " << result << endl;
	return result;
}