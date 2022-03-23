/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	cv::Mat dstImg(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));

	cv::Point pts1[4] = { cv::Point(100, 100), cv::Point(200, 100), cv::Point(200, 200), cv::Point(100, 200) };
	cv::Point pts2[3] = { cv::Point(300, 200), cv::Point(400, 100), cv::Point(400, 200) };

	const cv::Point* polygons[2] = { pts1, pts2 };
	int npts[2] = { 4, 3 };

	//cv::polylines(dstImg, polygons, npts, 2, true, cv::Scalar(255, 0, 0));
	//cv::polylines(dstImg, polygons, npts, 2, false, cv::Scalar(255, 0, 0));
	cv::fillConvexPoly(dstImg, polygons[0], npts[0], cv::Scalar(0, 0, 255));
	cv::fillConvexPoly(dstImg, polygons[1], npts[1], cv::Scalar(255, 0, 255));

	cv::imshow("dstImage", dstImg);
	cv::waitKey(0);

	return 0;
}
*/