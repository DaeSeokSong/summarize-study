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
//	double R = (0.1) * (0.1);
//	//double R = 0.0001;
//
//	Scalar stddevR = Scalar::all(0.1);
//	vector<float> measurement_k(count);
//	randn(measurement_k, Scalar::all(x), stddevR);
//
//	vector<float> state_k(count);
//	vector<float> postP(count);
//
//	KalmanFilter KF(1, 1, 0);
//	Mat measurement(1, 1, CV_32F);
//
//	setIdentity(KF.transitionMatrix); // A = 1
//	setIdentity(KF.measurementMatrix); // H = 1
//	setIdentity(KF.processNoiseCov, Scalar::all(Q));
//	setIdentity(KF.measurementNoiseCov, Scalar::all(R));
//
//	// Init guesses
//	setIdentity(KF.statePost, Scalar::all(0));
//	setIdentity(KF.errorCovPost, Scalar::all(1));
//	state_k[0] = KF.statePost.at<float>(0);
//	postP[0] = KF.errorCovPost.at<float>(0);
//
//	for (t = 1; t < count; t++)
//	{
//		Mat prediction = KF.predict();
//		measurement.at<float>(0) = measurement_k[t];
//
//		Mat estimate = KF.correct(measurement);
//		state_k[t] = KF.statePost.at<float>(0);
//		postP[t] = KF.errorCovPost.at<float>(0);
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