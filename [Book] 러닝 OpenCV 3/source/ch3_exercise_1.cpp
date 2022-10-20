/*
#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>

using namespace std;
using namespace cv;

int main() {
	// 1-a. 음의 부동 소수점 숫자
	double d = -9.80814;

	// 1-b. 절대값 -> 반올림, 올림, 내림값
	cout << "기존값 = " << d << endl;
	cout << "절대값 = " << fabs(d) << endl;
	cout << "올림값 = " << cvCeil(d) << endl;
	cout << "내림값 = " << cvFloor(d) << endl;
	cout << "반올림값 = " << cvRound(d) << endl;
	cout << "===============================" << endl;

	// 1-c. 난수 생성
	srand((uint)time(NULL));
	int r = rand()%100;
	cout << "난수 = " << r << endl;
	cout << "틱 카운트 = " << getTickCount() << endl;
	cout << "===============================" << endl;

	// 1-d. 부동 소수점 cv::Point2f 객체 생성 및 Point 객체와 상호 캐스팅
	Point2f p2f(9102.1124f, 21350.26134f);
	cout << "Point2f = " << p2f << endl;
	cout << "Point2f to Point = " << Point(p2f) << endl;
	cout << "(Point2f to Point) to Point2f = " << Point2f(Point(p2f)) << endl;
	cout << "===============================" << endl;
}
*/