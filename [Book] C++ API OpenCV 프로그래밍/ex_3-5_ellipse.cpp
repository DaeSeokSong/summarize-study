/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	cv::Mat dstImg(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::Point center(250, 200);
	cv::Size sz(200, 100);

	cv::rectangle(dstImg, cv::Point(center.x - sz.width, center.y - sz.height), cv::Point(center.x + sz.width, center.y + sz.height), cv::Scalar(255, 0, 0));
	cv::line(dstImg, cv::Point(center.x - sz.width, center.y), cv::Point(center.x + sz.width, center.y), cv::Scalar(0, 255, 0));
	cv::line(dstImg, cv::Point(center.x, center.y - sz.height), cv::Point(center.x, center.y + sz.height), cv::Scalar(0, 255, 0));
	cv::ellipse(dstImg, center, sz, 0, 0, 360, cv::Scalar(0, 0, 250));
	cv::ellipse(dstImg, center, sz, 90, 45, 360, cv::Scalar(0, 0, 250), 10);

	cv::RotatedRect box(center, sz, 90);
	cv::ellipse(dstImg, box, cv::Scalar(255, 0, 0), -1);

	vector<cv::Point> pts;
	cv::ellipse2Poly(center, sz, 90, 0, 360, 45, pts);
	cv::polylines(dstImg, pts, true, cv::Scalar(0, 255, 0), 4);

	cv::Point pt1, pt2;
	for (int i = 0; i < pts.size(); i++) {
		pt1 = pts[i];
		if (i == pts.size() - 1) pt2 = pts[0];
		else pt2 = pts[i + 1];

		cv::line(dstImg, pt1, pt2, cv::Scalar(0, 0, 255));
	}

	cv::imshow("dstImage", dstImg);
	cv::waitKey(0);

	return 0;
}
*/