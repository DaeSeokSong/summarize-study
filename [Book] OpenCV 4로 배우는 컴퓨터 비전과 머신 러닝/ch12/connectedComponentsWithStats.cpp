#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("keyboard.bmp", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return -1;
	}

	Mat bin;
	threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

	Mat open_bin;
	Mat morphRect = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(bin, open_bin, MORPH_OPEN, morphRect);

	Mat labels, stats, centroids;
	int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	int label_idx = 1;
	for (int i = 1; i < cnt; i++)
	{
		int* p = stats.ptr<int>(i);
		if (p[4] < 20) continue;

		int centroid_x = centroids.at<double>(i * 2);
		int centroid_y = centroids.at<double>((i * 2) + 1);
		Point centroid(centroid_x, centroid_y);

		rectangle(dst, Rect(p[0], p[1], p[2], p[3]), Scalar(0, 255, 255), 2);
		putText(dst, to_string(label_idx++), centroid, FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0, 0, 255), 2);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);

	return 0;
}