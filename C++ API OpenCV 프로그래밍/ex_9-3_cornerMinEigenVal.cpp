/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\life\\book.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	// cornerMinEigenVal
	// 단일 채널 8비트 또는 실수 입력 영상에서 코너점 검출을 위한 영상 블록의 고유값과 고유 벡터를
	// CV_32FC6 자료형의 dst에 계산한다. Sobel 커널(필터)를 쓴다.
	// cornerEigenValsAndVecs와 유사하지만 최소 고유값만을 dst에 저장한다.
	// 작은 고유 값이 임계값보다 큰 화소가 코너점이 된다.
	int blockSize = 5;
	int ksize = 3;
	Mat eigenVal;
	cornerMinEigenVal(srcImg, eigenVal, blockSize, ksize);

	Mat dstImg(srcImg.size(), CV_8UC3);
	cvtColor(srcImg, dstImg, COLOR_GRAY2BGR);

	float eval;
	for (int y = 0; y < eigenVal.rows; y++)
	{
		for (int x = 0; x < eigenVal.cols; x++)
		{
			eval = eigenVal.at<float>(y, x);

			if (eval > 0.2) // corner points
			{
				circle(dstImg, Point(x, y), 5, Scalar(0, 255, 0), 2);
			}
		}
	}
	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}
*/