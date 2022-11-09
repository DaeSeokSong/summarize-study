#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void on_threshold(int pos, void* userdata);
Mat draw_histogram(Mat img);

int main()
{
	Mat src = imread("neutrophils.png", IMREAD_GRAYSCALE);

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return -1;
	}

	imshow("src", src);
	imshow("histo_graph (src)", draw_histogram(src));

	namedWindow("dst");
	createTrackbar("Threshold", "dst", 0, 255, on_threshold, (void*)&src);
	setTrackbarPos("Threshold", "dst", 128);

	waitKey(0);

	return 0;
}

void on_threshold(int pos, void* userdata)
{
	Mat src = *(Mat*)userdata;

	Mat dst;
	threshold(src, dst, pos, 255, THRESH_BINARY);

	imshow("dst", dst);
}

Mat draw_histogram(Mat img)
{
	// Calc Histogram
	int histSize = img.cols;
	float hValue[] = { 0, 256 };
	const float* ranges[] = { hValue };
	int channels = 0;
	int dims = 1;

	Mat src_hist;
	calcHist(&img, 1, &channels, cv::Mat(), 
		src_hist, dims, &histSize, ranges);
	normalize(src_hist, src_hist, 0, 255, NORM_MINMAX);

	// Draw Histogram
	Mat histo_graph(Size(histSize, 256), CV_8UC1, Scalar::all(0));
	for (int p_idx = 0; p_idx < histSize; p_idx++)
	{
		int pixel_num = cvRound(src_hist.at<float>(1, p_idx));

		line(histo_graph,
			Point(p_idx, histo_graph.rows),
			Point(p_idx, histo_graph.rows - pixel_num),
			Scalar::all(255),
			2);
	}

	return histo_graph;
}