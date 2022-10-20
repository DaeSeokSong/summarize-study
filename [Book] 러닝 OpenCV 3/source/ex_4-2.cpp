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

	// 0.0 ~ 1.0 사이 임의의 부동 소수점 수 125개로 배열 채운다.
	cv::RNG rng;
	rng.fill(n_mat0, cv::RNG::UNIFORM, 0.f, 1.f);
	rng.fill(n_mat1, cv::RNG::UNIFORM, 0.f, 1.f);

	const cv::Mat* arr[] = { &n_mat0, &n_mat1, 0 };
	cv::Mat my_planes[2];

	// 전달인자
	// 1. cv::Mat의 모든 요소에 대한 C스타일 배열 포인터(0이나 NULL로 끝나야 한다.)
	// 2. 배열의 각 평면을 반복할 때 참조하는 또 다른 cv::Mat의 C 스타일 배열
	// 배열을 구성하는 각 평면을 반복할 수 있다.
	// planes[0] = n_mat0의 평면 데이터, planes[1] = n_mat1의 평면 데이터
	cv::NAryMatIterator it(arr, my_planes);

	float s = 0.f; // 두 배열이 모든 평면에 대한 합계
	int n = 0; // 총 평면의 수

	// 두 개의 평면을 합산해서 그 값을 누적시킨다.
	// it.size = 평면의 크기(요소의 수 O, 채널의 수 X), Ex. nplanes = 4, size = 16
	for (int p = 0; p < it.nplanes; p++, ++it) {
		s += cv::sum(it.planes[0])[0];
		s += cv::sum(it.planes[1])[0];
		n++;
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

	cout << "s(두 배열이 모든 평면에 대한 합계) = " << s << endl;
	cout << "n(총 평면의 수) = " << n << endl;
}*/