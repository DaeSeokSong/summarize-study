/*
#include <opencv2/opencv.hpp>

using namespace cv;

void example2_5(const Mat& image) {
	// 입력 및 결과 이미지를 출력할 윈도우 생성
	namedWindow("Example2_5-in", WINDOW_AUTOSIZE);
	namedWindow("Example2_5-out", WINDOW_AUTOSIZE);

	// 입력 이미지를 출력할 윈도우에 이미지 출력
	imshow("Example2_5-in", image);

	// 결과 이미지
	Mat out;
	GaussianBlur(image, out, Size(5, 5), 3, 3);
	GaussianBlur(out, out, Size(5, 5), 3, 3);

	// 결과 이미지 출력
	imshow("Example2_5-out", out);

	waitKey(0);
}

int main() {
	example2_5(imread("D:/example/dataset/DdaBongDoChi.jpg", -1));
}*/