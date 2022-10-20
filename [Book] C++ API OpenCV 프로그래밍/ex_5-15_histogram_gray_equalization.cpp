/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 히스토그램, 관찰 데이터의 빈도수를 막대그래프로 표시한 것, 데이터의 확률밀도 함수를 추정할 수 있다.
// 히스토그램 평활화, 입력 영상의 화소값을 누적분포 함수(cdf)를 사용하여 출력 영상의 화소값을 계산하는 영상개선 방법
// 평활화 수행하면 화소값의 범위가 좁은 저대비 영상을 화소값 범위가 넓은 고대비 영상으로 얻을 수 있다. (더 선명하게 보인다.)
int main() {
	Mat srcImg = imread("D:/example/dataset/lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat dstImg;
	equalizeHist(srcImg, dstImg); // 히스토그램 계산(추출) 및 평활화

	vector<int> params;
	params.push_back(IMWRITE_JPEG_QUALITY);
	params.push_back(100);
	imwrite("D:/example/dataset/imageEq2.jpg", dstImg, params); // 히스토그램 평활화한 dstImg를 jpg 파일(IMWRITE_JPEG_QUALITY=100)로 저장

	imshow("dstImg", dstImg);
	waitKey(0);

	return 0;
}
*/