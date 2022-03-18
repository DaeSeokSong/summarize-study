#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	cv::Mat src1 = cv::imread("D:/example/dataset/DdaBongDoChi.jpg", -1);
	cv::Mat src2 = cv::imread("D:/example/dataset/Lenna.png", -1);

	if (src1.empty() && src2.empty()) {
		cout << "\n■□■□■□ ERROR, image read ■□■□■□\n" << endl;
		return -1;
	}

	int x1 = 365;
	int y1 = 70;
	int x2 = 235;
	int y2 = 235;
	int w = 115;
	int h = 150;
	double alpha = 0.5; // 투명도 수준
	double beta = 1 - alpha; // 투명도 수준

	cv::Mat roi1(src1, cv::Rect(x1, y1, w, h));
	cv::Mat roi2(src2, cv::Rect(x2, y2, w, h));

	cv::addWeighted(roi1, alpha, roi2, beta, 0, roi1);

	cv::namedWindow("Alpha Blend");
	cv::imshow("Alpha Blend", src1);
	cv::waitKey(0);

	return 0;
}