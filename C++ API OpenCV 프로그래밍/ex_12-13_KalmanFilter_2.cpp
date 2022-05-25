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
//	int count = 100;
//	double x = -0.37727;
//
//	// Kalman
//	double Q = 1e-5;
//	double R = 1;
//	//double R = 0.0001;
//
//	Scalar stddevR = Scalar::all(0.1);
//
//	vector<float> measurement_k(count);
//	vector<float> state_k(count);
//	float predict_k;
//	float postP;
//	float preP;
//	float K;
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
//	state_k[0] = 0.0;
//	postP = 1.0;
//	theRNG().state = time(NULL);
//	int t = 1;
//	while (true)
//	{
//		int t1 = (t - 1 + count) % count; // t-1
//
//		// predict
//		predict_k = state_k[t1];
//		preP = postP + Q;
//
//		Mat measurement(1, 1, CV_32F);
//		randn(measurement, Scalar::all(x), stddevR);
//		measurement_k[t] = measurement.at<float>(0);
//
//		// update
//		K = preP / (preP + R);
//		state_k[t] = predict_k + K * (measurement_k[t] - predict_k);
//		postP = (1 - K) * preP;
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