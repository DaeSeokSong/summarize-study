/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define L 256

// 히스토그램, 관찰 데이터의 빈도수를 막대그래프로 표시한 것, 데이터의 확률밀도 함수를 추정할 수 있다.
// 히스토그램 평활화, 입력 영상의 화소값을 누적분포 함수(cdf)를 사용하여 출력 영상의 화소값을 계산하는 영상개선 방법
// 평활화 수행하면 화소값의 범위가 좁은 저대비 영상을 화소값 범위가 넓은 고대비 영상으로 얻을 수 있다. (더 선명하게 보인다.)
int main() {
	uchar dataA[16]{ 0, 0, 0, 0,
					1, 1, 3, 5,
					6, 1, 1, 3,
					4, 3, 1, 7 };
	Mat A(4, 4, CV_8U, dataA);
	cout << "A = " << A << endl;

	Mat dst;
	equalizeHist(A, dst);
	cout << "dst = " << dst << endl;

	return 0;
}
*/