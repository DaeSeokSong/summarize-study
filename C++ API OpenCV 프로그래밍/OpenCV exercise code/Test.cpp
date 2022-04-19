#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

#define ROI_WIDTH 100
#define ROI_HEIGHT 100

int main()
{
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
	cv::Mat hsvFrame;
	cv::Mat hImg8U;
	cv::Mat hImg32F;
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

	// Extract result
	cv::Mat rgbBp(cv::Size(camera.get(cv::CAP_PROP_FRAME_WIDTH), camera.get(cv::CAP_PROP_FRAME_HEIGHT)), CV_32F, cv::Scalar(0));
	cv::Mat chartBIN(cv::Size(camera.get(cv::CAP_PROP_FRAME_WIDTH), camera.get(cv::CAP_PROP_FRAME_HEIGHT)), CV_8U, cv::Scalar(0));

	// Color compare
	double skinRate = 0;

	// Start projection on window
	while (true)
	{
		// Get frame per second
		camera >> frame;
		if (frame.empty()) break;
		else frame.copyTo(originF);

		// Convert BGR to HSV
		cv::cvtColor(frame, hsvFrame, cv::COLOR_BGR2HSV);

		// ROI Backproject
		cv::rectangle(frame, roi, cv::Scalar(0, 0, 255), 2);
		if (!roiImg.empty()) // is Exist ROI image
		{
			// Extract H(Hue)
			cv::split(hsvFrame, planes);
			planes[0].copyTo(hImg8U);

			// Make mask by backproject
			hImg8U.convertTo(hImg32F, CV_32F);
			cv::calcBackProject(&hImg32F, 1, &channels, roiHist, backProject, ranges);
			cv::normalize(backProject, backProject, 0, 255, cv::NORM_MINMAX, CV_8U);

			// Extract RGB image substacted mask(backproject)
			rgbBp = cv::Scalar::all(0);
			cv::bitwise_and(originF, originF, rgbBp, backProject);

			// Calculate extracted region(Value == 1, white) on backproejct
			chartBIN = cv::Scalar::all(0);
			for (int y = 0; y < backProject.rows; y++)
			{
				int density = 0;
				for (int x = 0; x < backProject.cols; x++)
				{
					if (backProject.at<uchar>(y, x) != 0)
					{
						chartBIN.at<uchar>(y, density++) = 255;
						skinRate++;
					}
				}
			}
			skinRate = (skinRate / (backProject.rows * backProject.cols)) * 100;

			// Show results
			cv::imshow("Display <RESULT BACK_PROJECT>", backProject);
			cv::imshow("Display <COLOR CHAR in BackProject>", chartBIN);
			cv::imshow("Display <RESULT BACK_PROJECT(RGB)>", rgbBp);
		}
		cout << "영상 중 피부색 비율 = " << skinRate << "%" << endl;
		cv::imshow("Display <ORIGIN>", frame);

		// Function keys
		char inputKey = cv::waitKey(1);
		if (inputKey == 27) break;
		else if (inputKey == 99 || inputKey == 67)
		{
			roiImg = hsvFrame(roi);
			cv::calcHist(&roiImg, 1, &channels, cv::Mat(), roiHist, dims, &histSize, ranges);
		}
	}

	return 0;
}