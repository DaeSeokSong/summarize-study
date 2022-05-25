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
//	int t = 0, count = 100;
//	double x = -0.37727;
//
//	// Kalman
//	double Q = 1e-5;
//	double R = (0.1) * (0.1);
//	//double R = 0.0001;
//
//	Scalar stddevR = Scalar::all(0.1);
//
//	vector<float> measurement_k(count);
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
//	randn(measurement, Scalar::all(x), stddevR);
//	measurement_k[0] = measurement.at<float>(0);
//
//	// Init guesses
//	setIdentity(KF.statePost, Scalar::all(0));
//	setIdentity(KF.errorCovPost, Scalar::all(1));
//	state_k[0] = KF.statePost.at<float>(0);
//	postP[0] = KF.errorCovPost.at<float>(0);
//
//	// drawimg values
//	Mat dstImg(512, 512, CV_8UC3, Scalar::all(255));
//	Size size = dstImg.size();
//	namedWindow("dstImg");
//
//	int step = size.width / count;
//	double minVal = x - stddevR.val[0] * 3;
//	double maxVal = x + stddevR.val[0] * 3;
//	double scale = size.height / (maxVal - minVal);
//
//	while (true)
//	{
//		Mat prediction = KF.predict();
//
//		randn(measurement, Scalar::all(x), stddevR);
//		measurement_k[t] = measurement.at<float>(0);
//
//		Mat estimate = KF.correct(measurement);
//		state_k[t] = KF.statePost.at<float>(0);
//		postP[t] = KF.errorCovPost.at<float>(0);
//
//		// drawing the truth value
//		Point pt1, pt2;
//		pt1.x = 0;
//		pt1.y = size.height - cvRound(scale * x - scale * minVal);
//
//		pt2.x = size.width;
//		pt2.y = size.height - cvRound(scale * x - scale * minVal);
//
//		line(dstImg, pt1, pt2, Scalar(255, 0, 0), 2);
//
//		for (int k = count - 1; k > 0; k--)
//		{
//			int k1 = (t + k) % count;
//			int k2 = (t + k + 1) % count;
//
//			// drawing the noisy measurement_k
//			pt1.x = k * step;
//			pt1.y = size.height - cvRound(scale * measurement_k[k1] - scale * minVal);
//
//			pt2.x = (k + 1) * step;
//			pt2.y = size.height - cvRound(scale * measurement_k[k2] - scale * minVal);
//
//			line(dstImg, pt1, pt2, Scalar(0, 255, 0), 2);
//
//			// drawing the filter estimate
//			pt1.x = k * step;
//			pt1.y = size.height - cvRound(scale * state_k[k1] - scale * minVal);
//
//			pt2.x = (k + 1) * step;
//			pt2.y = size.height - cvRound(scale * state_k[k2] - scale * minVal);
//
//			line(dstImg, pt1, pt2, Scalar(0, 0, 255), 2);
//		}
//
//		imshow("dstImg", dstImg);
//
//		int ckey = waitKey(30);
//		if (ckey == 27) break;
//
//		t = (t + 1) % count;
//		dstImg = Scalar::all(255);
//	}
//
//	return 0;
//}