/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	double dataA[] = { 2, -1, 1,
						3, 3, 9,
						3, 3, 5 };

	cv::Mat A(3, 3, CV_64F, dataA);
	cout << "A = " << A << endl;

	cv::Mat B = (cv::Mat_<double>(3, 1) << -1, 0, 4);
	cout << "B = " << B << endl;

	cv::SVD svd(A, cv::SVD::MODIFY_A + cv::SVD::FULL_UV);
	cout << "svd.u = " << svd.u << endl;
	cout << "svd.w = " << svd.w << endl;
	cout << "svd.vt = " << svd.vt << endl;

	cv::Mat X;
	svd.backSubst(B, X);
	cout << "X = " << X << endl;

	return 0;
}
*/