/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

#define FLIP_Y(y) ((dstImg.size().height-1)-y)

int main() {
	double dataX[] = { 0, 0, 0, 100, 100, 150, -100, -150,
						0, 50, -50, 0, 30, 100, -20, -100 };

	cv::Mat X(2, 8, CV_64F, dataX);
	cout << "X = " << X << endl;

	cv::Mat cX, mX;
	cv::calcCovarMatrix(X, cX, mX, cv::COVAR_NORMAL + cv::COVAR_COLS);
	cout << "mX = " << mX << endl;
	cout << "cX = " << cX << endl << endl;

	cv::Mat eValsX;
	cv::Mat eVectsX;
	cv::eigen(cX, eValsX, eVectsX);
	cout << "eValsX = " << eValsX << endl;
	cout << "eVectsX = " << eVectsX << endl;

	// PCA projection start
	cv::Mat X1 = X.clone();
	for (int x = 0; x < X1.cols; x++) {
		X1.col(x) = X.col(x) - mX;
	}

	cv::Mat A = eVectsX.clone();
	cv::Mat Y = A * X1;
	cout << "Y = " << Y << endl;
	// PCA projection end

	// PCA backProjection start
	cv::Mat X2 = A.t() * Y;
	for (int x = 0; x < X2.cols; x++) {
		X2.col(x) = X2.col(x) + mX;
	}
	cout << "X2 = " << X2 << endl;
	// PCA backProjection end

	cv::Mat cY, mY;
	cv::calcCovarMatrix(Y, cY, mY, cv::COVAR_NORMAL + cv::COVAR_COLS);
	cout << "mY = " << mY << endl;
	cout << "cY = " << cY << endl << endl;

	cv::Mat eValsY;
	cv::Mat eVectsY;
	cv::eigen(cX, eValsY, eVectsY);
	cout << "eValsY = " << eValsY << endl;
	cout << "eVectsY = " << eVectsY << endl;

	// for Mahalanobis distance
	cv::Mat invCx;
	cv::invert(cX, invCx);
	cv::Mat invCy;
	cv::invert(cY, invCy);

	// draw points and axis
	cv::Mat dstImg(512, 512, CV_8UC3, cv::Scalar::all(255));
	cv::Point center(dstImg.cols / 2, dstImg.rows / 2);

	int x, y;
	cv::Mat vec2(2, 1, CV_64F);
	double fDistance1, fDistance2;
	for (y = 0; y < dstImg.rows; y++) {
		for (x = 0; x < dstImg.cols; x++) {
			vec2.at<double>(0, 0) = x - center.x;
			vec2.at<double>(1, 0) = y - center.y;

			fDistance1 = cv::Mahalanobis(mX, vec2, invCx);
			if (0.7 <= fDistance1 && fDistance1 <= 0.8) dstImg.at<cv::Vec3b>(FLIP_Y(y), x) = cv::Vec3b(0, 0, 255);

			fDistance2 = cv::Mahalanobis(mY, vec2, invCy);
			if (0.7 <= fDistance2 && fDistance2 <= 0.8) dstImg.at<cv::Vec3b>(FLIP_Y(y), x) = cv::Vec3b(255, 0, 0);
		}
	}

	// draw points on the image
	cv::Point pt1, pt2;
	for (x = 0; x < X.cols; x++) {
		// draw X
		pt1.x = X.at<double>(0, x) + center.x;
		pt1.y = X.at<double>(1, x) + center.y;
		pt1.y = FLIP_Y(pt1.y);
		circle(dstImg, pt1, 3, cv::Scalar(0, 0, 255), 3);

		// draw Y
		pt2.x = Y.at<double>(0, x) + center.x;
		pt2.y = Y.at<double>(1, x) + center.y;
		pt2.y = FLIP_Y(pt2.y);
		circle(dstImg, pt2, 3, cv::Scalar(255, 0, 0), 3);
	}

	// draw mX
	pt1.x = cvRound(mX.at<double>(0, 0)) + center.x;
	pt1.y = cvRound(mX.at<double>(1, 0)) + center.y;
	pt1.y = FLIP_Y(pt1.y);
	circle(dstImg, pt1, 3, cv::Scalar(255, 0, 255), 3);

	// draw mY
	pt2.x = cvRound(mX.at<double>(0, 0)) + center.x;
	pt2.y = cvRound(mX.at<double>(1, 0)) + center.y;
	pt2.y = FLIP_Y(pt2.y);
	circle(dstImg, pt2, 3, cv::Scalar(0, 0, 0), 3);

	// draw X, Y axes
	pt1 = cv::Point(0, center.y);
	pt2 = cv::Point(dstImg.cols - 1, center.y);
	cv::line(dstImg, pt1, pt2, cv::Scalar(0, 0, 0), 2);

	pt1 = cv::Point(center.x, 0);
	pt2 = cv::Point(center.x, dstImg.rows - 1);
	cv::line(dstImg, pt1, pt2, cv::Scalar(0, 0, 0), 2);

	// draw eigen vectors for X
	double scale = cv::sqrt(eValsX.at<double>(0, 0));
	double x1, y1, x2, y2;
	//draw eVectsX(0)
	x1 = scale * eValsX.at<double>(0, 0);
	y1 = scale * eValsX.at<double>(0, 1);
	x2 = -x1; // symmetric point
	y2 = -y1;

	x1 += mX.at<double>(0, 0) + center.x;
	y1 += mX.at<double>(1, 0) + center.y;
	x2 += mX.at<double>(0, 0) + center.x;
	y2 += mX.at<double>(1, 0) + center.y;

	pt1 = cv::Point(cvRound(x1), FLIP_Y(cvRound(y1)));
	pt2 = cv::Point(cvRound(x2), FLIP_Y(cvRound(y2)));
	cv::line(dstImg, pt1, pt2, cv::Scalar(0, 0, 255), 2);
	//draw eVectsX(1)
	scale = cv::sqrt(eValsX.at<double>(1, 0));
	x1 = scale * eValsX.at<double>(1, 0);
	y1 = scale * eValsX.at<double>(1, 1);
	x2 = -x1; // symmetric point
	y2 = -y1;

	x1 += mX.at<double>(0, 0) + center.x;
	y1 += mX.at<double>(1, 0) + center.y;
	x2 += mX.at<double>(0, 0) + center.x;
	y2 += mX.at<double>(1, 0) + center.y;

	pt1 = cv::Point(cvRound(x1), FLIP_Y(cvRound(y1)));
	pt2 = cv::Point(cvRound(x2), FLIP_Y(cvRound(y2)));
	cv::line(dstImg, pt1, pt2, cv::Scalar(0, 0, 255), 2);

	cv::imshow("dstImage", dstImg);
	cv::waitKey(0);

	return 0;
}
*/