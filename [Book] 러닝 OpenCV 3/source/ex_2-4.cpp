/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int g_slider_position = 0; // 슬라이더의 위치 상태
int g_run = 1;
int g_dontset = 0; // 싱글모드 시작
VideoCapture g_cap;

// 트랙바 위치를 재배치하는 콜백 함수
void onTrackbarSlide(int pos, void*) {
	if (!g_dontset) {
		g_run = 1;
		g_cap.set(CAP_PROP_POS_FRAMES, pos);
	}

	g_dontset = 0;
}

int main() {
	namedWindow("Example2_4", WINDOW_AUTOSIZE);
	g_cap.open("D:/example/dataset/Robin.mp4");

	int frames = (int)g_cap.get(CAP_PROP_FRAME_COUNT);
	int tmpw = (int)g_cap.get(CAP_PROP_FRAME_WIDTH);
	int tmph = (int)g_cap.get(CAP_PROP_FRAME_HEIGHT);
	cout << "Video has" << frames << " frames of demensions(" << tmpw << ", " << tmph << ")" << endl;

	createTrackbar("Position", "Example2_4", &g_slider_position, frames, onTrackbarSlide);

	Mat frame;
	while (true) {
		if (g_run != 0) {
			g_cap >> frame;
			if (frame.empty()) break;

			int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
			g_dontset = 1;

			setTrackbarPos("Position", "Example2_4", current_pos);
			imshow("Example2_4", frame);

			g_run -= 1;
		}

		char c = (char)waitKey(10);
		if (c == 's') {
			g_run = 1;
			cout << "Single step, run = " << g_run << endl;
		} else if (c == 'r') {
			g_run = -1;
			cout << "Run mode, run = " << g_run << endl;
		} else if (c == 27) break; // ESC
	}

	return 0;
}
*/