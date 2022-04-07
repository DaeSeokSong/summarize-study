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

	int border = 2;

	Mat B;
	copyMakeBorder(A, B, border, border, border, border, BORDER_REPLICATE, 0);
	cout << "B = " << B << endl;

	cout << "borderInterpolate" << endl;
	for (int y = -border; y < A.rows + border; y++) {
		for (int x = -border; x < A.cols + border; x++) {
			// borderType(Ex. BORDER_REPLICATE)으로 패딩한 위치의 값을 출력
			float val = A.at<uchar>(borderInterpolate(y, A.rows, BORDER_REPLICATE), borderInterpolate(x, A.cols, BORDER_REPLICATE));
			cout << val << ",";
		}
		cout << endl;
	}

	cout << "A = " << A << endl;

	waitKey(0);
	return 0;
}
*/