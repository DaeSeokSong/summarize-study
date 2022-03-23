/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:/example/dataset/lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat dstImg1;
	double th1 = threshold(srcImg, dstImg1, 100, 255, THRESH_BINARY);
	cout << "th1 = " << th1 << endl;

	Mat dstImg2;
	double th2 = threshold(srcImg, dstImg2, 100, 255, THRESH_BINARY + THRESH_OTSU);
	cout << "th2 = " << th2 << endl;

	imshow("srcImg", srcImg);
	imshow("dstImg1", dstImg1);
	imshow("dstImg2", dstImg2);
	waitKey(0);

	return 0;
}
*/