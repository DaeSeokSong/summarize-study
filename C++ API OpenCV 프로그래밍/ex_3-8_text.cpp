/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	cv::Mat dstImg(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));

	string text = "OpenCV Programming";
	int fontFace = cv::FONT_HERSHEY_SIMPLEX;
	double fontScale = 1.0;
	int thickness = 1;
	int baseLine;
	cv::Point org(100, 100);

	cv::putText(dstImg, text, org, fontFace, fontScale, cv::Scalar(0, 0, 0));
	cv::Size sz = cv::getTextSize(text, fontFace, fontScale, thickness, &baseLine);
	cv::rectangle(dstImg, org, cv::Point(org.x + sz.width, org.y - sz.height), cv::Scalar(0, 0, 255));
	cv::circle(dstImg, org, 3, cv::Scalar(255, 0, 0), 2);

	cv::imshow("dstImage", dstImg);
	cv::waitKey(0);

	return 0;
}
*/