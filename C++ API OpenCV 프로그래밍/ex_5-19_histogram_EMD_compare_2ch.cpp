/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void drawHistogram2D(Mat& img, Mat hist);

// 히스토그램, 관찰 데이터의 빈도수를 막대그래프로 표시한 것, 데이터의 확률밀도 함수를 추정할 수 있다.
// EMD, 두 개의 분포 사이에서 최소임을 측정하는 방법으로 두 분포 사이의 거리를 계산할 수 있고 이는 분포 p를 q로 변경하는 데 소요되는 최소비용이다. (수송 문제에 활용)
// 칼라매칭 등 활용 가능
int main() {
	Mat srcImg1(512, 512, CV_8UC2);
	Mat srcImg2(512, 512, CV_8UC2);

	Scalar mean1 = Scalar(128, 128);
	Scalar stddev1 = Scalar(20, 20);
	RNG& rng1 = theRNG();	// 난수 채우기
	rng1.fill(srcImg1, RNG::NORMAL, mean1, stddev1);

	Scalar mean2 = Scalar(110, 128);
	Scalar stddev2 = Scalar(20, 20);
	RNG& rng2 = theRNG();
	rng2.fill(srcImg2, RNG::NORMAL, mean2, stddev2);

	int histSize[] = { 32, 32 };
	float range1[] = { 0, 256 };
	float range2[] = { 0, 256 };
	const float* ranges[] = { range1, range2 };
	int channels[] = { 0, 1 };
	int dims = 2;

	Mat H1;
	calcHist(&srcImg1, 2, channels, Mat(), H1, dims, histSize, ranges);
	normalize(H1, H1, 1, 0, NORM_L1, CV_32F);

	Mat H2;
	calcHist(&srcImg2, 1, channels, Mat(), H2, dims, histSize, ranges);
	normalize(H2, H2, 1, 0, NORM_L1, CV_32F);

	int nRows1 = H1.rows * H1.cols;
	Mat S1(nRows1, 3, CV_32F, Scalar(0));
	for (int y = 0; y < H1.rows; y++) {
		for (int x = 0; x < H1.cols; x++) {
			int n = H1.cols * y + x;

			S1.at<float>(n, 0) = H1.at<float>(y, x);
			S1.at<float>(n, 1) = y;
			S1.at<float>(n, 2) = x;
		}
	}
	cout << "S1.size() = " << S1.size() << endl;

	int nRows2 = H2.rows * H2.cols;
	Mat S2(nRows2, 3, CV_32F, Scalar(0));
	for (int y = 0; y < H2.rows; y++) {
		for (int x = 0; x < H2.cols; x++) {
			int n = H1.cols * y + x;

			S2.at<float>(n, 0) = H2.at<float>(y, x);
			S2.at<float>(n, 1) = y;
			S2.at<float>(n, 2) = x;
		}
	}
	cout << "S2.size() = " << S2.size() << endl;

	float emdDist = EMD(S1, S2, DIST_L2);
	cout << "emdDist = " << emdDist << endl;

	float lowerBound = 100;
	float emdDist2 = EMD(S1, S2, DIST_L2, noArray(), &lowerBound);
	cout << "lowerBound = " << lowerBound << endl;
	cout << "emdDist2 = " << emdDist2 << endl;

	Mat histImg1;
	drawHistogram2D(histImg1, H1);
	imshow("histImg1", histImg1);

	Mat histImg2;
	drawHistogram2D(histImg2, H2);
	imshow("histImg2", histImg2);

	waitKey(0);

	return 0;
}

void drawHistogram2D(Mat& img, Mat hist) {
	if (img.empty()) img.create(512, 512, CV_8U);

	normalize(hist, hist, 0, 255, NORM_MINMAX, CV_32F);
	int binW = cvRound((double)img.cols / hist.cols);
	int binH = cvRound((double)img.rows / hist.rows);

	int x, y;
	Rect rtROI;
	Mat roi;
	for (int i = 0; i < hist.cols; i++) {
		for (int k = 0; k < hist.rows; k++) {
			float hValue = hist.at<float>(k, i);

			x = i * binW;
			y = k * binH;
			rtROI = Rect(x, y, binW, binH);
			img(rtROI) = cvRound(hValue);
		}
	}
}
*/