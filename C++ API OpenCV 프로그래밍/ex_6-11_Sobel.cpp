/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 샤프닝
// 영상의 테두리를 강조하여 영상이 날카롭게 보이게 하는 것 (엣지 영상 + 원본 영상)
int main() {
	uchar dataA[] = { 1, 1, 1, 1, 1, 1,
					1, 1, 1, 1, 1, 1,
					1, 1, 9, 9, 1, 1,
					1, 1, 9, 9, 1, 1,
					1, 1, 1, 1, 1, 1,
					1, 1, 1, 1, 1, 1 };
	Mat A(6, 6, CV_8U, dataA);

	int dx = 1, dy = 0;
	int ksize = 3;
	Mat kx, ky;
	// getDerivKernels
	// 영상에서 미분을 계산하기 위한 1차원 선형 필터를 반환한다. kx, ky는 dx, dy의 미분 필터계수를 위한 매개변수다.
	// ksize는 커널의 크기로써, k=CV_SCHARR(-1)이면 Scharr 3*3 커널이 생성된다. k = 1, 3, 5, 7 같은 홀수라면 Sobel 커널이 생성된다.
	// sepFilter2D 에서 생성된 필터를 사용하여 필터링하며, 2D 필터는 ky * kx.t()로 얻을 수 있다.
	getDerivKernels(kx, ky, dx, dy, ksize);
	cout << "kx = " << kx << endl;
	cout << "ky = " << ky << endl;

	Mat kxy = ky * kx.t();
	cout << "kxy = " << kxy << endl;

	int ddepth = CV_16S;
	Mat dst1;
	sepFilter2D(A, dst1, ddepth, kx, ky);
	cout << "dst1 = " << dst1 << endl;

	Mat dst2;
	filter2D(A, dst2, ddepth, kxy);
	cout << "dst2 = " << dst2 << endl;

	// Sobel (디폴트 경계 처리 방식 = BORDOR_REFLECT101)
	// 입력영상에 대해 Sobel 미분을 적용하여 출력영상을 만든다. ddepth = -1이면 입출력 형태가 동일하다.
	Mat dst3;
	Sobel(A, dst3, ddepth, dx, dy, ksize);
	cout << "dst3 = " << dst3 << endl;

	Mat dst4;
	Sobel(A, dst4, ddepth, dx, dy, -1); // CV_SCHARR
	cout << "dst4 = " << dst4 << endl;

	// Scharr
	// 입력영상에 Scharr 연산자를 적용하여 X축 Y축 방향으로의 미분을 적용해서 출력영상을 만든다.
	// scale에 의한 스케일링과 delta에 의한 덧셈을 계산하여 출력영상을 만든다.
	// Sobel 함수에서 ksize = -1로 필터링 한 것과 결과가 동일하다.
	Mat dst5;
	Scharr(A, dst5, ddepth, dx, dy);
	cout << "dst5 = " << dst5 << endl;

	return 0;
}
*/