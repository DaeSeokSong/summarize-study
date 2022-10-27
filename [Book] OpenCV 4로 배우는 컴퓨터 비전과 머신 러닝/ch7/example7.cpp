//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//void filter_embossing();
//void blurring_mean();
//void blurring_gaussian();
//void noise_gaussian();
//void filter_median();
//Mat calcGrayHist(const Mat& img);
//Mat getGrayHistImage(const Mat& hist);
//
//int main()
//{
//	//// Ex1
//	//filter_embossing();
//
//
//
//	//// Ex2
//	//blurring_mean();
//
//
//
//	//// Ex3
//	//blurring_gaussian();
//
//
//
//	//// Ex4
//	//noise_gaussian();
//
//
//
//	// Ex5
//	filter_median();
//
//	return 0;
//}
//
//void filter_embossing()
//{
//	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	float data[] = { -1, -1, 0, -1, 0, 1, 0, 1, 1 };
//	Mat emboss(3, 3, CV_32FC1, data);
//
//	Mat dst, dst2, dst3;
//	filter2D(src, dst, -1, emboss, Point(-1, -1), 128);
//	filter2D(src, dst2, -1, emboss, Point(0, 0), 128);
//	filter2D(src, dst3, -1, emboss, Point(2, 2), 128);
//
//	Mat diff1_2, diff1_3, diff2_3;
//	absdiff(dst, dst2, diff1_2);
//	absdiff(dst, dst3, diff1_3);
//	absdiff(dst2, dst3, diff2_3);
//
//	imshow("src", src);
//	imshow("dst", dst);
//	imshow("dst2", dst2);
//	imshow("dst3", dst3);
//	imshow("diff1_2", diff1_2);
//	imshow("diff1_3", diff1_3);
//	imshow("diff2_3", diff2_3);
//
//	waitKey(0);
//}
//
//void blurring_mean()
//{
//	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//	imshow("src", src);
//
//	Mat dst;
//	for (int ksize = 3; ksize < 8; ksize += 2)
//	{
//		blur(src, dst, Size(ksize, ksize));
//
//		String desc = format("Mean: %dx%d", ksize, ksize);
//		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
//
//		imshow("dst", dst);
//		waitKey(0);
//	}
//}
//
//void blurring_gaussian()
//{
//	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//	imshow("src", src);
//
//	Mat dst;
//	for (int sigma = 1; sigma < 6; sigma++)
//	{
//		GaussianBlur(src, dst, Size(), sigma);
//
//		String text = format("sigma = %d", sigma);
//		putText(dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
//
//		imshow("dst [sigma = " + to_string(sigma) + "]", dst);
//		waitKey(0);
//	}
//}
//
//void noise_gaussian()
//{
//	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//	imshow("src", src);
//
//	for (int std = 10; std < 31; std += 10)
//	{
//		Mat noise(src.size(), CV_32SC1);
//		randn(noise, 0, std);
//
//		Mat dst;
//		add(src, noise, dst, Mat(), CV_8U);
//
//		Mat blurredImg, blurredGImg;
//		blur(dst, blurredImg, Size(3, 3));
//		GaussianBlur(dst, blurredGImg, Size(), 3);
//
//		String desc = format("std = %d", std);
//		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
//
//		imshow("dst", dst);
//		imshow("blur", blurredImg);
//		imshow("Gaussianblur", blurredGImg);
//		waitKey(0);
//	}
//}
//
//void filter_median()
//{
//	Mat src = imread("lena.jpg", IMREAD_GRAYSCALE);
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//	imshow("src", src);
//
//	// Add solt-and-papper noise
//	int num = (int)(src.total() * 0.2);
//	for (int i = 0; i < num; i++)
//	{
//		int x = rand() % src.cols;
//		int y = rand() % src.rows;
//		src.at<uchar>(y, x) = (i % 2) * 255;
//	}
//
//	Mat dst1;
//	GaussianBlur(src, dst1, Size(), 1);
//
//	Mat dst2;
//	medianBlur(src, dst2, 3);
//
//	Mat dst3;
//	bilateralFilter(src, dst3, -1, 10, 15);
//
//	imshow("src", src);
//	imshow("src hist", getGrayHistImage(calcGrayHist(src)));
//	imshow("dst1", dst1);
//	imshow("dst1 hist", getGrayHistImage(calcGrayHist(dst1)));
//	imshow("dst2", dst2);
//	imshow("dst2 hist", getGrayHistImage(calcGrayHist(dst2)));
//	imshow("dst3", dst3);
//	imshow("dst3 hist", getGrayHistImage(calcGrayHist(dst3)));
//	waitKey(0);
//}
//
//Mat calcGrayHist(const Mat& img)
//{
//	CV_Assert(img.type() == CV_8UC1);
//
//	Mat hist;
//
//	int channels[] = { 0 };
//	int dims = 1;
//	const int histSize[] = { 256 };
//	float graylevel[] = { 0, 256 };
//	const float* ranges[] = { graylevel };
//
//	calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
//
//	return hist;
//}
//
//Mat getGrayHistImage(const Mat& hist)
//{
//	CV_Assert(hist.type() == CV_32FC1);
//	CV_Assert(hist.size() == Size(1, 256));
//
//	double histMax;
//	minMaxLoc(hist, 0, &histMax);
//
//	Mat imgHist(100, 256, CV_8UC1, Scalar(255));
//	for (int i = 0; i < 256; i++)
//	{
//		line(imgHist, Point(i, 100),
//			Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
//	}
//
//	return imgHist;
//}