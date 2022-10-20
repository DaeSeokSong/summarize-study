/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void Printmat(const char* strName, Mat m);

// 템플릿 매칭
// 참조 영상에서 템플릿 영상과 매칭되는 위치를 탐색하는 방법이다. 템플릿 매칭은 물체 인식, 스테레오 영상에서 대응점 검출 등에 사용될 수 있다.
// 참조 영상의 (0, 0) 위치에 템플릿 영상의 (0, 0)을 맞추고 래스터 주사 순서로 왼쪽부터 오른쪽, 위부터 아래를 시작 엣지부터 끝 엣지까지 옮길 때 마다
// 템플릿 영상과 템플릿 영상의 해당 위치에 있는 참조 영상의 화소값을 비교하여 연산한다.
// 템플릿 매칭은 이동 문제는 해결할 수 있지만, 회전 및 스케일링된 물체에 대한 매칭은
// 템플릿을 회전 및 스케일링해가며 여러 개의 템플릿을 이용한 매칭 방법도 있으나, 어려운 문제다.
// 영상의 밝기를 그대로 사용할 수도 있고, 엣지, 코너점, 주파수 변황 등 특징 공간으로 변환하여 매칭을 수행할 수 있으며,
// 밝기 등에 덜 민감하도록 정규화가 필요하다.
// 매칭 방법은 상관관계(Correlation), SAD(Sum of Absolute Difference) 등을 사용한다.
int main() {
	float dataA[] = { 1, 1, 1, 1, 1, 1,
					1, 1, 1, 1, 1, 1,
					1, 1, 9, 9, 1, 1,
					1, 1, 9, 9, 1, 1,
					1, 1, 1, 1, 1, 1,
					1, 1, 1, 1, 1, 1 };
	float dataB[] = { 9, 9, 1,
					9, 9, 1,
					1, 1, 1 };
	Mat A(6, 6, CV_32F, dataA);
	Printmat("A = ", A);
	Mat B(3, 3, CV_32F, dataB);
	Printmat("B = ", B);

	double minVal, maxVal;
	Point minLoc, maxLoc;
	Mat result;

	// matchTemplate
	// 참조 영상에서 두 번째 매개변수를  method 방법(네 번째 매개변수)에 따라 템플릿 매칭을 계산하여 result(세 번째 매개변수)에 반환한다.
	// 템플릿 매칭 위치를 찾기 위해서는 result에 minMaxLoc 함수를 사용하여 찾을 수 있다. 최소값은 TM_SQDIFF, 최대값은 TM_CCORR, TM_CCOEFF
	// 같은 값의 최대/최소값이 있다면 처음 위치만 찾는다.

	// TM_SQDIFF, 매칭되는 위치에서 작은 값을 갖는다.
	matchTemplate(A, B, result, TM_SQDIFF);
	Printmat("result: TM_SQDIFF = ", result);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	cout << "TM_SQDIFF" << endl;
	cout << "minVal = " << minVal << endl;
	cout << "minLoc = " << minLoc << endl << endl;

	// TM_SQDIFF_NORMED, TM_SQDIFF 결과를 특정 식으로 나눈 뒤 정규화한다.
	matchTemplate(A, B, result, TM_SQDIFF_NORMED);
	Printmat("result: TM_SQDIFF_NORMED = ", result);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	cout << "TM_SQDIFF" << endl;
	cout << "minVal = " << minVal << endl;
	cout << "minLoc = " << minLoc << endl << endl;

	// TM_CCORR, 곱의 합계를 계산한다. 매칭되는 위치에서 큰 값을 갖는다.
	matchTemplate(A, B, result, TM_CCORR);
	Printmat("result: TM_CCORR = ", result);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
	cout << "TM_SQDIFF" << endl;
	cout << "maxVal = " << maxVal << endl;
	cout << "maxLoc = " << maxLoc << endl << endl;

	// TM_CCORR_NORMED, TM_CCORR 결과를 특정 식으로 나눈 뒤 정규화한다.
	matchTemplate(A, B, result, TM_CCORR_NORMED);
	Printmat("result: TM_CCORR_NORMED = ", result);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
	cout << "TM_SQDIFF" << endl;
	cout << "maxVal = " << maxVal << endl;
	cout << "maxLoc = " << maxLoc << endl << endl;

	// TM_CCOEFF, 각 평균값으로 보정하여 비교한다. 매칭되는 위치에서 큰 값을 갖는다.
	matchTemplate(A, B, result, TM_CCOEFF);
	Printmat("result: TM_CCOEFF = ", result);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
	cout << "TM_SQDIFF" << endl;
	cout << "maxVal = " << maxVal << endl;
	cout << "maxLoc = " << maxLoc << endl << endl;

	// TM_CCOEFF_NORMED, TM_CCOEFF 결과를 특정 식으로 나눈 뒤 정규화한다.
	matchTemplate(A, B, result, TM_CCOEFF_NORMED);
	Printmat("result: TM_CCOEFF_NORMED = ", result);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
	cout << "TM_SQDIFF" << endl;
	cout << "maxVal = " << maxVal << endl;
	cout << "maxLoc = " << maxLoc << endl << endl;

	return 0;
}

void Printmat(const char* strName, Mat m) {
	int x, y;
	float fValue;
	cout << endl << strName << endl;
	cout << setiosflags(ios::fixed);

	for (y = 0; y < m.rows; y++) {
		for (x = 0; x < m.cols; x++) {
			fValue = m.at<float>(y, x);
			cout << setprecision(2) << setw(8) << fValue;
		}
		cout << endl;
	}
	cout << endl;
}
*/