/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define L 256

// 히스토그램, 관찰 데이터의 빈도수를 막대그래프로 표시한 것, 데이터의 확률밀도 함수를 추정할 수 있다.
// 히스토그램 평활화, 입력 영상의 화소값을 누적분포 함수(cdf)를 사용하여 출력 영상의 화소값을 계산하는 영상개선 방법
// 평활화 수행하면 화소값의 범위가 좁은 저대비 영상을 화소값 범위가 넓은 고대비 영상으로 얻을 수 있다. (더 선명하게 보인다.)
int main() {
	Mat srcImg = imread("D:/example/dataset/lena_color.png");
	if (srcImg.empty()) return -1;

	int histSize[] = { L };
	float valueRange[] = { 0, L };
	const float* ranges[] = { valueRange };
	int channels[] = { 0 };
	int dims = 1;

	Mat hist;
	// 히스토그램 계산(추출)
	calcHist(&srcImg, 1, channels, Mat(), hist, dims, histSize, ranges); // false == 비등간격

	Mat pdf;
	normalize(hist, pdf, L - 1, 0, NORM_L1); // sum of pef = L -1

	Mat cdf(pdf.size(), pdf.type());
	cdf.at<float>(0) = pdf.at<float>(0); // (0, 0)
	for (int i = 1; i < pdf.rows; i++) cdf.at<float>(i) = cdf.at<float>(i - 1) + pdf.at<float>(i); // (0, 0)

	Mat table(cdf.size(), CV_8U);
	table.at<uchar>(0) = 0;
	for (int i = 0; i < pdf.rows; i++) table.at<uchar>(i) = cvRound(cdf.at<float>(i)); // (i, 0)

	Mat dstImg;
	LUT(srcImg, table, dstImg);

	vector<int> params;
	params.push_back(IMWRITE_JPEG_QUALITY);
	params.push_back(100);
	imwrite("D:/example/dataset/imageEq1.jpg", dstImg, params); // 히스토그램 평활화한 dstImg를 jpg 파일(IMWRITE_JPEG_QUALITY=100)로 저장

	imshow("dstImg", dstImg);
	waitKey(0);

	return 0;
}
*/