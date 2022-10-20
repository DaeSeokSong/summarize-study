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

	Mat avgX = (Mat_<float>(1, 3) << 1. / 3., 1. / 3., 1. / 3.);
	Mat avgY = (Mat_<float>(3, 1) << 1. / 3., 1. / 3., 1. / 3.);

	Mat B, C;
	filter2D(A, B, -1, avgX);
	cout << "B = " << B << endl;
	filter2D(B, C, -1, avgY);
	cout << "C = " << C << endl;

	Mat D;
	// filter2D와 기본 동작은 같으나 X, Y에 각자 분리된 필터를 적용할 수 있다.
	sepFilter2D(A, D, -1, avgX, avgY);
	cout << "D = " << D << endl;

	return 0;
}
*/