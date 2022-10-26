//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//
//// Mouse event
//Mat img;
//Point pt01d;
//void on_mouse(int event, int x, int y, int flags, void*);
//
//// Trackbar
//void on_level_change(int pos, void* userdata);
//
//int main()
//{
//	//VideoCapture camera;
//	//camera.open(0);
//
//	//if (!camera.isOpened())
//	//{
//	//	cout << "Web cam open FAIL" << endl;
//	//}
//
//	//cout << "Frame width = " << cvRound(camera.get(CAP_PROP_FRAME_WIDTH)) << endl;
//	//cout << "Frame height = " << cvRound(camera.get(CAP_PROP_FRAME_HEIGHT)) << endl;
//
//	//Mat frame, inversed;
//	//while (true)
//	//{
//	//	camera >> frame;
//	//	if (frame.empty()) break;
//
//	//	inversed = ~frame;
//
//	//	imshow("Frame", frame);
//	//	imshow("Inversed", inversed);
//
//	//	if (cv::waitKey(1) == 27) break;
//	//}
//
//	//// Draw
//	//Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));
//
//	//line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
//	//line(img, Point(50, 100), Point(200, 100), Scalar(255, 0, 255), 3);
//	//line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 0), 10);
//
//	//line(img, Point(250, 50), Point(350, 100), Scalar(0, 0, 255), 1, LINE_4);
//	//line(img, Point(250, 70), Point(350, 120), Scalar(255, 0, 255), 1, LINE_8);
//	//line(img, Point(250, 90), Point(350, 140), Scalar(255, 0, 0), 1, LINE_AA);
//
//	//arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0, 0, 255), 1);
//	//arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(255, 0, 255), 1);
//	//arrowedLine(img, Point(50, 300), Point(350, 300), Scalar(255, 0, 0), 1, LINE_8, 0, 0.05);
//
//	//drawMarker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);
//	//drawMarker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
//	//drawMarker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);
//	//drawMarker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);
//	//drawMarker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);
//	//drawMarker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
//	//drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);
//
//	//imshow("img", img);
//	//waitKey(0);
//
//
//
//	//// Print text
//	//Mat img(500, 800, CV_8UC3, Scalar(255, 255, 255));
//
//	//putText(img, "FONT_HERSHEY_SIMPLEX", Point(20, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));
//	//putText(img, "FONT_HERSHEY_PLAIN", Point(20, 100), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
//	//putText(img, "FONT_HERSHEY_DUPLEX", Point(20, 150), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 255));
//	//putText(img, "FONT_HERSHEY_COMPLEX", Point(20, 200), FONT_HERSHEY_COMPLEX, 1, Scalar(255, 0, 0));
//	//putText(img, "FONT_HERSHEY_TRIPLEX", Point(20, 250), FONT_HERSHEY_TRIPLEX, 1, Scalar(255, 0, 0));
//	//putText(img, "FONT_HERSHEY_COMPLEX_SMALL", Point(20, 300), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(255, 0, 0));
//	//putText(img, "FONT_HERSHEY_SCRIPT_SIMPLEX", Point(20, 350), FONT_HERSHEY_SCRIPT_SIMPLEX, 1, Scalar(255, 0, 255));
//	//putText(img, "FONT_HERSHEY_SCRIPT_COMPLEX", Point(20, 400), FONT_HERSHEY_SCRIPT_COMPLEX, 1, Scalar(255, 0, 255));
//	//putText(img, "FONT_HERSHEY_COMPLEX | FONT_ITALIC", Point(20, 450), FONT_HERSHEY_COMPLEX | FONT_ITALIC, 1, Scalar(255, 0, 0));
//
//	//imshow("img", img);
//	//waitKey(0);
//
//
//
//	//// Print text 2
//	//Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));
//
//	//const String text = "Hello, OpenCV";
//	//int fontFace = FONT_HERSHEY_TRIPLEX;
//	//double fontScale = 2.0;
//	//int thickness = 1;
//
//	//Size sizeText = getTextSize(text, fontFace, fontScale, thickness, 0);
//	//Size sizeImg = img.size();
//
//	//Point org((sizeImg.width - sizeText.width) / 2, (sizeImg.height + sizeText.height) / 2);
//	//putText(img, text, org, fontFace, fontScale, Scalar(255, 0, 0), thickness);
//	//rectangle(img, org, org + Point(sizeText.width, -sizeText.height), Scalar(255, 0, 0), 1);
//
//	//imshow("img", img);
//	//waitKey(0);
//
//
//
//	//// Mouse event
//	//img = imread("lena.jpg");
//	//if (img.empty())
//	//{
//	//	cerr << "Image load failed" << endl;
//	//	return -1;
//	//}
//
//	//namedWindow("img");
//	//setMouseCallback("img", on_mouse);
//
//	//imshow("img", img);
//	//waitKey(0);
//
//
//
//	//// Trackbar
//	//Mat img = Mat::zeros(400, 400, CV_8UC1);
//
//	//namedWindow("image");
//	//createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);
//
//	//imshow("image", img);
//	//waitKey(0);
//
//
//
//	//// copyTo
//	//Mat src = imread("airplane.bmp");
//	//Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
//	//Mat dst = imread("field.bmp");
//
//	//if (src.empty() || mask.empty() || dst.empty())
//	//{
//	//	cerr << "Image load failed!" << endl;
//	//	return -1;
//	//}
//
//	//src.copyTo(dst, mask);
//
//	//imshow("dst", dst);
//	//waitKey(0);
//
//	return 0;
//}
//
//void on_mouse(int event, int x, int y, int flags, void*)
//{
//	switch(event)
//	{
//		case EVENT_LBUTTONDOWN:
//			pt01d = Point(x, y);
//			cout << "EVENT_LBUTTONDOWN: " << x << ", " << y << endl;
//			break;
//
//		case EVENT_LBUTTONUP:
//			cout << "EVENT_LBUTTONUP: " << x << ", " << y << endl;
//			break;
//
//		case EVENT_MOUSEMOVE:
//			if (flags & EVENT_FLAG_LBUTTON)
//			{
//				line(img, pt01d, Point(x, y), Scalar(0, 255, 255), 2);
//				imshow("img", img);
//				pt01d = Point(x, y);
//			}
//			break;
//		default:
//			break;
//	}
//}
//
//void on_level_change(int pos, void* userdata)
//{
//	Mat img = *(Mat*)userdata;
//
//	img.setTo(pos * 16);
//	imshow("image", img);
//}