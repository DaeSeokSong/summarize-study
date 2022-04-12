/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat img = imread("D:/example/dataset/전신 골격 원자선 스캔.png");
	cvtColor(img, img, COLOR_BGR2GRAY);

	Mat laplacianImg;
	Laplacian(img, laplacianImg, CV_16S);

	Mat sharpedImg;
	add(img, laplacianImg, sharpedImg);

	Mat sobeledImg = imread("D:/example/dataset/전신 골격 원자선 스캔_소벨 필터.png");
	cvtColor(sobeledImg, sobeledImg, COLOR_BGR2GRAY);

	Mat smothingImg;
	medianBlur(sobeledImg, smothingImg, 5);

	Mat mulImg;
	multiply(smothingImg, sharpedImg, mulImg);
	mulImg = ~(mulImg - smothingImg);

	Mat sumImg;
	add(img, mulImg, sumImg);

	imshow("Original", img);
	imshow("Laplacian", laplacianImg);
	imshow("Sharp", sharpedImg);
	imshow("Sobel", sobeledImg);
	imshow("Smothing", smothingImg);
	imshow("Multipy", mulImg);
	imshow("Result", sumImg);
	waitKey(0);

	return 0;
}
*/