/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void drawHistogram(Mat& img, Mat hist);

// 히스토그램, 관찰 데이터의 빈도수를 막대그래프로 표시한 것, 데이터의 확률밀도 함수를 추정할 수 있다.
// EMD, 두 개의 분포 사이에서 최소임을 측정하는 방법으로 두 분포 사이의 거리를 계산할 수 있고 이는 분포 p를 q로 변경하는 데 소요되는 최소비용이다. (수송 문제에 활용)
// 칼라매칭 등 활용 가능
int main() {
	Mat srcImg1(512, 512, CV_8U);
	Mat srcImg2(512, 512, CV_8U);

	Scalar mean1 = Scalar(128);
	Scalar stddev1 = Scalar(10); // 20
	RNG& rng1 = theRNG();
	rng1.fill(srcImg1, RNG::NORMAL, mean1, stddev1);

	Scalar mean2 = Scalar(110);
	Scalar stddev2 = Scalar(10); // 20
	RNG& rng2 = theRNG();
	rng2.fill(srcImg2, RNG::NORMAL, mean2, stddev2);

	int histSize = 256;
	float valueRange[] = { 0, 256 };
	const float* ranges[] = { valueRange };
	int channels = 0;
	int dims = 1;

	Mat H1;
	calcHist(&srcImg1, 1, &channels, Mat(), H1, dims, &histSize, ranges);
	normalize(H1, H1, 1, 0, NORM_L1, CV_32F);

	Mat H2;
	calcHist(&srcImg2, 1, &channels, Mat(), H2, dims, &histSize, ranges);
	normalize(H2, H2, 1, 0, NORM_L1, CV_32F);

	Mat S1(H1.rows, 2, CV_32F);
	Mat S2(H2.rows, 2, CV_32F);

	for (int i = 0; i < H1.rows; i++) {
		S1.at<float>(i, 0) = H1.at<float>(i);
		S1.at<float>(i, 1) = i + 1;
	}
	for (int i = 0; i < H2.rows; i++) {
		S2.at<float>(i, 0) = H2.at<float>(i);
		S2.at<float>(i, 1) = i + 1;
	}
	float emdDist = EMD(S1, S2, DIST_L2);

	Mat histImg1;
	drawHistogram(histImg1, H1);
	imshow("histImg1", histImg1);

	Mat histImg2;
	drawHistogram(histImg2, H2);
	imshow("histImg2", histImg2);

	waitKey(0);

	return 0;
}

void drawHistogram(Mat& img, Mat hist) {
	if (img.empty()) img.create(512, 512, CV_8U);

	normalize(hist, hist, 0, img.rows, NORM_MINMAX, CV_32F);

	img = Scalar(255);
	int binW = cvRound((double)img.cols / hist.rows);
	int x1, y1, x2, y2;
	for (int i = 0; i < hist.rows; i++) {
		x1 = i * binW;
		y1 = img.rows;
		x2 = (i + 1) * binW;
		y2 = img.rows - cvRound(hist.at<float>(i));
		rectangle(img, Point(x1, y1), Point(x2, y2), Scalar(0), -1);
	}
}
*/