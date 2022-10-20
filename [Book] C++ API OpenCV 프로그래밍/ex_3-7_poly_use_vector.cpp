/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	cv::Mat dstImg(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));

	vector<vector<cv::Point>> contour(2, vector<cv::Point>());
	contour[0].push_back(cv::Point(100, 100));
	contour[0].push_back(cv::Point(200, 100));
	contour[0].push_back(cv::Point(200, 200));
	contour[0].push_back(cv::Point(100, 200));
	contour[1].push_back(cv::Point(300, 200));
	contour[1].push_back(cv::Point(400, 100));
	contour[1].push_back(cv::Point(400, 200));

	const cv::Point* pts1 = (const cv::Point*)cv::Mat(contour[0]).data;
	const cv::Point* pts2 = (const cv::Point*)cv::Mat(contour[1]).data;

	const cv::Point* polygon[2] = { pts1, pts2 };
	int npts[2] = { contour[0].size(), contour[1].size() };

	//cv::polylines(dstImg, polygon, npts, 2, true, cv::Scalar(255, 0, 0));
	//cv::polylines(dstImg, polygons, npts, 2, false, cv::Scalar(255, 0, 0));
	cv::fillConvexPoly(dstImg, polygon[0], npts[0], cv::Scalar(0, 0, 255));
	cv::fillConvexPoly(dstImg, polygon[1], npts[1], cv::Scalar(255, 0, 255));

	cv::imshow("dstImage", dstImg);
	cv::waitKey(0);

	return 0;
}
*/