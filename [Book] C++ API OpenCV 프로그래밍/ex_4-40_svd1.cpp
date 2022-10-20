/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	double dataA[] = { 1, 0, 0, 0, 2,
						0, 0, 3, 0, 0,
						0, 0, 0, 0, 0,
						0, 4, 0, 0, 0 };

	cv::Mat A(4, 5, CV_64F, dataA);
	cout << "A = " << A << endl;

	cv::Mat A1 = A.clone();
	cv::SVD svd(A1, cv::SVD::MODIFY_A + cv::SVD::FULL_UV);
	cout << "svd.u = " << svd.u << endl;
	cout << "svd.w = " << svd.w << endl;
	cout << "svd.vt = " << svd.vt << endl;

	cv::Mat W = cv::Mat::zeros(A.size(), A.type());
	for (int i = 0; i < svd.w.rows; i++) {
		W.at<double>(i, i) = svd.w.at<double>(i, 0);
	}

	cout << "W = " << W << endl;

	cv::Mat A2 = svd.u * W * svd.vt;
	cout << "A2 = " << A2 << endl;

	return 0;
}
*/