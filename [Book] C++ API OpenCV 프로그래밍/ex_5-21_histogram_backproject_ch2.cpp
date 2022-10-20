/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 히스토그램, 관찰 데이터의 빈도수를 막대그래프로 표시한 것, 데이터의 확률밀도 함수를 추정할 수 있다.
// 역투영 Ex1. 피부 영역의 히스토그램을 계산한 후 영투영하면, 손 / 얼굴 등의 영역을 분할할 수 있다.
// 역투영 Ex2. 물체 추적시 추적할 물체를 관심영역 지정하고 컬러 정보(Hue)를 히스토그램으로 계산하고, 계산된 히스토그램을 비디오에 역투영하고 이진화(임계치)하면 컬러정보가 비슷한 영역만 검출 가능하다.
// findContours 함수로 물체의 경계 검출하고, 물체 추적 방법인 meanShift랑 CamShift에서 역투영을 사용한다.
int main() {
	uchar dataA[16]{ 0, 0, 0, 0,
					1, 1, 1, 1,
					1, 1, 1, 2,
					1, 2, 1, 3 };
	Mat A(4, 4, CV_8UC2, dataA);
	cout << "A = " << A << endl;

	int histSize[] = { 4, 4 };
	float range1[] = { 0, 4 };
	float range2[] = { 0, 4 };
	const float* ranges[] = { range1, range2 };
	int channels[] = { 0, 1 };
	int dims = 2;

	Mat hist;
	calcHist(&A, 1, channels, Mat(), hist, dims, histSize, ranges, true);
	cout << "hist = " << hist << endl;

	Mat backProject;
	calcBackProject(&A, 1, channels, hist, backProject, ranges);
	cout << "backProject = " << backProject << endl;

	return 0;
}
*/