/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	cv::Mat img = cv::imread("D:/example/dataset/lena_color.png", cv::IMREAD_GRAYSCALE);
	if (img.empty()) return -1;

	cv::Point p1(10, 10), p2(400, 400);
	cv::LineIterator it(img, p1, p2, 8);

	vector<uchar> buffer(it.count);
	for (int i = 0; i < it.count; i++, ++it) {
		buffer[i] = **it;
		// buffer[i] = img.at<uchar>(it.pos());

		// 이미지가 3채널 컬러인 경우
		// buffer[i] = *(const cv::Vec3b)*it;
		// buffer[i] = img.at<cv::Vec3b>(it.pos());
	}
	cout << (cv::Mat)buffer << endl;
	cv::line(img, p1, p2, cv::Scalar(255), 2);

	cv::Mat bfImg(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));
	p1 = cv::Point(0, bfImg.cols - buffer[0]);
	for (int i = 1; i < buffer.size(); i++, ++it) {
		p2 = cv::Point(i, bfImg.cols - buffer[i]);
		cv::line(bfImg, p1, p2, cv::Scalar(255), 2);
		p1 = p2;
	}

	cv::imshow("srcImage", img);
	cv::imshow("dstImage", bfImg);
	cv::waitKey(0);

	return 0;
}
*/