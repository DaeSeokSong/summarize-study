#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void lena_edge_detect();
void canny_edge();

int main()
{
	//// Ex1
	//lena_edge_detect();

	// Ex2
	canny_edge();

	return 0;
}

void lena_edge_detect()
{
	Mat src = imread("lena.jpg", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return;
	}

	float filter[] = { -1.f, 0.f, 1.f };
	Mat maskX(3, 1, CV_32F, filter);
	Mat maskY(1, 3, CV_32F, filter);

	Mat srcPdX, srcPdY;
	filter2D(src, srcPdX, -1, maskX);
	filter2D(src, srcPdY, -1, maskY);
	
	Mat srdGrd(src.size(), src.type());
	for (int y = 0; y < srdGrd.rows; y++)
	{
		for (int x = 0; x < srdGrd.cols; x++)
		{
			float fx = pow(srcPdX.at<float>(y, x), 2);
			float fy = pow(srcPdY.at<float>(y, x), 2);
			float grad = sqrt(fx + fy);

			if (grad > 30)
				srdGrd.at<uchar>(y, x) = 255;
			else
				srdGrd.at<uchar>(y, x) = 0;
		}
	}

	imshow("src", src);
	imshow("srcPdX", srcPdX);
	imshow("srcPdY", srcPdY);
	imshow("srdGrd", srdGrd);
	
	waitKey(0);
}

void canny_edge()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return;
	}

	Mat dst1, dst2;
	Canny(src, dst1, 50, 100);
	Canny(src, dst2, 50, 150);

	Mat srcSobel;
	Sobel(src, srcSobel, -1, 1, 0);
	Mat dst3;
	Canny(src, dst3, 50, 150);

	imshow("src", src);
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);

	waitKey(0);
}