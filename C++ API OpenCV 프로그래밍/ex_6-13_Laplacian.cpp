/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	uchar dataA[] = { 1, 1, 1, 1, 1, 1,
					1, 1, 1, 1, 1, 1,
					1, 1, 9, 9, 1, 1,
					1, 1, 9, 9, 1, 1,
					1, 1, 1, 1, 1, 1,
					1, 1, 1, 1, 1, 1 };
	Mat A(6, 6, CV_8U, dataA);
	cout << "A = " << A << endl;

	int ksize = 1;
	float K[2][9] = { {0, 1, 0, 1, -4, 1, 0, 1, 0},
					{2, 0, 2, 0, -8, 0, 2, 0, 2} };
	Mat kernel(3, 3, CV_32F, K[ksize == 3]);

	int ddepth = CV_16S;
	Mat dst1;
	filter2D(A, dst1, ddepth, kernel);
	cout << "dst1 = " << dst1 << endl;

	// Laplacian
	// 입력에 대해 라플라시안을 적용한 후에 scale로 스케일링 하고, delta 값을 더해 ddepth 깊이의 출력을 만든다.
	// ksize는 라플라시안 크기를 결정하며 ksize = 1 또는 3일 때 3*3 라플라시안 필터다.
	Mat dst2;
	Laplacian(A, dst2, ddepth, ksize);
	cout << "dst2 = " << dst2 << endl;

	return 0;
}
*/