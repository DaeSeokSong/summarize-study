/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	const int n_mat_size = 5;
	const int n_mat_sz[] = { n_mat_size , n_mat_size , n_mat_size };
	// 3차원의 배열 생성
	cv::Mat n_mat0(3, n_mat_sz, CV_32FC1);
	cv::Mat n_mat1(3, n_mat_sz, CV_32FC1);
	cv::Mat dst(3, n_mat_sz, CV_32FC1);

	// 0.0 ~ 1.0 사이 임의의 부동 소수점 수 125개로 배열 채운다.
	cv::RNG rng;
	rng.fill(n_mat0, cv::RNG::UNIFORM, 0.f, 1.f);
	rng.fill(n_mat1, cv::RNG::UNIFORM, 0.f, 1.f);
	rng.fill(dst, cv::RNG::UNIFORM, 0.f, 1.f);

	const cv::Mat* arr[] = { &n_mat0, &n_mat1, &dst, 0 };
	float* ptrs[3];

	// 전달인자
	// 1. cv::Mat의 모든 요소에 대한 C스타일 배열 포인터(0이나 NULL로 끝나야 한다.)
	// 2. 배열의 각 평면을 반복할 때 참조하는 또 다른 cv::Mat의 C 스타일 배열
	// 배열을 구성하는 각 평면을 반복할 수 있다.
	// planes[0] = n_mat0의 평면 데이터, planes[1] = n_mat1의 평면 데이터
	cv::NAryMatIterator it(arr, (uchar**)ptrs);


	// 두 개의 평면을 합산해서 그 값을 누적시킨다.
	// it.size = 평면의 크기(요소의 수 O, 채널의 수 X), Ex. nplanes = 4, size = 16
	for (size_t i= 0; i < it.nplanes; i++, ++it) {
		for (size_t j = 0; j < it.size; j++) {
			ptrs[2][j] = pow(ptrs[0][j], ptrs[1][j]); // pow = 제곱함수, Ex. ptrs[0][j]의  ptrs[1][j] 제곱
		}
	}

	cout << "n_mat0.flags = " << n_mat0.flags << endl;
	cout << "n_mat0.dims = " << n_mat0.dims << endl;
	cout << "n_mat0.size = " << n_mat0.size << endl; // 평면의 크기
	cout << "n_mat0.rows = " << n_mat0.rows << endl;
	cout << "n_mat0.cols = " << n_mat0.cols << endl;
	cout << '\n';

	cout << "n_mat1.flags = " << n_mat1.flags << endl;
	cout << "n_mat1.dims = " << n_mat1.dims << endl;
	cout << "n_mat1.size = " << n_mat1.size << endl;
	cout << "n_mat1.rows = " << n_mat1.rows << endl;
	cout << "n_mat1.cols = " << n_mat1.cols << endl;
	cout << '\n';

	cout << &ptrs << endl;
	cout << *ptrs << endl;
	cout << ptrs << endl;
}
*/