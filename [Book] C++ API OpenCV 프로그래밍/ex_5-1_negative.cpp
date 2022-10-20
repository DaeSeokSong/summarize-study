/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat srcImg = imread("D:/example/dataset/lena_color.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat_<uchar> img(srcImg);
	Mat_<uchar> dstImg(srcImg.size());

	for (int x = 0; x < img.rows; x++) {
		for (int y = 0; y < img.cols; y++) {
			uchar r = img(x, y);
			// 입력영상의 밝기 최대값에서 화소의 밝기값을 뺀 값으로 화소를 재설정
			dstImg(x, y) = 255 - r;
		}
	}

	imshow("srcImg", srcImg);
	imshow("dstImg", dstImg);
	waitKey(0);
	return 0;
}
*/