/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:/example/dataset/lena_color.png");
	if (srcImg.empty()) return -1;
	imshow("srcImg", srcImg);

	Mat grayImg;
	cvtColor(srcImg, grayImg, COLOR_BGR2GRAY);
	imshow("grayImg", grayImg);

	Mat hsvImg;
	cvtColor(srcImg, hsvImg, COLOR_BGR2HSV);
	imshow("hsvImg", hsvImg);

	Mat yCrCbImg;
	cvtColor(srcImg, yCrCbImg, COLOR_BGR2YCrCb);
	imshow("yCrCbImg", yCrCbImg);

	Mat luvImg;
	cvtColor(srcImg, luvImg, COLOR_BGR2Luv);
	imshow("luvImg", luvImg);

	waitKey(0);

	return 0;
}
*/