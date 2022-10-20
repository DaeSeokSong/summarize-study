/*
#include <iostream>
#include <opencv2/opencv.hpp>
#include <random>

using namespace std;

int main() {
	// 난수 설정
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 255);

	cv::Mat img1(cv::Size(100, 200), CV_8UC1, cv::Scalar(dis(gen)));
	cv::Mat img2(cv::Size(100, 200), CV_32FC1, cv::Scalar(0));

	cv::waitKey(0);
}
*/