/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	// 단일채널 uchar, 500x500, 모든 픽셀=0, 이미지 생성
	cv::Mat img(cv::Size(500, 500), CV_8UC1, cv::Scalar(0));

	cv::namedWindow("Exercise_4-1", cv::WINDOW_AUTOSIZE);
	cv::imshow("Exercise_4-1", img);

	int x = 0;
	int y = 20;
	while (true) {
		char c[] = { cv::waitKey(5000), '\0'};
		if (isdigit(c[0])) {
			cv::putText(img, string(c), cv::Point(x, y), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 1, 1);
			if (x + 10 < 500) x += 10;
			else {
				x = 0;
				y += 20;
			}

			cv::imshow("Exercise_4-1", img);
		}
	}

	return 0;
}
*/