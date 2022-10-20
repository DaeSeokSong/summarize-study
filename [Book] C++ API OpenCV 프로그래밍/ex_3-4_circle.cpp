/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	cv::Mat dstImg(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::rectangle(dstImg, cv::Point(100, 100), cv::Point(400, 400), cv::Scalar(0, 0, 255));
	cv::line(dstImg, cv::Point(250, 100), cv::Point(250, 400), cv::Scalar(0, 0, 255));
	cv::line(dstImg, cv::Point(100, 250), cv::Point(400, 250), cv::Scalar(0, 0, 255));
	cv::circle(dstImg, cv::Point(250, 250), 150, cv::Scalar(255, 0, 0));
	cv::circle(dstImg, cv::Point(250, 250), 50, cv::Scalar(0, 255, 0), -1);

	cv::imshow("dstImage", dstImg);
	cv::waitKey(0);

	return 0;
}
*/