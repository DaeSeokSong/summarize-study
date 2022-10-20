/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	uchar dataA[] = { 1, 2, 4, 5, 2, 1,
					3, 6, 6, 9, 0, 3,
					1, 8, 3, 7, 2, 5,
					2, 9, 8, 9, 9, 1,
					3, 9, 8, 8, 7, 2,
					4, 9, 9, 9, 9, 3 };
	Mat A(Size(6, 6), CV_8U, dataA);
	cout << "A = " << A << endl;

	Mat avgKernel = (Mat_<float>(3, 3) << 1. / 9., 1. / 9., 1. / 9.,
										1. / 9., 1. / 9., 1. / 9.,
										1. / 9., 1. / 9., 1. / 9.);

	// Correlation, filter2D는 기본적으로 Correlation으로 작동
	Mat B;
	filter2D(A, B, -1, avgKernel);
	cout << "B = " << B << endl;

	Mat C;
	filter2D(A, C, -1, avgKernel, Point(1, 1));
	cout << "C = " << C << endl;

	// Convolution, 필터를 flip 시키고 fliter(Correlation) 적용하면 Convolution 계산
	Mat D;
	Mat flipKernel;
	flip(avgKernel, flipKernel, -1);
	filter2D(A, D, -1, flipKernel);
	cout << "D = " << D << endl;

	return 0;
}
*/