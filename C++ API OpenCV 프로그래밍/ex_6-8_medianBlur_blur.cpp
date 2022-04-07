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

	int border = 1;

	// BORDER_CONSTANT, 0-padding
	Mat B;
	copyMakeBorder(A, B, border, border, border, border, BORDER_CONSTANT, 0);
	cout << "B = " << B << endl;

	int ksize = border * 2 + 1;

	// medianBlur (패딩 방식 = BORDER_REPLICATE)
	// src영상에서 ksize * ksize 필터 윈도우를 이용하여 중간값(오름차순 배열했을 때 중간에 위치한 값)을 계산해서 dst에 저장한다.
	// 소금-후추 노이즈(임펄스 노이즈)를 평균 필터, 가우시안 필터보다 효과적으로 제거할 수 있다.
	Mat dst1;
	medianBlur(A, dst1, ksize);
	cout << "dst1 = " << dst1 << endl;

	// blur (패딩 방식 = BORDER_REPLICATE101)
	// 윈도우 크기 내의 합의 정규화를 결과로 내는 박스필터를 이용하여 블러링한다. (평균 필터링)
	Mat dst2;
	blur(A, dst2, Size(ksize, ksize));
	cout << "dst2 = " << dst2 << endl;

	return 0;
}
*/