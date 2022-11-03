//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//void color_inverse();
//void color_grayscale();
//void color_split();
//void color_histogram_equalize();
//void draw_2d_histogram();
//
//int main()
//{
//	//// Ex1
//	//color_inverse();
//
//	//// Ex2
//	//color_grayscale();
//
//	//// Ex3
//	//color_split();
//
//	//// Ex4
//	//color_histogram_equalize();
//
//	// Ex4-1
//	draw_2d_histogram();
//
//	return 0;
//}
//
//void color_inverse()
//{
//	Mat src = imread("butterfly.jpg");
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	Mat dst(src.rows, src.cols, src.type());
//	for (int k = 0; k < src.rows; k++)
//	{
//		for (int i = 0; i < src.cols; i++)
//		{
//			Vec3b& p1 = src.at<Vec3b>(k, i);
//			Vec3b& p2 = src.at<Vec3b>(k, i);
//
//			p2[0] = 255 - p1[0];
//			p2[1] = 255 - p1[1];
//			p2[2] = 255 - p1[2];
//		}
//	}
//
//	imshow("src", src);
//	imshow("dst", dst);
//
//	waitKey(0);
//}
//
//void color_grayscale()
//{
//	Mat src = imread("butterfly.jpg");
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	Mat dst;
//	cvtColor(src, dst, COLOR_BGR2GRAY);
//
//	imshow("src", src);
//	imshow("dst", dst);
//
//	waitKey(0);
//}
//
//void color_split()
//{
//	Mat src = imread("candies.png");
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	vector<Mat> bgr_planes;
//	split(src, bgr_planes);
//
//	imshow("src", src);
//	imshow("B_plane", bgr_planes[0]);
//	imshow("G_plane", bgr_planes[1]);
//	imshow("R_plane", bgr_planes[2]);
//
//	waitKey(0);
//}
//
//void color_histogram_equalize()
//{
//	Mat src = imread("candies.png");
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	Mat ycrcb;
//	cvtColor(src, ycrcb, COLOR_BGR2YCrCb);
//
//	vector<Mat> ycrcb_planes;
//	split(ycrcb, ycrcb_planes);
//
//	equalizeHist(ycrcb_planes[0], ycrcb_planes[0]);
//	merge(ycrcb_planes, ycrcb);
//
//	Mat ycrcb_dst;
//	cvtColor(ycrcb, ycrcb_dst, COLOR_YCrCb2BGR);
//
//	Mat hsv;
//	cvtColor(src, hsv, COLOR_BGR2HSV);
//
//	vector<Mat> hsv_planes;
//	split(hsv, hsv_planes);
//
//	equalizeHist(hsv_planes[1], hsv_planes[1]);
//	merge(hsv_planes, hsv);
//
//	Mat hsv_dst;
//	cvtColor(hsv, hsv_dst, COLOR_HSV2BGR);
//
//	imshow("src", src);
//	imshow("ycrcb_dst", ycrcb_dst);
//	imshow("hsv_dst", hsv_dst);
//
//	waitKey(0);
//}
//
//void draw_2d_histogram()
//{
//	Mat src = imread("kids.png");
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	Mat ycrcb;
//	cvtColor(src, ycrcb, COLOR_BGR2YCrCb);
//
//	Mat hist;
//	int ch[] = { 1, 2 };
//	int histSize[] = { 128, 128 };
//	float cr_range[] = { 0, 256 };
//	float cb_range[] = { 0, 256 };
//	const float* ranges[] = { cr_range, cb_range };
//
//	calcHist(&ycrcb, 1, ch, noArray(), hist, 2, histSize, ranges);
//	//imshow("hist", hist);
//
//	//waitKey(0);
//}