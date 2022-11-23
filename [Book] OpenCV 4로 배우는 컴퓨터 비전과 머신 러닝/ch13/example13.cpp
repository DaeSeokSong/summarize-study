#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void detect_faceNeye();
void decode_qrcode();

int main()
{
	//// Ex1
	//detect_faceNeye();

	// Ex2
	decode_qrcode();

	return 0;
}

void detect_faceNeye()
{
	Mat src = imread("faces1.jpg");

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return;
	}
	
	CascadeClassifier cat_classifier("cascade_haar-like\\haarcascade_frontalcatface.xml");
	CascadeClassifier face_classifier("cascade_haar-like\\haarcascade_frontalface_default.xml");
	CascadeClassifier eye_classifier("cascade_haar-like\\haarcascade_eye.xml");
	if (cat_classifier.empty() || face_classifier.empty() || eye_classifier.empty())
	{
		cerr << "XML load failed" << endl;
		return;
	}

	vector<Rect> faces;
	face_classifier.detectMultiScale(src, faces);
	//cat_classifier.detectMultiScale(src, faces);

	for (Rect face : faces)
	{
		rectangle(src, face, Scalar(255, 0, 255), 2);

		Mat faceROI = src(face);
		vector<Rect> eyes;
		eye_classifier.detectMultiScale(faceROI, eyes);

		for (Rect eye : eyes)
		{
			Point center(eye.x + eye.width / 2, eye.y + eye.height / 2);
			circle(faceROI, center, eye.width / 2, Scalar(255, 0, 0), 2, LINE_AA);
		}
	}

	imshow("src", src);

	waitKey(0);
}

void decode_qrcode()
{
	Mat src = imread("distored_qrcode.jpg");

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return;
	}

	Mat straight_qr;
	QRCodeDetector detector;
	vector<Point> points;
	String info = detector.detectAndDecode(src, points, straight_qr);

	// 부동 소수점 문제로 straight CV_32FC1 >> CV_8UC1
	straight_qr.convertTo(straight_qr, CV_8UC1);
	resize(straight_qr, straight_qr, src.size());

	if (!info.empty())
	{
		polylines(src, points, true, Scalar(0, 0, 255), 2);
		putText(src, info, Point(10, 30), FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 0, 255));
	}
	cout << "src.shape = " << src.size() << endl;
	cout << "src.type = " << src.type() << endl;
	cout << "straight_qr.shape = " << straight_qr.size() << endl;
	cout << "straight_qr.type = " << straight_qr.type() << endl;

	imshow("src", src);
	imshow("straight_qr", straight_qr);
	waitKey(0);
}