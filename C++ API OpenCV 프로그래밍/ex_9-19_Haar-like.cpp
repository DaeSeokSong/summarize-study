/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

enum HAAR_TYPE {HORZ2, VERT2, CENT3, DIAG4};

double HaarLikeFeature(Mat& sumA, Size windowSize, HAAR_TYPE HaarType);
void PrintMat(const char* strName, Mat A);

int main()
{
	uchar dataA[36] = { 1, 2, 3, 4, 5, 6,
						7, 8, 9, 10, 11, 12,
						13, 14, 15, 16, 17, 18,
						19, 20, 21, 22, 23, 24,
						25, 26, 27, 28, 29, 30,
						31, 32, 33, 34, 35, 36 };
	Mat A(Size(6, 6), CV_8U, dataA);
	PrintMat("A = ", A);

	Mat sumA;
	integral(A, sumA);
	PrintMat("sumA = ", sumA);

	Size windowSize = A.size();
	double fH = HaarLikeFeature(sumA, windowSize, HORZ2);
	double fV = HaarLikeFeature(sumA, windowSize, VERT2);
	double fC = HaarLikeFeature(sumA, windowSize, CENT3);
	double fD = HaarLikeFeature(sumA, windowSize, DIAG4);

	cout << "fH = " << fH << endl;
	cout << "fV = " << fV << endl;
	cout << "fC = " << fC << endl;
	cout << "fD = " << fD << endl;

	waitKey(0);
	return 0;
}

double rectSum(Mat& sumA, Rect r)
{
	Mat_<int> tmpSum(sumA);

	double a, b, c, d;
	a = tmpSum(r.y, r.x);
	b = tmpSum(r.y, r.x + r.width);
	c = tmpSum(r.y + r.height, r.x);
	d = tmpSum(r.y + r.height, r.x + r.width);

	return (a + d - b - c);
}

double HaarLikeFeature(Mat& sumA, Size windowSize, HAAR_TYPE HaarType)
{
	double sum1, sum2, sum3, sum4;
	double fValue = 0;

	Rect r1, r2, r3, r4;
	int widthD2 = windowSize.width / 2;
	int heightD2 = windowSize.height / 2;
	int widthD3 = windowSize.width / 3;
	int heightD3 = windowSize.height / 3;

	switch (HaarType)
	{
		case HORZ2 :
			// White Rect
			r1 = Rect(0, 0, windowSize.width, heightD2);
			sum1 = rectSum(sumA, r1);

			// Black Rect
			r2 = Rect(0, heightD2, windowSize.width, heightD2);
			sum2 = rectSum(sumA, r2);

			fValue = sum1 - sum2;
			break;
		case VERT2:
			// White Rect
			r1 = Rect(0, 0, widthD2, windowSize.height);
			sum1 = rectSum(sumA, r1);

			// Black Rect
			r2 = Rect(widthD2, 0, widthD2, windowSize.height);
			sum2 = rectSum(sumA, r2);

			fValue = sum2 - sum1;
			break;
		case CENT3:
			r1 = Rect(0, 0, widthD3, windowSize.height);
			sum1 = rectSum(sumA, r1);

			r2 = Rect(widthD3, 0, widthD3, windowSize.height);
			sum2 = rectSum(sumA, r2);

			r3 = Rect(widthD3 * 2, 0, widthD3, windowSize.height);
			sum3 = rectSum(sumA, r3);

			fValue = sum1 + sum3 - sum2;
			break;
		case DIAG4:
			r1 = Rect(0, 0, widthD2, heightD2);
			sum1 = rectSum(sumA, r1);

			r2 = Rect(widthD2, 0, widthD2, heightD2);
			sum2 = rectSum(sumA, r2);

			r3 = Rect(0, heightD2, widthD2, heightD2);
			sum3 = rectSum(sumA, r3);

			r4 = Rect(widthD2, heightD2, widthD2, heightD2);
			sum4 = rectSum(sumA, r4);

			fValue = sum2 + sum3 - sum1 - sum4;
			break;
	}
	return fValue;
}

void PrintMat(const char* strName, Mat A)
{
	int x, y;
	uchar uValue;
	float fValue;
	double dValue;
	int iValue;

	cout << endl << endl << strName << endl;
	cout << setiosflags(ios::fixed);
	for (y = 0; y < A.rows; y++)
	{
		for (x = 0; x < A.cols; x++)
		{
			switch (A.type())
			{
			case CV_8U:
				uValue = A.at<uchar>(y, x);
				cout << setw(8) << (int)uValue;
				break;
			case CV_32S:
				iValue = A.at<int>(y, x);
				cout << setw(8) << iValue;
				break;
			case CV_32F:
				fValue = A.at<float>(y, x);
				cout << setprecision(2) << fValue;
				break;
			case CV_64F:
				dValue = A.at<double>(y, x);
				cout << setprecision(2) << dValue;
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}
*/