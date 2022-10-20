/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

// 기존 함수 형태, 행렬 타입이 CV_32F(float)이 아닌 경우 컴파일 에러 발생
void print_matrix_origin(const cv::SparseMat* sm) {
	cv::SparseMatConstIterator_<float> it = sm->begin<float>();
	cv::SparseMatConstIterator_<float> it_end = sm->end<float>();

	for (; it != it_end; ++it) {
		const cv::SparseMat::Node* node = it.node();
		printf(" (%3d, %3d) %f\n", node->idx[0], node->idx[1], *it);
	}
}

// 개선 함수, 어떤 데이터형이 행렬에 주어져도 컴파일 에러 발생 X
template <class T> void print_matrix(const cv::SparseMat_<T>* sm) {
	// sm 선언 할 때 <>안에 데이터형을 명시하고 인스턴스화 했으므로
	// begin()과 end()에 <>안에 데이터형 명시할 필요 없다.
	cv::SparseMatConstIterator_<T> it = sm->begin();
	cv::SparseMatConstIterator_<T> it_end = sm->end();

	for (; it != it_end; ++it) {
		const typename cv::SparseMat_<T>::Node* node = it.node();
		cout << "(" << node->idx[0] << ", " << node->idx[1] << ") = " << *it << '\n' << endl;
	}
}

int main() {
	const int n_mat_size = 5;
	const int n_mat_sz[] = { n_mat_size , n_mat_size , n_mat_size };

	// 3차원의 배열 생성
	cv::Mat n_mat0(3, n_mat_sz, CV_32FC1);
	cv::Mat n_mat1(3, n_mat_sz, CV_32SC1);

	// 0.0 ~ 1.0 사이 임의의 부동 소수점 수 125개로 배열 채운다.
	cv::RNG rng;
	rng.fill(n_mat0, cv::RNG::UNIFORM, 0.f, 1.f);
	rng.fill(n_mat1, cv::RNG::UNIFORM, 1, 10);

	// 희소 행렬로 변환
	cv::SparseMat_<float> n_sparseMat0(n_mat0);
	cv::SparseMat_<int> n_sparseMat1(n_mat1);

	print_matrix<float>(&n_sparseMat0);
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	print_matrix<int>(&n_sparseMat1);
}
*/