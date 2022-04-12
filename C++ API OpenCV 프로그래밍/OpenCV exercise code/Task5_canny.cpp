#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	VideoCapture camera;
	camera.open(0);

	if (!camera.isOpened()) {
		cout << "■□■□■□ 카메라 인식 실패 ■□■□■□" << endl;
		return -1;
	}

	// BGR
	Mat frame;

	// Gray
	Mat frameGray;

	// Contour
	Mat frameSobelX;
	Mat frameSobelY;
	Mat frameCannyX;
	Mat frameCannyY;
	Mat frameCanny;
	Mat sumCanny;

	while (true) {
		camera >> frame;
		if (frame.empty()) break;

		cvtColor(frame, frameGray, COLOR_BGR2GRAY);

		// Sobel(입력, 출력, 출력형태(-1 == 입력과 동일), X 미분 차수(ksize보다 작게), Y 미분 차수(ksize보다 작게));
		Sobel(frameGray, frameSobelX, -1, 1, 0);
		Sobel(frameGray, frameSobelY, -1, 0, 1);
		// Canny(입력, 출력, 1차 임계값, 2차 임계값);
		Canny(frameSobelX, frameCannyX, 50, 127);
		Canny(frameSobelY, frameCannyY, 50, 127);
		Canny(frameGray, frameCanny, 50, 127);

		imshow("Display <ORIGIN>", frame);
		imshow("Display <CANNY>", frameCanny);
		imshow("Display <CANNY X>", frameCannyX);
		imshow("Display <CANNY Y>", frameCannyY);
		imshow("Display <CANNY X + Y>", frameCannyX + frameCannyY);

		if (waitKey(1) == 27) break;
	}

	return 0;
}