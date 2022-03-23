/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:/example/dataset/lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	double minVal, maxVal;
	Point minLoc, maxLoc;
	minMaxLoc(srcImg, &minVal, &maxVal, &minLoc, &maxLoc);
	cout << "In srcImg" << endl;
	cout << "minVal = " << minVal << endl;
	cout << "maxVal = " << maxVal << endl;
	cout << "minLoc = " << minLoc << endl;
	cout << "maxLoc = " << maxLoc << endl;

	Mat dstImg;
	double scale = 100.0 / (maxVal - minVal);
	// 선형 변환은 입력영상의 값을 기울기가 scale, y절편이 shift인 직선의 방정식에 의한 변환이다.
	srcImg.convertTo(dstImg, -1, scale, -scale * minVal); // 0~100 범위로 선형 번환
	// normalize(srcImg, dstImg, 0, 100, NORM_MINMAX); 0~100 범위로 선형 번환

	minMaxLoc(dstImg, &minVal, &maxVal, &minLoc, &maxLoc);
	cout << "In dstImg" << endl;
	cout << "minVal = " << minVal << endl;
	cout << "maxVal = " << maxVal << endl;
	cout << "minLoc = " << minLoc << endl;
	cout << "maxLoc = " << maxLoc << endl;

	imshow("srcImg", srcImg);
	imshow("dstImg", dstImg);
	waitKey(0);

	return 0;
}
*/