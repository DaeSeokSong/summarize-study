/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\momentTest.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	// moments
	// 경계선을 나타내는 다각형 또는 영상의 3차 모멘트까지 계산한다.
	// Moments 클래스를 반환하는데, 공간/중심/정규화된 중신 모멘트가 계산된다.
	Moments M = moments(srcImg, true);

	// 무게 중심점
	Point2f center;
	center.x = M.m10 / M.m00;
	center.y = M.m01 / M.m00;

	Mat dstImg;
	cvtColor(srcImg, dstImg, COLOR_GRAY2BGR);
	circle(dstImg, center, 5, Scalar(0, 0, 255), -1);
	imshow("dstImg", dstImg);

	// HuMoments
	// moments 함수로 계산한 모멘트 또는 moments에서 Hu의 이동, 스케일, 회전에 불변인 모멘트 hu는
	// 정규화된 중심 모멘트를 이용하여 Hu의 7 모멘트를 계산한다.
	// 제한된 해상도의 물체 영상의 Hu 모멘트와 이동, 스케일, 회전의 변환 영상에서
	// 계산된 Hu 모멘트는 다를 수 있지만 거의 같다.
	Mat hu;
	HuMoments(M, hu);
	for (int i = 0; i < hu.rows; i++)
	{
		cout << "hu[" << i << "] = ";
		cout << hu.at<double>(i) << endl;
	}

	waitKey(0);
	return 0;
}
*/