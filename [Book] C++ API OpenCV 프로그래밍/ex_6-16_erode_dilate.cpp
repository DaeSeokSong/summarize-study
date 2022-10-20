/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 모폴로지, Morphology
// 모폴로지 연산은 구조요소를 이용하여 반복적으로 영역을 확장시켜 떨어진 부분 또는 구멍을 채우거나,
// 잡음을 축소하여 제거하는 등의 연산으로 침식(erode), 팽창(dilate), 열기(opening), 닫기(closing) 등이 있다.
int main() {
	Mat srcImg = imread("D:\\example\\dataset\\morphology.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;
	imshow("srcImg", srcImg);

	Size size(5, 5);
	// getStructuringElement
	// 모폴로지 연산을 위한 ksize 크기의 모양 shape 구조 요소를 반환한다.
	Mat rectKernel = getStructuringElement(MORPH_RECT, size);
	int iterations = 3;
	Point anchor(-1, -1);

	Mat erodeImg;
	// erode
	// 입력영상에 이웃을 결정하는 구조 요소 kernel을 적용하여 모폴로지 침식 연산을 iterations 만큼 반복하여 출력영상을 만든다.
	// kernel=Mat()이면, 3*3 사각형 구조 요소를 사용한다. 채널의 제한수는 없으며,
	// 그레이-스케일 영상에서는 반복적인 min 필터리과 같다. 지역 극소값을 계산할 수 있다.
	erode(srcImg, erodeImg, rectKernel, anchor, iterations);
	imshow("erodeImg", erodeImg);
	Mat dilateImg;
	// dilate
	// 입력영상에 이웃을 결정하는 구조 요소 kernel을 적용하여 모폴로지 팽창 연산을 iterations 만큼 반복하여 출력영상을 만든다.
	// kernel=Mat()이면, 3*3 사각형 구조 요소를 사용한다. 채널의 제한수는 없으며,
	// 그레이-스케일 영상에서는 반복적인 max 필터리과 같다. 지역 극대값을 계산할 수 있다.
	dilate(srcImg, dilateImg, rectKernel, anchor, iterations);
	imshow("dilateImg", dilateImg);

	Mat ellipseKernel = getStructuringElement(MORPH_ELLIPSE, size);

	Mat erodeImg2;
	erode(srcImg, erodeImg2, ellipseKernel, anchor, iterations);
	imshow("erodeImg2", erodeImg2);
	Mat dilateImg2;
	dilate(srcImg, dilateImg2, ellipseKernel, anchor, iterations);
	imshow("dilateImg2", dilateImg2);

	Mat crossKernel = getStructuringElement(MORPH_CROSS, size);

	Mat erodeImg3;
	erode(srcImg, erodeImg3, crossKernel, anchor, iterations);
	imshow("erodeImg3", erodeImg3);
	Mat dilateImg3;
	dilate(srcImg, dilateImg3, crossKernel, anchor, iterations);
	imshow("dilateImg3", dilateImg3);

	waitKey(0);
	return 0;
}
*/