/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:/example/dataset/lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat fImg;
	srcImg.convertTo(fImg, CV_32F);	// 자료형 변환 8U -> 32F

	double power = 0.2;	// 거듭제곱 수(멱 수)
	Mat powImg;
	// 지수의 값에 의해 다양하게입력 영상을 변환시킬 수 있다.
	// power가 1이면 입력과 출력이 동일, 음수면 로그변환과 유사, 양수면 역로그 변환과 유사하다.
	pow(fImg, power, powImg);

	double minVal, maxVal;
	minMaxLoc(powImg, &minVal, &maxVal);
	cout << "Before normalizing in logImg" << endl;
	cout << "minVal = " << minVal << endl;
	cout << "maxVal = " << maxVal << endl;

	normalize(powImg, powImg, 0, 1.0, NORM_MINMAX);	// 영상의 화소값을 [0, 1] 범위로 정규화
	minMaxLoc(powImg, &minVal, &maxVal);
	cout << "After normalizing in logImg" << endl;
	cout << "minVal = " << minVal << endl;
	cout << "maxVal = " << maxVal << endl;

	imshow("srcImg", srcImg);
	imshow("powImg", powImg);
	waitKey(0);

	return 0;
}
*/