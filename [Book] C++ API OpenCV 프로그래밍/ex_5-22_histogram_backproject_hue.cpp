/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 히스토그램, 관찰 데이터의 빈도수를 막대그래프로 표시한 것, 데이터의 확률밀도 함수를 추정할 수 있다.
// 역투영 Ex1. 피부 영역의 히스토그램을 계산한 후 영투영하면, 손 / 얼굴 등의 영역을 분할할 수 있다.
// 역투영 Ex2. 물체 추적시 추적할 물체를 관심영역 지정하고 컬러 정보(Hue)를 히스토그램으로 계산하고, 계산된 히스토그램을 비디오에 역투영하고 이진화(임계치)하면 컬러정보가 비슷한 영역만 검출 가능하다.
// findContours 함수로 물체의 경계 검출하고, 물체 추적 방법인 meanShift랑 CamShift에서 역투영을 사용한다.
int main() {
	Mat srcImg = imread("D:/example/dataset/lena_color.png");
	if (srcImg.empty()) return -1;

	Mat hsvImg;
	cvtColor(srcImg, hsvImg, COLOR_BGR2HSV);
	vector<Mat> planes;
	split(hsvImg, planes);
	Mat hueImg = planes[0];

	Rect roi(100, 400, 100, 100);
	rectangle(srcImg, roi, Scalar(0, 0, 255), 2);
	Mat roiImg = hueImg(roi);

	int histSize = 256;
	float hValue[] = { 0, 256 };
	const float* ranges[] = { hValue };
	int channels = 0;
	int dims = 1;

	Mat hist;
	calcHist(&roiImg, 1, &channels, Mat(), hist, dims, &histSize, ranges);

	Mat hueImg2;
	hueImg.convertTo(hueImg2, CV_32F);

	Mat backProject;
	calcBackProject(&hueImg2, 1, &channels, hist, backProject, ranges);

	double minVal, maxVal;
	minMaxLoc(backProject, &minVal, &maxVal);

	Mat backProject2;
	normalize(backProject, backProject2, 0, 255, NORM_MINMAX, CV_8U);

	imshow("backProject2", backProject2);
	imshow("srcImg", srcImg);

	waitKey(0);

	return 0;
}
*/