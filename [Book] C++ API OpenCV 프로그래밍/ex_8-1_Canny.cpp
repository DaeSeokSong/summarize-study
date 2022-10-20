/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	// Canny(입력, 출력, 임계값1, 임계값2 (1 < 2), 기울기 계산용 Sobel 필터 크기, 그래디언트 크기 계산 방법)
	// 가우시안 필터링 > Sobel로 기울기 크기 계산 > 벡터 방향에 기울기 크기가 최대값인 화소만 남기고
	// 나머지는 0으로 억제 > 큰 임계값에서 낮은 임계값이 나올 때까지 추적하며
	// 에지를 연결(히스테리시스 임계값 방식)

	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat edges;
	Canny(srcImg, edges, 50, 100);
	imshow("edges", edges);
	waitKey(0);

	return 0;
}
*/