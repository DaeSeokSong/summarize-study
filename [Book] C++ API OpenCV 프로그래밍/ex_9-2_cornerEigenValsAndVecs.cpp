/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\life\\book.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	// cornerEigenValsAndVecs
	// 단일 채널 8비트 또는 실수 입력 영상에서 코너점 검출을 위한 영상 블록의 고유값과 고유 벡터를
	// CV_32FC6 자료형의 dst에 계산한다. Sobel 커널(필터)를 쓴다.
	int blockSize = 5;
	int ksize = 3;
	Mat cornerMap;
	cornerEigenValsAndVecs(srcImg, cornerMap, blockSize, ksize);

	Mat dstImg(srcImg.size(), CV_8UC3);
	cvtColor(srcImg, dstImg, COLOR_GRAY2BGR);

	Vec6f element;
	for (int y = 0; y < cornerMap.rows; y++)
	{
		for (int x = 0; x < cornerMap.cols; x++)
		{
			element = cornerMap.at<Vec6f>(y, x);

			if (element[0] > 0.2 && element[1] > 0.2) // corner points
			{
				circle(dstImg, Point(x, y), 5, Scalar(0, 0, 255), 2);
			}

			if (element[0] > 0.2) // edges
			{
				circle(dstImg, Point(x, y), 1, Scalar(255, 0, 0), 1);
			}
		}
	}
	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}
*/