/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg1 = imread("D:\\example\\dataset\\ChessBoard1.jpg", IMREAD_GRAYSCALE);
	Mat srcImg2 = imread("D:\\example\\dataset\\ChessBoard3.jpg", IMREAD_GRAYSCALE);
	if (srcImg1.empty() || srcImg2.empty())
	{
		cout << "사진 불러오기 실패" << endl;
		return -1;
	}

	//findChessboardCorners
	//체스보드 패턴의 내부 코너점의 위치를 순차적으로 검출한다.
	//코너점은 행우선 순서로 검출하고, 왼쪽에서 오른쪽으로 정렬하여 반환한다.
	//cornerSubPix 함수를 추가적으로 사용하면, 부화소단위로 정확환 좌표를 검출할 수 있다.
	Size patternsize(5, 5);
	vector<Point2f> corners1;
	bool bfound1 = findChessboardCorners(srcImg1, patternsize, corners1);
	vector<Point2f> corners2;
	bool bfound2 = findChessboardCorners(srcImg2, patternsize, corners2);

	//drawChessboardCorners
	//findChessboardCorners 함수에 의해 검출된 코너점 벡터를 영상에 표시한다.
	Mat dstImg1;
	cvtColor(srcImg1, dstImg1, COLOR_GRAY2BGR);
	drawChessboardCorners(dstImg1, patternsize, corners1, bfound1);
	imshow("dstImg1", dstImg1);
	waitKey(0);

	Mat dstImg2;
	cvtColor(srcImg2, dstImg2, COLOR_GRAY2BGR);
	drawChessboardCorners(dstImg2, patternsize, corners2, bfound2);
	imshow("dstImg2", dstImg2);
	waitKey(0);

	Mat M = findHomography(corners1, corners2, RANSAC);

	vector<Point2f> dstCorners;
	perspectiveTransform(corners1, dstCorners, M);
	for (int i = 0; i < dstCorners.size(); i++)
	{
		circle(dstImg2, dstCorners[i], 5, Scalar(255, 255, 0), -1);
	}
	imshow("dstImg2", dstImg2);
	waitKey(0);

	return 0;
}
*/