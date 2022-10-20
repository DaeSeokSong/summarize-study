/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	cv::Mat dstImage(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::rectangle(dstImage, cv::Point(100, 100), cv::Point(400, 400), cv::Scalar(0, 0, 255), 2);
	cv::rectangle(dstImage, cv::Point(400 / 2, 100 / 2), cv::Point(100 / 2, 400 / 2), cv::Scalar(255, 0, 0));

	cv::line(dstImage, cv::Point(400, 100), cv::Point(100, 400), cv::Scalar(0, 255, 0));
	cv::line(dstImage, cv::Point(400, 100), cv::Point(100, 400), cv::Scalar(0, 255, 0), 2, 8, 1);

	cv::imshow("dstImage", dstImage);
	cv::waitKey(0);

	return 0;
}
*/