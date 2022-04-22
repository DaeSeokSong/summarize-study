/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\momentTest.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat dstImg;
	cvtColor(srcImg, dstImg, COLOR_GRAY2BGR);

	threshold(srcImg, srcImg, 200, 255, THRESH_BINARY);

	int mode = RETR_LIST;
	int method = CHAIN_APPROX_SIMPLE;

	vector<vector<Point>> contours;
	findContours(srcImg, contours, noArray(), mode, method);

	for (int k = 0; k < contours.size(); k++)
	{
		drawContours(dstImg, contours, k, Scalar(0, 0, 255), 4);

		Moments M = moments(contours[k]);

		Point2f center;
		center.x = M.m10 / M.m00;
		center.y = M.m01 / M.m00;

		circle(dstImg, center, 5, Scalar(0, 0, 255), -1);

		Mat hu;
		HuMoments(M, hu);
		cout << "============================ contours's Hu moments ============================" << endl;
		for (int i = 0; i < hu.rows; i++)
		{
			cout << "hu[" << i << "] = ";
			cout << hu.at<double>(i) << endl;
		}

		double angle = 45.0; // rotation angle
		double scale = 0.5; // scaling
		Point t(0, 0); // traslation

		Mat rot = getRotationMatrix2D(center, angle, scale);
		rot.col(2).at<double>(0) += t.x;
		rot.col(2).at<double>(1) += t.y;

		Mat points(contours[k]);
		transform(points, points, rot);

		vector<Point> contour2;
		points.copyTo(contour2);
		drawContours(dstImg, vector<vector<Point>>(1, contour2), 0, Scalar(255, 255, 0), 4);

		Moments M2 = moments(contour2);

		Point2f center2;
		center2.x = M2.m10 / M2.m00;
		center2.y = M2.m01 / M2.m00;

		circle(dstImg, center2, 5, Scalar(0, 255, 255), -1);

		Mat hu2;
		HuMoments(M2, hu2);
		cout << "============================ contour2's Hu moments ============================" << endl;
		for (int i = 0; i < hu2.rows; i++)
		{
			cout << "hu[" << i << "] = ";
			cout << hu2.at<double>(i) << endl;
		}

		double distError = norm(hu, hu2);
		cout << endl << "distError = " << distError << endl;
		imshow("dstImg", dstImg);
	}

	waitKey(0);
	return 0;
}
*/