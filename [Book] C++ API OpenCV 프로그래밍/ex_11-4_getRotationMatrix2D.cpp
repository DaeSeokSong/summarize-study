/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;
	else resize(srcImg, srcImg, Size(512, 512));

	Point2f center(256.0f, 256.0f);
	double angle = -45.0;
	double scale = 1.0;

	//getRotationMatrix2D
	//2D 회전 및 확대를 위한 어파인 변환 행렬을 계산한다.
	//center를 중심으로 angle 각도를 회전하고 scale 만큼 확대/축소하는 2*3 변환행렬을 반환한다.
	//angle은 라디안이 아니라 각도다.
	Mat rotMat = getRotationMatrix2D(center, angle, scale);

	Point pt1(400, 256);
	Mat A(3, 1, CV_64F);
	A.at<double>(0, 0) = (double)pt1.x;
	A.at<double>(1, 0) = (double)pt1.y;
	A.at<double>(2, 0) = 1.0;
	Mat B = rotMat * A;

	Point pt0;
	pt0.x = cvRound(center.x);
	pt0.y = cvRound(center.y);
	line(srcImg, Point(pt0.x, 0), Point(pt0.x, srcImg.rows - 1), Scalar(0, 0, 255));
	line(srcImg, Point(0, pt0.y), Point(srcImg.cols - 1, pt0.y), Scalar(0, 0, 255));
	circle(srcImg, pt0, 5, Scalar(0, 255, 0), 1);

	line(srcImg, pt0, pt1, Scalar(255, 0, 0), 2);

	Point pt2;
	pt2.x = cvRound(B.at<double>(0, 0));
	pt2.y = cvRound(B.at<double>(1, 0));
	line(srcImg, pt0, pt2, Scalar(0, 0, 255), 2);

	putText(srcImg, "pt0", Point(pt0.x - 30, pt0.y + 20), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 255), 2);
	putText(srcImg, "pt1", pt1, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 255), 2);
	putText(srcImg, "pt2", pt2, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 255), 2);

	imshow("srcImg", srcImg);

	waitKey(0);
	return 0;
}
*/