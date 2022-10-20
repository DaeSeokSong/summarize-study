//#include <iostream>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	int t = 0;
//	int count = 7;
//
//	// Kalman
//	KalmanFilter KF(2, 1, 1);
//	Mat measurement(1, 1, CV_32F);
//
//	float g = 1.0;
//	Mat controlB(1, 1, CV_32F, -g);
//
//	setIdentity(KF.measurementMatrix); // H = {1, 0}
//	KF.transitionMatrix = (Mat_<float>(2, 2) << 1, 1, 0, 1); // A
//	KF.controlMatrix = (Mat_<float>(2, 1) << 0.5, 1.0);
//
//	double Q = 0;
//	double R = 1;
//	setIdentity(KF.processNoiseCov, Scalar::all(Q));
//	setIdentity(KF.measurementNoiseCov, Scalar::all(R));
//
//	KF.statePost.at<float>(0, 0) = 95.0;
//	KF.statePost.at<float>(1, 0) = 1.0;
//
//	// init error
//	setIdentity(KF.errorCovPost); // P(0,0)=10, P(1,1)=1
//	KF.errorCovPost.at<float>(0, 0) = 10.0;
//
//	float z[7] = { 0, 100.0, 97.9, 94.4, 92.7, 87.3, 82.1 };
//	printf("t = %d: statePost=(%f, %f) : errorCovPost=(%f, %f)\n", t,
//		KF.statePost.at<float>(0, 0),
//		KF.statePost.at<float>(1, 0),
//		KF.errorCovPost.at<float>(0, 0),
//		KF.errorCovPost.at<float>(1, 0));
//
//	for (t = 1; t < count; t++)
//	{
//		Mat prediction = KF.predict();
//
//		measurement.at<float>(0) = z[t];
//
//		Mat estimate = KF.correct(measurement);
//
//		printf("t = %d: statePost=(%f, %f) : errorCovPost=(%f, %f)\n", t,
//			KF.statePost.at<float>(0, 0),
//			KF.statePost.at<float>(1, 0),
//			KF.errorCovPost.at<float>(0, 0),
//			KF.errorCovPost.at<float>(1, 0));
//	}
//
//	return 0;
//}