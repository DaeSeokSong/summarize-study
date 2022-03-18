/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img_rgb, img_gry, img_cny;
	Mat img_pyr, img_pyr2;

	int x = 16;
	int y = 32;

	namedWindow("Example Origin", WINDOW_AUTOSIZE);
	namedWindow("Example Gray", WINDOW_AUTOSIZE);
	namedWindow("Example Canny", WINDOW_AUTOSIZE);

	img_rgb = imread("D:/example/dataset/DdaBongDoChi.jpg", -1);
	imshow("Example Origin", img_rgb);

	cvtColor(img_rgb, img_gry, COLOR_RGB2GRAY);
	imshow("Example Gray", img_gry);

	cout << "Gray pixel there is: "
		<< (unsigned int)img_gry.at<uchar>(y, x) << endl;

	pyrDown(img_gry, img_pyr);
	pyrDown(img_pyr, img_pyr2);

	Canny(img_pyr2, img_cny, 10, 100, 3, true);
	imshow("Example Canny", img_cny);

	Vec3b intensity = img_rgb.at<Vec3b>(y, x);

	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	cout << "At (x, y) = (" << x << ", " << y
		<< "): (B, G, R) = (" << (unsigned int)blue << ", "
		<< (unsigned int)green << ", " << (unsigned int)red
		<< ")" << endl;

	x /= 4;
	y /= 4;
	cout << "Pyramid2 pixel there is: "
		<< (unsigned int)img_pyr2.at<uchar>(y, x) << endl;

	img_cny.at<uchar>(x, y) = 128;

	waitKey(0);
}
*/