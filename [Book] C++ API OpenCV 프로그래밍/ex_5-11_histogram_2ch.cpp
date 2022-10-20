/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 히스토그램, 관찰 데이터의 빈도수를 막대그래프로 표시한 것, 데이터의 확률밀도 함수를 추정할 수 있다.
int main() {
	Mat srcImg = imread("D:/example/dataset/lena_color.png");
	if (srcImg.empty()) return -1;

	int histSize[] = { 64, 64 }; // 32
	float range1[] = { 0, 256 };
	float range2[] = { 0, 256 };
	const float* ranges[] = { range1, range2 };
	const int channels[] = { 0, 1, 2 }; // 0 = Blue, 1 = Green, 2 = Red
	int dims = 3;

	Mat hist;
	calcHist(&srcImg, 1, channels, Mat(), hist, dims, histSize, ranges); // uniform의 디폴트는 true
	cout << "hist.size() = " << hist.size() << endl;
	normalize(hist, hist, 0, 255, NORM_MINMAX, CV_32F);

	Mat histImg(512, 512, CV_8U, Scalar(255));
	int binW = cvRound((double)histImg.cols / histSize[1]);
	int binH = cvRound((double)histImg.rows / histSize[0]);

	int x, y;
	Rect rtROI;
	Mat roi;
	for (int i = 0; i < histSize[1]; i++) {
		for (int k = 0; k < histSize[0]; k++) {
			float hValue = hist.at<float>(k, i);
			x = i * binW;
			y = k * binH;
			rtROI = Rect(x, y, binW, binH);
			histImg(rtROI) = hValue;
		}
	}

	imshow("srcImg", srcImg);
	imshow("histImg", histImg);
	waitKey(0);

	return 0;
}
*/