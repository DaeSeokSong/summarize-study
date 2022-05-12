/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	// resize
	// 입력영상을 INTER(interpolation)에 제시된 방법을 사용하여 dsize(출력영상 크기)로 출력영상을 만든다.
	// fx는 수평축의 스케일, fy는 수직축의 스케일 크기이다.
	Mat dstImg1(320, 240, CV_8U);
	resize(srcImg, dstImg1, dstImg1.size(), 0, 0, INTER_AREA); // 화소 영역관계를 이용한 재샘플링, 영상 축소
	imshow("dstImg1", dstImg1);

	Mat dstImg2;
	resize(srcImg, dstImg2, Size(), 1.2, 1.4, INTER_LINEAR); // 양방향 선형 보간, 영상 확대
	imshow("dstImg2", dstImg2);

	// INTER_NEAREST, 최근접 이웃보간
	// INTER_CUBIC, 4*4 이웃을 이용한 양방향 3차보간, 영상 확대

	waitKey(0);
	return 0;
}
*/