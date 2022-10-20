/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void PrintMat(const char* strName, Mat A);

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Rect rtROI(100, 100, 10, 10);
	Mat roi = srcImg(rtROI);
	PrintMat("roi = ", roi);

	Point2f center(105.0f, 105.0f);
	Size patchSize(5, 5);
	Mat patch;

	// getRectSubPix
	// 입력영상에서 center를 중심점으로 하는 patchSize 크기의 화소값을 읽어 patch 행렬에 저장한다.
	// 정수가 아닌 좌표에서의 화소값은 양방향 선형보간으로 계산한다.
	// center는 반드시 입력영상 좌표 내부에 있어야 하지만, patchSize는 영상의 크기를 넘어도 된다.
	getRectSubPix(srcImg, patchSize, center, patch, CV_32F);
	PrintMat("patch = ", patch);

	waitKey(0);
	return 0;
}

void PrintMat(const char* strName, Mat A)
{
	int x, y;
	uchar uValue;
	float fValue;
	double dValue;
	int iValue;

	std::cout << endl << strName << endl;
	std::cout << setiosflags(ios::fixed);
	for (y = 0; y < A.rows; y++)
	{
		for (x = 0; x < A.cols; x++)
		{
			switch (A.type())
			{
			case CV_8U:
				uValue = A.at<uchar>(y, x);
				std::cout << setw(6) << (int)uValue;
				break;
			case CV_32S:
				iValue = A.at<int>(y, x);
				std::cout << setw(6) << iValue;
				break;
			case CV_32F:
				fValue = A.at<float>(y, x);
				std::cout << setprecision(2) << setw(8) << fValue;
				break;
			case CV_64F:
				dValue = A.at<double>(y, x);
				std::cout << setprecision(2) << setw(8) << dValue;
				break;
			}
		}
		std::cout << endl;
	}
	std::cout << endl;
}
*/