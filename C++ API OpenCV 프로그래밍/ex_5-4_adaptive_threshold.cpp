/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:/example/dataset/lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat dstImg1;
	adaptiveThreshold(srcImg, dstImg1, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 21, 5);

	Mat dstImg2;
	adaptiveThreshold(srcImg, dstImg2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 21, 5);

	imshow("srcImg", srcImg);
	imshow("dstImg1", dstImg1);
	imshow("dstImg2", dstImg2);
	waitKey(0);

	return 0;
}
*/