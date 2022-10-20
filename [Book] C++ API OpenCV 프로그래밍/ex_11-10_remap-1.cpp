/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat mapX, mapY;
	mapX.create(srcImg.size(), CV_32FC1);
	mapY.create(srcImg.size(), CV_32FC1);

	for (int y = 0; y < srcImg.rows; y++)
	{
		for (int x = 0; x < srcImg.cols; x++)
		{
			mapX.at<float>(y, x) = x;
			//mapX.at<float>(y, x) = srcImg.cols - x;
			mapY.at<float>(y, x) = srcImg.rows - y;
		}
	}

	Mat dstImg(srcImg.size(), srcImg.type());
	//remap
	//입력 영상을 두 개의 변환 좌표 행렬을 이용하여 변환시킨 출력 영상을 반환한다.
	//x와 y에 대해 각각 변환 행렬을 따로 줄 수 있다.
	remap(srcImg, dstImg, mapX, mapY, INTER_LINEAR);

	imshow("srcImg", srcImg);
	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}
*/