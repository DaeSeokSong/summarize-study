/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void PrintMat(const char* strName, Mat src);

int main()
{
	uchar dataA[] = { 0, 0, 0, 0, 0, 0, 0,
					0, 1, 1, 1, 1, 1, 0,
					0, 1, 1, 1, 1, 1, 0,
					0, 1, 1, 1, 1, 1, 0,
					0, 1, 1, 1, 1, 1, 0,
					0, 1, 1, 1, 1, 1, 0,
					0, 0, 0, 0, 0, 0, 0};
	Mat A(7, 7, CV_8U, dataA);

	int distanceType = DIST_L1;
	int maskSize = 5;
	Mat labels;
	Mat distance;

	distanceTransform(A, distance, labels, distanceType, maskSize, DIST_LABEL_PIXEL);
	PrintMat("distance = ", distance);
	PrintMat("labels = ", labels);

	waitKey(0);
	return 0;
}

void PrintMat(const char *strName, Mat src)
{
	int x, y;
	uchar uValue;
	float fValue;
	double dValue;
	int iValue;

	cout << endl << endl << strName << endl;
	cout << setiosflags(ios::fixed);
	for (y = 0; y < src.rows; y++)
	{
		for (x = 0; x < src.cols; x++)
		{
			switch (src.type())
			{
			case CV_8U:
				uValue = src.at<uchar>(y, x);
				cout << setw(4) << (int)uValue;
				break;
			case CV_32S:
				iValue = src.at<int>(y, x);
				cout << setw(4) << iValue;
				break;
			case CV_32F:
				fValue = src.at<float>(y, x);
				cout << setprecision(1) << setw(5) << fValue;
				break;
			case CV_64F:
				dValue = src.at<double>(y, x);
				cout << setprecision(1) << setw(5) << dValue;
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}
*/