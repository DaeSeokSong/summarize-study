/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat pyrImgD[3];
	pyrImgD[0] = srcImg.clone();
	imshow("pryImgD[0]", pyrImgD[0]);

	pyrDown(pyrImgD[0], pyrImgD[1]);
	imshow("pryImgD[1]", pyrImgD[1]);

	pyrDown(pyrImgD[1], pyrImgD[2]);
	imshow("pryImgD[2]", pyrImgD[2]);

	Mat pyrImgU[2];
	pyrUp(pyrImgD[1], pyrImgU[0]);
	imshow("pyrImgU[0])", pyrImgU[0]);

	pyrUp(pyrImgD[2], pyrImgU[1]);
	imshow("pyrImgU[1])", pyrImgU[1]);

	waitKey(0);
	return 0;
}
*/