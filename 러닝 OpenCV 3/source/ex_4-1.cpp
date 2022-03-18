/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	const int n_mat_size = 5;
	const int n_mat_sz[] = { n_mat_size , n_mat_size , n_mat_size };
	// 3차원의 배열 생성
	cv::Mat n_mat(3, n_mat_sz, CV_32FC1);

	cv::RNG rng;
	// 0.0 ~ 1.0 사이 임의의 부동 소수점 수 125개로 배열 채운다.
	rng.fill(n_mat, cv::RNG::UNIFORM, 0.f, 1.f);

	const cv::Mat* arr[] = { &n_mat, 0 };
	cv::Mat my_planes[1];

	// 전달인자
	// 1. cv::Mat의 모든 요소에 대한 C스타일 배열 포인터(0이나 NULL로 끝나야 한다.)
	// 2. 배열의 각 평면을 반복할 때 참조하는 또 다른 cv::Mat의 C 스타일 배열
	cv::NAryMatIterator it(arr, my_planes); // 배열을 구성하는 각 평면을 반복할 수 있다.

	// it.planes[i]는 'arr'의 i번째 배열의 현재 평면이 된다.
	float s = 0.f;
	int n = 0;
	// 평면의 개수 = it.nplanes
	// NAryMatIterator는 현재 참조하는 배열의 평면 헤더를 가지고 있다.
	for (int p = 0; p < it.nplanes; p++, ++it) {
		s += cv::sum(it.planes[0])[0];
		n++;
	}
}
*/