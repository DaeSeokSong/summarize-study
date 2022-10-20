//#include <iostream>
//#include <time.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	theRNG().state = time(NULL);
//	int t, count = 100;
//	double x = -0.37727;
//
//	// Kalman
//	double Q = 1e-5;
//	double R = 1;
//	//double R = 0.0001;
//
//	Scalar stddevR = Scalar::all(0.1);
//	vector<float> measurement_k(count);
//	randn(measurement_k, Scalar::all(x), stddevR);
//
//	vector<float> state_k(count);
//	vector<float> predict_k(count);
//	vector<float> postP(count);
//	vector<float> preP(count);
//	vector<float> K(count);
//
//	state_k[0] = 0.0;
//	postP[0] = 1.0;
//	for (t = 1; t < count; t++)
//	{
//		// predict
//		predict_k[t] = state_k[t - 1];
//		preP[t] = postP[t - 1] + Q;
//
//		// update
//		K[t] = preP[t] / (preP[t] + R);
//		state_k[t] = predict_k[t] + K[t] + K[t] * (measurement_k[t] - predict_k[t]);
//		postP[t] = (1 - K[t]) * preP[t];
//	}
//
//	// drawimg values
//	Mat dstImg(512, 512, CV_8UC3, Scalar::all(255));
//	Size size = dstImg.size();
//	namedWindow("dstImg");
//
//	double minVal, maxVal;
//	minMaxLoc(measurement_k, &minVal, &maxVal);
//	double scale = size.height / (maxVal - minVal);
//
//	// drawing the truth value
//	Point pt1, pt2;
//	pt1.x = 0;
//	pt1.y = size.height - cvRound(scale * x - scale * minVal);
//
//	pt2.x = size.width;
//	pt2.y = size.height - cvRound(scale * x - scale * minVal);
//
//	line(dstImg, pt1, pt2, Scalar(255, 0, 0), 2);
//
//	// drawing the noisy measurement_k
//	int step = size.width / count;
//	for (t = 0; t < count; t++)
//	{
//		pt1.x = t * step;
//		pt1.y = size.height - cvRound(scale * measurement_k[t] - scale * minVal);
//
//		circle(dstImg, pt1, 3, Scalar(0, 255, 0), 2);
//	}
//
//	// drawing the filter estimate
//	pt1.x = 0;
//	pt1.y = size.height - cvRound(scale * state_k[0] - scale * minVal);
//	for (t = 1; t < count; t++)
//	{
//		pt2.x = t * step;
//		pt2.y = size.height - cvRound(scale * state_k[t] - scale * minVal);
//		
//		line(dstImg, pt1, pt2, Scalar(0, 0, 255), 2);
//		pt1 = pt2;
//	}
//	imshow("dstImg", dstImg);
//
//	// drawing the error covariance
//	Mat PImg(size.height, size.width, CV_8UC3, Scalar::all(255));
//	size = PImg.size();
//	namedWindow("PImg");
//
//	minMaxLoc(postP, &minVal, &maxVal);
//
//	pt1.x = 0;
//	pt1.y = size.height - cvRound(scale * postP[0] - scale * minVal);
//	step = size.width / count;
//	for (t = 1; t < count; t++)
//	{
//		pt2.x = t * step;
//		pt2.y = size.height - cvRound(scale * postP[t] - scale * minVal);
//		
//		line(PImg, pt1, pt2, Scalar(0, 0, 255), 2);
//		pt1 = pt2;
//	}
//	imshow("PImg", PImg);
//	waitKey(0);
//
//	return 0;
//}