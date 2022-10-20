/*
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
	Mat img_rgb, img_gry, img_cny;

	namedWindow("Example Gray", WINDOW_AUTOSIZE);
	namedWindow("Example Canny", WINDOW_AUTOSIZE);

	img_rgb = imread("D:/example/dataset/DdaBongDoChi.jpg", -1);

	cvtColor(img_rgb, img_gry, COLOR_RGB2GRAY);
	imshow("Example Gray", img_gry);

	Canny(img_gry, img_cny, 10, 100, 3, true);
	imshow("Example Canny", img_cny);

	waitKey(0);
}
*/