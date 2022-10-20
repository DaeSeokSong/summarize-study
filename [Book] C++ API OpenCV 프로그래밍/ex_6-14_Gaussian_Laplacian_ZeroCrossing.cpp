/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void ZeroCrossing(Mat& src, Mat& dst, int threshold);

int main() {
	Mat srcImg = imread("D:\\example\\dataset\\lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;
	imshow("srcImg", srcImg);

	int ksize = 11;
	Mat blurImg;
	GaussianBlur(srcImg, blurImg, Size(ksize, ksize), 0.0);
	imshow("GaussianBlur Img", blurImg);

	Mat lapImg;
	Laplacian(blurImg, lapImg, CV_32F, ksize);
	imshow("Laplacian Img", blurImg);

	Mat dstImg;
	ZeroCrossing(lapImg, dstImg, 10);
	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}

// 0-교차 화소에서 임계값 th(10)을 적용해서 이진영상 생성
void ZeroCrossing(Mat& src, Mat& dst, int th) {
	int x, y;
	double a, b;

	Mat zeroCrossH(src.size(), CV_32F, Scalar::all(0));
	Mat_<float> _src(src);
	for (y = 1; y < src.rows - 1; y++) {
		for (x = 1; x < src.cols - 1; x++) {
			a = _src(y, x);
			b = _src(y, x - 1);
			if (a == 0) a = _src(y, x - 1);

			if (a * b < 0) zeroCrossH.at<float>(y, x) = fabs(a) + fabs(b);
			else zeroCrossH.at<float>(y, x) = 0;
		}
	}

	Mat zeroCrossV(src.size(), CV_32F, Scalar::all(0));
	for (y = 1; y < src.rows - 1; y++) {
		for (x = 1; x < src.cols - 1; x++) {
			a = _src(y, x);
			b = _src(y, x - 1);
			if (a == 0) a = _src(y, x - 1);

			if (a * b < 0) zeroCrossV.at<float>(y, x) = fabs(a) + fabs(b);
			else zeroCrossV.at<float>(y, x) = 0;
		}
	}

	Mat zeroCross(src.size(), CV_32F, Scalar::all(0));
	add(zeroCrossH, zeroCrossV, zeroCross);
	threshold(zeroCross, dst, th, 255, THRESH_BINARY);
}
*/