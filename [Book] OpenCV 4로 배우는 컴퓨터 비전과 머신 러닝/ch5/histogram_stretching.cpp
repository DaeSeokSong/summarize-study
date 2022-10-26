//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//Mat calcGrayHist(const Mat& img);
//Mat getGrayHistImage(const Mat& hist);
//
//int main()
//{
//	VideoCapture cap;
//	cap.open(0);
//
//	if (!cap.isOpened())
//	{
//		cout << "Web cam open FAIL" << endl;
//		return -1;
//	}
//
//	int cap_w = cap.get(CAP_PROP_FRAME_WIDTH);
//	int cap_h = cap.get(CAP_PROP_FRAME_HEIGHT);
//
//	Mat frame, grayF, stretchF, gray_stretchF;
//	while (true)
//	{
//		cap >> frame;
//		if (frame.empty()) break;
//
//		double min_g, max_g;
//		minMaxLoc(frame, &min_g, &max_g);
//		cout << "min_g = " << min_g << endl;
//		cout << "max_g = " << max_g << endl;
//		if (min_g == 0) min_g += 50;
//		if (max_g == 255) max_g -= 50;
//
//		stretchF = (frame - min_g) * 255 / (max_g - min_g);
//
//		cvtColor(frame, grayF, COLOR_BGR2GRAY);
//		cvtColor(stretchF, gray_stretchF, COLOR_BGR2GRAY);
//
//		imshow("Frame [1719040 송대석]", frame);
//		imshow("Frame Hist [1719040 송대석]", getGrayHistImage(calcGrayHist(grayF)));
//
//		imshow("Stretching Frame [1719040 송대석]", stretchF);
//		imshow("Stretching Frame Hist [1719040 송대석]", getGrayHistImage(calcGrayHist(gray_stretchF)));
//
//		int input_key = waitKey(1);
//
//		if (input_key == 'c')
//		{
//			imwrite("frame_17019040.jpg", frame);
//			imwrite("stretched_frame_17019040.jpg", stretchF);
//		}
//		else if (input_key == 27) break;
//	}
//
//	return 0;
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