/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:/example/dataset/lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat fImg;
	srcImg.convertTo(fImg, CV_32F);	// 자료형 변환 8U -> 32F
	add(fImg, Scalar(1), fImg);

	// 입력값 r에 대한 log 값을 출력영상에 저장, log(1+|r|), 입력값의 범위가 넓을 때 효과적이다.
	Mat logImg;
	log(fImg, logImg);

	double minVal, maxVal;
	minMaxLoc(logImg, &minVal, &maxVal);
	cout << "Before normalizing in logImg" << endl;
	cout << "minVal = " << minVal << endl;
	cout << "maxVal = " << maxVal << endl;

	normalize(logImg, logImg, 0, 1.0, NORM_MINMAX);	// 영상의 화소값을 [0, 1] 범위로 정규화
	minMaxLoc(logImg, &minVal, &maxVal);
	cout << "After normalizing in logImg" << endl;
	cout << "minVal = " << minVal << endl;
	cout << "maxVal = " << maxVal << endl;

	imshow("srcImg", srcImg);
	imshow("logImg", logImg);
	waitKey(0);

	return 0;
}
*/