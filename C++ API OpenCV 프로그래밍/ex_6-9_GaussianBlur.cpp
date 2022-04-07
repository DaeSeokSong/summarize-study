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

	int ksize = 3;
	double sigma = 0.0;
	// getGaussianKernel
	// ksize * 1의 1차원 가우시안 커널을 행렬로 반환한다. ksize는 홀수여야 한다. sigma는 표준 편차이다.
	// sigma <= 일 경우, simga = 0.3*((ksize-1)*0.5 - 1) + 0.8 로 계산한다.
	Mat kx = getGaussianKernel(ksize, sigma);
	cout << "kx = " << kx << endl;
	Mat ky = getGaussianKernel(ksize, sigma);
	cout << "ky = " << ky << endl;
	Mat kxy = ky * kx.t();
	cout << "kxy = " << kxy << endl;
	cout << "sum(kxy) = " << sum(kxy) << endl;

	Mat dst1;
	sepFilter2D(A, dst1, -1, kx, ky);
	cout << "dst1 = " << dst1 << endl;

	Mat dst2;
	filter2D(A, dst2, -1, kxy);
	cout << "dst2 = " << dst2 << endl;

	// GaussianBlur (패딩 방식 = BORDER_REPLICATE101)
	// ksize 크기의 2차원 가우시안 커널과 Convolution을 수행한다. 각 sigma 값은 X, Y 축으로 각각 가우시안 커널 표준편차이다.
	// sigmaX 는 0이 될 수 없고 sigmaY = 0이면 SigmaY = sigmaX 이다.
	Mat dst3;
	GaussianBlur(A, dst3, Size(ksize, ksize), sigma, sigma);
	cout << "dst3 = " << dst3 << endl;

	return 0;
}
*/