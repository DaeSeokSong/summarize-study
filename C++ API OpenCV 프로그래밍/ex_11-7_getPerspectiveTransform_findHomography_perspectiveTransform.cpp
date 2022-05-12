/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png");
	if (srcImg.empty()) return -1;
	else resize(srcImg, srcImg, Size(512, 512));

	Point2f srcP[] = { Point2f(100.0f, 100.0f),
						Point2f(50.0f, 200.0f),
						Point2f(150.0f, 250.0f),
						Point2f(150.0f, 150.0f) };
	Point2f dstP[] = { Point2f(400.0f, 50.0f),
						Point2f(350.0f, 150.0f),
						Point2f(400.0f, 250.0f),
						Point2f(450.0f, 120.0f) };

	vector<Point2f> srcV(srcP, srcP + sizeof(srcP) / sizeof(srcP[0]));
	vector<Point2f> dstV(dstP, dstP + sizeof(dstP) / sizeof(dstP[0]));

	for (int i = 0; i < srcV.size(); i++)
	{
		line(srcImg, srcV[i], srcV[(i + 1) % 4], Scalar(255, 0, 0), 2);
		line(srcImg, dstV[i], dstV[(i + 1) % 4], Scalar(0, 0, 255), 2);
	}

	Mat M;
	//getPerspectiveTransform
	//사각형을 이루는 4개의 대응 좌표점을 입력에서 3*3 투영 변환 행렬을 계산하여 결과 영상을 반환한다.
	M = getPerspectiveTransform(srcP, dstP);

	vector<Point2f> dstV2;
	//perspectiveTransform
	//변환 행렬에 맞게 입력 행렬을 투영 변환한다.
	perspectiveTransform(srcV, dstV2, M);
	for (int i = 0; i < srcV.size(); i++)
	{
		line(srcImg, srcV[i], dstV2[i], Scalar(0, 255, 0), 2);
	}
	imshow("srcImg", srcImg);
	waitKey(0);

	Mat A(3, 1, CV_64F);
	Mat B;
	for (int i = 0; i < srcV.size(); i++)
	{
		A.at<double>(0, 0) = srcV[i].x;
		A.at<double>(1, 0) = srcV[i].y;
		A.at<double>(2, 0) = 1.0;
		B = M * A;

		float w = B.at<double>(2, 0);
		float x = B.at<double>(0, 0) / w;
		float y = B.at<double>(1, 0) / w;

		Point2f pt2(x, y);
		line(srcImg, srcV[i], pt2, Scalar(0, 255, 255), 2);
	}
	imshow("srcImg", srcImg);
	waitKey(0);

	return 0;
}
*/